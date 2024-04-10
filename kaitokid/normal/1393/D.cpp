#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
string s[3009];
ll n,m,ans;
int a[2003][2003][2];
int d[2003][2003];
vector<ll>v;
ll w[2009][2];
void go()
{
    int u=v.size();
    w[0][0]=1;
    w[u-1][1]=1;
    for(int i=1;i<u;i++)w[i][0]=min(w[i-1][0]+1,v[i]);
    for(int i=u-2;i>=0;i--)w[i][1]=min(w[i+1][1]+1,v[i]);
    for(int i=0;i<u;i++)ans+=min(w[i][0],w[i][1]);

}
int main()
{
ios::sync_with_stdio(0);

cin>>n>>m;
for(int i=0;i<n;i++)cin>>s[i];
for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
{
    a[i][j][0]=1;
    if((i>0)&&s[i][j]==s[i-1][j])a[i][j][0]+=a[i-1][j][0];
    }
for(int i=n-1;i>=0;i--)
    for(int j=m-1;j>=0;j--)
{
    a[i][j][1]=1;
if((i<n-1)&&s[i][j]==s[i+1][j])a[i][j][1]+=a[i+1][j][1];
d[i][j]=min(a[i][j][0],a[i][j][1]);
}

for(int i=0;i<n;i++)
{
    v.clear();
    v.push_back(d[i][0]);
    for(int j=1;j<m;j++)
    {
        if(s[i][j]!=s[i][j-1]){go();v.clear();v.push_back(d[i][j]);}
        else v.push_back(d[i][j]);
    }
    go();
}
cout<<ans;
    return 0;
}