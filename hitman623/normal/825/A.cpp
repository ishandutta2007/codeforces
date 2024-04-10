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
    string s;
    long i=0,n,c=0;
    vl v;
    cin>>n>>s;
    s.pb('0');
    for(;i<s.length();++i)
    if(s[i]=='1') c++;
    else {v.pb(c);c=0;}
    for(i=0;i<v.size();++i)
    cout<<v[i];
    return 0;
}