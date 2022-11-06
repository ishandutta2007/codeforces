#include<bits/stdc++.h>
using namespace std;
int n,p,a[2005][4],f,v[2005],typ[2005];
char str[2005];
int main(){
    scanf("%d%d%s",&n,&p,str+1);
    for(int i=1;i<=n;i++){
        int j=i%p;//printf("%d %d\n",i,j);
        switch(str[i]){
            case '0':a[j][0]=1;break;
            case '1':a[j][1]=1;break;
            case '.':a[j][2]=1;break;
            
        }
        ++a[j][3];
    }
    for(int i=0;i<p;i++){//printf("%d %d %d\n",a[i][0],a[i][1],a[i][2]);
        if(a[i][3]>1){
            
            if(a[i][2]){
                f=1;//printf("%d\n",i);
                if(a[i][0])typ[i]=1;
                else if(a[i][1])typ[i]=0;
                else typ[i]=2;
            }
            else if(a[i][1]&&a[i][0])f=1;
            
        }//if(f);
    }
    if(f)for(int i=1;i<=n;i++){
        if(str[i]=='.'){
            if(typ[i%p]<2)printf("%d",typ[i%p]);
            else printf("%d",v[i%p]),v[i%p]=1;
        }else printf("%c",str[i]);
    }
    else printf("No");
    return 0;
}