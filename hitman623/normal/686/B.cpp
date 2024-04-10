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
    long n,i,a[101],j;
    cin>>n;
    for(i=0;i<n;++i)
    cin>>a[i];
    for(i=0;i<n;++i)
    for(j=0;j<n-1;++j)
    if(a[j]>a[j+1]) {cout<<j+1<<" "<<j+2<<"\n";swap(a[j],a[j+1]);}
    return 0;
}