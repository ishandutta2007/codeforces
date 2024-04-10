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
    long n,k,i,d,j;
    cin>>n>>k;
    d=(n-1)/k;
    if((n-1)%k==0) cout<<2*d<<endl;
    else if((n-1)%k==1)cout<<2*d+1<<endl;
    else cout<<2*d+2<<endl;
    for(i=0;i<k;++i)
    {
        cout<<1<<" "<<i*d+2<<endl;
        for(j=0;j<d-1;++j)
        cout<<i*d+2+j<<" "<<i*d+3+j<<endl;
    }
    for(i=0;i<((n-1)%k);++i)
    cout<<(i+1)*d+1<<" "<<d*k+i+2<<endl;
    return 0;
}