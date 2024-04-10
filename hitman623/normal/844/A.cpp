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
    long i,v[27]={0},k,c=0;
    string s;
    cin>>s>>k;
    for(i=0;i<s.length();++i)
    v[s[i]-'a']=1;
    for(i=0;i<26;++i)
    c+=v[i];
    if(s.length()<k) cout<<"impossible";
    else cout<<max(0LL,k-c);
    return 0;
}