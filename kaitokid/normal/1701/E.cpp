#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int d[5009][5009];
int f[5009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {

    int n,m;
    string s,t;
    cin>>n>>m>>s>>t;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)d[i][j]=0;
    for(int i=n-1;i>=0;i--)
        for(int j=m-1;j>=0;j--)
            if(s[i]==t[j])d[i][j]=1+d[i+1][j+1];
    int u=0,h=-1;
    for(int i=0;i<n;i++)
    {
        if(s[i]==t[u])u++;
        if(u==m){h=i;break;}
    }

    if(h==-1){cout<<-1<<endl;continue;}
    if(h==m-1){cout<<n-m<<endl;continue;}
    u=m-1;
    for(int i=n-1;i>=0;i--)
    {
        if(u>=0 && s[i]==t[u])u--;
        f[i]=u;

    }
    int ans=n;
    u=0;
    for(int i=0;i<n-1;i++)
    {
        if(u<m && s[i]==t[u])u++;
        if(u-1==i)ans=min(ans,n-i-1);
        for(int j=0;j<=u;j++)
            if(f[i+1]<j)
                ans=min(ans,2*(i+1)-j+n-i-d[i+1][j]);
    }
    cout<<ans<<endl;
    }

    return 0;
}