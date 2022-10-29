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
    long n,k,m,i,a[100005],f=-1;
    ml mp;
    cin>>n>>k>>m;
    for(i=0;i<n;++i)
    {
        cin>>a[i];
        mp[a[i]%m]++;
    }
    for(auto i:mp)
    {
        if(i.y>=k) {f=i.x;break;}
    }
    if(f==-1) cout<<"No";
    else
    {
        cout<<"Yes\n";
        for(i=0;i<n;++i)
        if(a[i]%m==f && k)
        {cout<<a[i]<<" ";k--;}
    }
    return 0;
}