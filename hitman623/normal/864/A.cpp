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
    ml :: iterator it;
    ml a;
    long n,i,x;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>x;
        a[x]++;
    }
    if(a.size()>2 || a[x]!=n/2) {cout<<"NO";return 0;}
    else cout<<"YES\n";
    for(it=a.begin();it!=a.end();it++)
    cout<<it->x<<" ";
    return 0;
}