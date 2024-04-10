/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 1e5;
int n, h, a[N];

bool check(int k)
{
    int damage=0, lst=a[1];
    for(int i=2; i<=n; i++)
    {
        if(lst+k>a[i]) damage+=a[i]-lst;
        else damage+=k;
        lst=a[i];
    }
    damage+=k;
    return (damage>=h);
}

void solve()
{
    cin>>n>>h;
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);

    int l=0, r=h;
    while(l+1!=r)
    {
        int mid = (l+r)/2;
        if(check(mid)) r=mid;
        else l=mid;
    }

    cout<<r<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}