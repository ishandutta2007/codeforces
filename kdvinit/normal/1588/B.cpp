/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int ask(int l, int r)
{
    cout<<"? "<<l<<" "<<r<<endl;
    int ans;
    cin>>ans;
    return ans;
}

void solve()
{
    int n;
    cin>>n;

    int l=1, r=n;
    int tot = ask(1, n);

    while(l+1!=r)
    {
        int mid = (l+r)/2;
        int cur = ask(1, mid);
        if(cur==tot) r=mid;
        else l=mid;
    }

    int l2 = ask(1, l+1) - ask(1, l)+1;
    int s2 = (l2*(l2-1))/2;
    int s1 = tot-s2;
    int l1 = (1 + sqrt(1+8*s1))/2;

    int k = r;
    int j = k-l2+1;
    int i = j-l1;

    cout<<"! "<<i<<" "<<j<<" "<<k<<endl;
}

int32_t main()
{
    int t; cin>>t;
    while(t--) solve();
    return 0;
}