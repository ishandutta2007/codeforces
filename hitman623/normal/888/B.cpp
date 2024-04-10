#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define vl vector < long >
#define pll pair < long , long >
#define vll vector < pll >
#define x first
#define y second
#define ml map < long , long >
#define mll map < pll , long >
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    io
    long n,i,l=0,u=0,ans=0,d=0,r=0;
    string s;
    cin>>n>>s;
    for(i=0;i<n;++i)
    if(s[i]=='L') l++;
    else if(s[i]=='R') r++;
    else if(s[i]=='U') u++;
    else d++;
    cout<<2*min(l,r)+2*min(u,d);
    return 0;
}