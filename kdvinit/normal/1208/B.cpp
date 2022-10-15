/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2001;
int a[N];
int n;

bool check_k(int k)
{
    map<int, int> mp;

    int f2=0;
    for(int i=k+1; i<=n; i++)
    {
        if(mp[a[i]]==1) f2++;
        mp[a[i]]++;
    }

    if(f2==0) return true;

    for(int i=1; i<=(n-k); i++)
    {
        if(mp[a[i]]==1) f2++;
        mp[a[i]]++;

        int j = i+k;
        if(mp[a[j]]==2) f2--;
        mp[a[j]]--;

        if(f2==0) return true;
    }

    return false;
}

void solve()
{
    cin>>n;

    for(int i=1; i<=n; i++) cin>>a[i];

    int l=-1, r=n;
    while(l+1!=r)
    {
        int mid = (l+r)/2;
        if(check_k(mid)) r=mid;
        else l=mid;
    }
    cout<<r<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}