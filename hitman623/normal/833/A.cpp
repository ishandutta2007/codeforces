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
    long n,a,b,i,g,mm,j;
    vl v;
    for(i=1;i<=1000000;++i)
    v.pb(i*i*i);
    cin>>n;
    for(j=0;j<n;++j)
    {
        cin>>a>>b;
        if(binary_search(v.begin(),v.end(),a*b))
        {
            g=upper_bound(v.begin(),v.end(),a*b)-v.begin();
            if(a%g==0 && b%g==0)
            cout<<"Yes\n";
            else cout<<"No\n";
        }
        else cout<<"No\n";
    }
    return 0;
}