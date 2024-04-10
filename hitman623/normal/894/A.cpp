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
#define h 1000000007
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    io
    string s;
    long n,i,ans=0,j,k;
    cin>>s;
    n=s.length();
    for(i=0;i<n;++i)
    for(j=i+1;j<n;++j)
    for(k=j+1;k<n;++k)
    if(s[i]=='Q' && s[j]=='A' && s[k]=='Q') ans++;
    cout<<ans;
    return 0;
}