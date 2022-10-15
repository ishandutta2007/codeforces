/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 1;
int a[N], b[N], n;
int tot=0;

bool check_k(int k)
{
    if(k>tot) return false;
    int cur = 0;
    int dis = tot-k;
    for(int i=1; i<=n; i++)
    {
        if(cur>=k) break;
        if(b[i]>dis) return false;
        cur+=a[i];
        dis+=a[i];
    }
    return true;
}

void solve()
{
    cin>>n;

    array<int, 2> ab[n+1];
    for(int i=1; i<=n; i++)
    {
        cin>>ab[i][1]>>ab[i][0];
        tot+=ab[i][1];
    }
    sort(ab+1, ab+n+1);

    for(int i=1; i<=n; i++) a[i]=ab[i][1], b[i]=ab[i][0];

    int l=0, r=1e15;
    while(l+1!=r)
    {
        int mid = (l+r)/2;
        if(check_k(mid)) l=mid;
        else r=mid;
    }

    int ans = l + 2*(tot-l);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}