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
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    io
    long n,m,x1=1e9,x2=-1,y1=1e9,y2=-1,cnt=0,d,i,j;
    string s[102];
    cin>>n>>m;
    for(i=0;i<n;++i)
    cin>>s[i];
    for(i=0;i<n;++i)
    for(j=0;j<m;++j)
    if(s[i][j]=='B')
    {
        x1=min(x1,i);
        x2=max(x2,i);
        y1=min(y1,j);
        y2=max(y2,j);
    }
    if(x2==-1) {cout<<1;exit(0);}
    for(i=x1;i<=x2;++i)
    for(j=y1;j<=y2;++j)
    if(s[i][j]!='B') cnt++;
    d=max(x2-x1+1,y2-y1+1);
    if(n<d || m<d) {cout<<-1;exit(0);}
    cnt+=d*d-(x2-x1+1)*(y2-y1+1);
    cout<<cnt;
    return 0;
}