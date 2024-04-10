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
    long n,i,c=0;
    string s;
    cin>>n>>s;
    char cur=s[0];
    for(i=0;i<n;++i)
    if(s[i]!=cur) c++,cur=s[i];
    if(c%2 && s[0]=='S') cout<<"YES";
    else cout<<"NO";
    return 0;
}