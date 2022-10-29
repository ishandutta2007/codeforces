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
    long n,k,i,a[10004],c=0;
    cin>>n>>k;
    for(i=0;i<n;++i)
    cin>>a[i];
    for(i=0;i<n;++i)
    {
        c+=a[i];
        k-=min(8LL,c);
        c-=min(8LL,c);
        if(k<=0) break;
    }
    if(i!=n)
    cout<<i+1;
    else cout<<-1;
    return 0;
}