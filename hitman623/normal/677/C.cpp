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
    string s;
    cin>>s;
    map < char , long > w;
    long i,v[1000]={0},ans=1,h=1e9+7,j,c,k;
    for(i=0;i<10;++i)
    w[i+'0']=i;
    for(i=0;i<26;++i)
    w['A'+i]=10+i;
    for(i=0;i<26;++i)
    w['a'+i]=36+i;
    w['-']=62;
    w['_']=63;
    for(j=0;j<64;++j)
    for(k=0;k<64;++k)
    v[(j&k)]++;
    for(i=0;i<s.length();++i)
    ans=(ans*v[w[s[i]]])%h;
    cout<<ans;
    return 0;
}