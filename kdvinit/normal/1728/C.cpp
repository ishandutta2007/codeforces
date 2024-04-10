/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int cnt_digits(int n)
{
    int val=0;
    while(n!=0) { n/=10; val++; }
    return val;
}

void solve()
{
    int n;
    cin>>n;

    multiset<int> msa, msb;
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        msa.insert(x);
    }

    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        if(msa.count(x)==0) msb.insert(x);
        else msa.erase(msa.find(x));
    }

    int ans = 0;
    int dpa[10]={0};

    for(int x: msa)
    {
        if(x>9) { x = cnt_digits(x); ans++; }
        dpa[x]++;
    }

    for(int x: msb)
    {
        if(x>9) { x = cnt_digits(x); ans++; }
        if(dpa[x]>0) dpa[x]--;
        else
        {
            ans+=2;
            if(x==1) ans--;
        }
    }
    ans -= dpa[1];

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}