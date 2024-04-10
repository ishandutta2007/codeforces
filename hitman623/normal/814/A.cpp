#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    io
    long n,k,a[103],b[103],i;
    map < long , long > mp;
    cin>>n>>k;
    for(i=0;i<n;++i)
    cin>>a[i];
    for(i=0;i<k;++i)
    {
        cin>>b[i];
        mp[b[i]]++;
    }
    if(k>1) cout<<"Yes";
    else
    {
        for(i=0;i<n;++i)
        if(a[i]==0) a[i]=b[0];
        for(i=0;i<n-1;++i)
        if(a[i]>=a[i+1]) {cout<<"Yes";exit(0);}
        cout<<"No";
    }
    return 0;
}