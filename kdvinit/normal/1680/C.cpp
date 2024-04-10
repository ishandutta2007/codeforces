/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 2e5 + 100;
int a[N];
int n;

bool check(int k)
{
    int cnt1[n+1]={0};
    for(int i=1; i<=n; i++)
    {
        cnt1[i]=cnt1[i-1];
        if(a[i]==1) cnt1[i]++;
    }

    int c0=0;
    int pos0[n+1];

    for(int i=1; i<=n; i++)
    {
        if(a[i]==0)
        {
            c0++;
            pos0[c0]=i;
        }

        int rm = cnt1[n]-cnt1[i];

        int l=1;
        if(c0>k) l=pos0[c0-k]+1;

        int t1 = rm+cnt1[l-1];
        if(t1<=k) return true;
    }

    return false;
}

void solve()
{
    string s; cin>>s;
    n=s.size();

    for(int i=1; i<=n; i++) a[i]=(s[i-1]-'0');

    int l=-1, r=n;
    while(l+1!=r)
    {
        int mid=(l+r)/2;
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