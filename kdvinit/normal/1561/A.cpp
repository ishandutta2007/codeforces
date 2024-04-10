/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

bool sorted(int a[], int n)
{
    for(int i=1; i<=n; i++) if(a[i]!=i) return false;
    return true;
}

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int cnt=0;
    while(1)
    {
        if(sorted(a, n)) break;
        cnt++;
        int strt = 2 - cnt%2;
        for(int i=strt; i+1<=n; i+=2)
        {
            if(a[i]>a[i+1]) swap(a[i+1], a[i]);
        }
    }
    cout<<cnt<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}