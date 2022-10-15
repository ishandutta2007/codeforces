/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

#define int long long
using namespace std;

set<int> val;

const int mx=1e5;
vector<int> a;
int sum[mx+1];

void doit(int strt,int nd)
{
    if(strt==0) val.insert(sum[nd]);
    else val.insert(sum[nd]-sum[strt-1]);

    if(a[strt]==a[nd]) return;

    int mid=(a[strt]+a[nd])/2;
    int i=upper_bound(a.begin()+strt,a.begin()+nd+1,mid)-a.begin();
    doit(strt,i-1);
    doit(i,nd);
}

void solve()
{
    int n,q;
    cin>>n>>q;

    val.clear();
    a.clear();

    int x;
    for(int i=1;i<=n;i++) { cin>>x; a.push_back(x); }
    sort(a.begin(),a.end());

    int cnt=0;
    for(int i=0;i<n;i++)
    {
        cnt+=a[i];
        sum[i]=cnt;
    }

    doit(0,n-1);

    while(q--)
    {
        int s; cin>>s;
        if(val.find(s)!=val.end()) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}