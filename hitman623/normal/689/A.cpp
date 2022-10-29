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
    long n,i,ss[4][10],f=0;
    string s;
    cin>>n>>s;
    f=1;
    for(i=0;i<n;++i)
    if(s[i]<'4' && s[i]!='0') {f=0;break;}
    if(f)
    {cout<<"NO";exit(0);}
    f=1;
    for(i=0;i<n;++i)
    if(s[i]=='0' || s[i]=='7' || s[i]=='9') {f=0;break;}
    if(f)
    {cout<<"NO";exit(0);}
    f=1;
    for(i=0;i<n;++i)
    if(s[i]=='0' || s[i]=='7' || s[i]=='1' || s[i]=='4' ) {f=0;break;}
    if(f)
    {cout<<"NO";exit(0);}
    f=1;
    for(i=0;i<n;++i)
    if(s[i]=='0' || s[i]=='3'  || s[i]=='6' || s[i]=='9') {f=0;break;}
    if(f)
    {cout<<"NO";exit(0);}
    else cout<<"YES";
    return 0;
}