#include <cstdio>
#include <string>

int main()
{
    int n,x,y,ans=0;
    char *c;
    scanf("%d",&n);
    c = new char[n];
    for(int i=0;i<n;i++){
        c[i]='\n';
        while(c[i]=='\n' || c[i]==' '){
            scanf("%c",&c[i]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            x=0;
            y=0;
            for(int k=i;k<=j;k++){
                switch((int)c[k]){
                    case (int)'U': ++y; break;
                    case (int)'D': --y; break;
                    case (int)'R': ++x; break;
                    case (int)'L': --x; break;
                }
            }
            if(x==0 && y==0)
                ++ans;
        }
    }
    printf("%d",ans);
    delete [] c;
    return 0;
}