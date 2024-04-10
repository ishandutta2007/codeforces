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
string s;
long check(long n)
{
    long n1=0,n2=0;
    n1=n/100000;
    n%=100000;
    n1+=n/10000;
    n%=10000;
    n1+=n/1000;
    n%=1000;
    n2=n/100;
    n%=100;
    n2+=n/10;
    n%=10;
    n2+=n;
    if(n1==n2) return 1;
    else return 0;
}
long sol(long n)
{
    long c=0;
    if(s[0]-'0'!=n/100000) c++;
    n%=100000;
    if(s[1]-'0'!=n/10000) c++;
    n%=10000;
    if(s[2]-'0'!=n/1000) c++;
    n%=1000;
    if(s[3]-'0'!=n/100) c++;
    n%=100;
    if(s[4]-'0'!=n/10) c++;
    n%=10;
    if(s[5]-'0'!=n) c++;
    return c;
}
int main()
{
    io
    long n1=0,n2=0,ans=1e9,i;
    cin>>s;
    n1=s[0]-'0'+s[1]-'0'+s[2]-'0';
    n2=s[3]-'0'+s[4]-'0'+s[5]-'0';
    for(i=0;i<1e6;++i)
    if(check(i))
    ans=min(ans,sol(i));
    cout<<ans;
    return 0;
}