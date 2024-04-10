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
    cin>>s;
    vl v;
    char ch='a';
    long n=s.length(),i,b[5005],c[5005],ans=0,j;
    b[0]=(s[0]=='a');
    c[0]=!b[0];
    for(i=1;i<n;++i)
    {
        b[i]=b[i-1]+(s[i]=='a');
        c[i]=c[i-1]+(s[i]=='b');
    }
    for(i=0;i<n;++i)
    {
        ans=max(ans,c[i]+b[n-1]-b[i]);
        for(j=i;j<n;++j)
        ans=max(ans,b[i]+c[j]-c[i]+b[n-1]-b[j]);
    }
    cout<<ans;
    return 0;
}