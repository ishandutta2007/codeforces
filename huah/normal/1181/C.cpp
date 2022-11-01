#include<map>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=1005;
int n,m;
char s[N][N];
int a[N][N];
bool cmp(char a,char b,char c)
{
    return a!=b&&a!=c;
}
int main()
{
    memset(s,'#',sizeof(s));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    long long ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if(s[i][j]==s[i-1][j])
        a[i][j]=a[i-1][j]+1;
        else a[i][j]=1;
    for(int i=n-1;i>=1;i--)
        for(int j=1;j<=m;j++)
        if(s[i][j]==s[i+1][j])
        a[i][j]=a[i+1][j];
    for(int i=1;i<=n;i++)
    {
        int t=0,pre=0;
        char x='#',y='#',z='#';
        for(int j=1;j<=m;j++)
        {
            int p=0;
            char xx,yy,zz;
            xx=s[i][j];yy=s[i-a[i][j]][j];zz=s[i+1][j];
            if(xx!=zz&&cmp(xx,yy,zz)&&a[i-a[i][j]][j]>=a[i][j]&&a[i+1][j]>=a[i][j])
                p=a[i][j];
            if(p==0)
            {
                if(t)
                    ans+=t*(t+1)/2;
                pre=p;t=0;x=y=z='#';
            }
            else if(pre==0)
            {
                pre=p;t=1;x=xx;y=yy;z=zz;
            }
            else if(p==pre&&x==xx&&y==yy&&z==zz) t++;
            else
            {
                if(t)
                    ans+=t*(t+1)/2;
                pre=p;t=1;x=xx;y=yy;z=zz;
            }
            pre=p;
        }
        if(t)
            ans+=t*(t+1)/2;
    }
    printf("%lld\n",ans);
}