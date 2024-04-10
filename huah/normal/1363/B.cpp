#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int a[N],b[N];
char s[N];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s+1);
        int n=strlen(s+1);
        b[n+1]=0;
        for(int i=1;i<=n;i++) a[i]=a[i-1]+(s[i]=='0');
        for(int i=n;i>=1;i--) b[i]=b[i+1]+(s[i]=='1');
        int ans=min(b[1],a[n]);
        for(int i=1;i<n;i++) ans=min(ans,a[i]+b[i+1]);
        b[n+1]=0;
        for(int i=1;i<=n;i++) a[i]=a[i-1]+(s[i]=='1');
        for(int i=n;i>=1;i--) b[i]=b[i+1]+(s[i]=='0');
        ans=min(ans,b[1]);ans=min(ans,a[n]);
        for(int i=1;i<n;i++) ans=min(ans,a[i]+b[i+1]);
        printf("%d\n",ans);
    }
}