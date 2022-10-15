/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 5e5;
int n, k, a[N];

bool check(int x)
{
    int sum=0;
    for(int i=1; i<=x; i++) sum+=a[i];
    if(sum>=n) return  false;
    else return true;
}

void solve()
{
    cin>>n>>k;
    for(int i=1; i<=k; i++)
    {
        int x; cin>>x;
        a[i] = n-x;
    }
    sort(a+1, a+k+1);

    int l=0, r=k+1;

    while(l+1!=r)
    {
        int mid = (l+r)/2;
        if(check(mid)) l=mid;
        else r=mid;
    }

    cout<<l<<endl;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}