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
    long l,r,x,y,k,i;
    cin>>l>>r>>x>>y>>k;
    for(i=l;i<=r;++i)
    if(i%k==0)
    if(i/k<=y && i/k>=x) break;
    if(i==r+1) cout<<"NO";
    else cout<<"YES";
    return 0;
}