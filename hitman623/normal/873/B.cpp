#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
long n,i,ss=0,v[2000005][2],ans=0,cur=0;
int main()
{
    io
    memset(v,-1,sizeof v);
    string s;
    cin>>n>>s;
    v[n+1][0]=0;
    v[n+1][1]=0;
    for(i=0;i<n;++i)
    {
        if(s[i]=='1')
        cur++;
        else cur--;
        if(v[cur+n+1][0]==-1) v[cur+n+1][0]=i+1;
        v[cur+n+1][1]=i+1;
    }
    for(i=0;i<=2*n+3;++i)
    ans=max(ans,v[i][1]-v[i][0]);
    cout<<ans;
    return 0;
}