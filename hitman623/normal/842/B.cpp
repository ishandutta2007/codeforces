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

int main()
{
    io
    long d,r,n,x,y,rr,i,dis,cnt=0;
    cin>>r>>d>>n;
    for(i=0;i<n;++i)
    {
        cin>>x>>y>>rr;
        dis=x*x+y*y;
        if((r-d+rr)*(r-d+rr)<=dis && (r-rr)*(r-rr)>=dis)
        cnt++;
    }
    cout<<cnt;
    return 0;
}