#include <cstdio>
using namespace std;
int main()
{
    char c;
    int *s,*f;
    bool *b;
    int n;
    int sum_f,sum_m;
    int ans;
    scanf("%d",&n);
    s = new int[n];
    f = new int[n];
    b = new bool[n];
    for(int i=0;i<n;++i){
        scanf("%c",&c);
        if(c=='\n')
            scanf("%c",&c);
        scanf("%d %d",&s[i],&f[i]);
        b[i]=(c=='F');
    }
    ans=0;
    for(int j=0;j<=366;++j){
        sum_m=0;
        sum_f=0;
        for(int i=0;i<n;++i){
            if((s[i]<=j) && (f[i]>=j)){
                if(b[i]){
                    ++sum_f;
                }else{
                    ++sum_m;
                }
            }
        }
        if(sum_f>sum_m)
            sum_f=sum_m;
        if(sum_f>ans)
            ans=sum_f;
    }
    printf("%d",2*ans);
    delete [] s;
    delete [] f;
    delete [] b;
}