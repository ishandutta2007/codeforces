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
#define hell 99991
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    io
    long n,k,i;
    cin>>n>>k;
    if(k==0) cout<<0<<" "<<0;
    else cout<<min(1LL,n-k)<<" "<<min(n-k,2*k);
    return 0;
}