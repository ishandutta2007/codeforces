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
long n,x,k,i,a[100005],l[100005],r[100005],ans,cur;
ml mp;
int main()
{
    io
    cin>>n>>x>>k;
    for(i=0;i<n;++i)
    cin>>a[i];
    sort(a,a+n);
    while(cur<n)
    {
        long d=a[cur],c=0;
        while(cur<n && a[cur]==d)
        mp[(a[cur]-1)/x]++,cur++,c++;
        ans+=mp[d/x-k]*c;
    }
    cout<<ans;
    return 0;
}