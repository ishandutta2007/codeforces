#include <bits/stdc++.h>
using namespace std;
const int SIZE=400;
const int mn=1e5+10;
int a[mn],par[mn],dis[mn];
int b[mn],c[mn],d[mn];
bool ch[mn];
int main()
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",a+i);
    for(i=0;i<m;i+=SIZE){
        memset(ch,0,sizeof(ch));
        for(j=0;j+i<m&&j<SIZE;j++){
            scanf("%d",b+j);
            if(b[j])scanf("%d",c+j);
            else{
                scanf("%d%d",c+j,d+j);
                ch[c[j]]=1;
            }
        }
        for(j=n;j>=1;j--){
            if(ch[j])par[j]=j,dis[j]=0;
            else{
                if(j+a[j]>n)par[j]=j,dis[j]=0;
                else par[j]=par[j+a[j]],dis[j]=dis[j+a[j]]+1;
            }
        }
        for(j=0;j+i<m&&j<SIZE;j++){
            if(b[j]){
                int ans=0,cur=c[j],ln=cur;
                while(cur<=n){
                    ans+=dis[cur];
                    cur=par[cur];
                    ln=cur;
                    ans++;
                    cur+=a[cur];
                }
                printf("%d %d\n",ln,ans);
            }
            else{
                a[c[j]]=d[j];
            }
        }
    }
}