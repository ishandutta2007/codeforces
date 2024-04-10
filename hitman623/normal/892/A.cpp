#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define vl vector < long >
#define pll pair < long , long >
#define vll vector < pll >
#define x first
#define y second
#define ml map < long , long >
#define mll map < pll , long >
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    io
    long n,i,a[100005],b[100005],s=0;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>a[i];
        s+=a[i];
    }
    for(i=0;i<n;++i)
    cin>>b[i];
    sort(b,b+n);
    if(s<=b[n-1]+b[n-2]) cout<<"YES";
    else cout<<"NO";
    return 0;
}