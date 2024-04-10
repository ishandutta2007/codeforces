#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define x first
#define y second
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    io
    long n,a[100],i;
    cin>>n;
    for(i=0;i<n;++i)
    cin>>a[i];
    if(a[0]>15) {cout<<15;exit(0);}
    for(i=0;i<n-1;++i)
    if(a[i+1]-a[i]>15) {cout<<a[i]+15;exit(0);}
    if(90-a[i]>15) {cout<<a[i]+15;exit(0);}
    cout<<90;
    return 0;
}