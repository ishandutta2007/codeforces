/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int val;
void query(int r)
{
    if(r==0)
    {
        val=0;
        return;
    }

    cout<<"? "<<1<<" "<<r<<endl;
    cin>>val;
    val = r-val;
}

void solve()
{
    int n, t;
    cin>>n>>t;

    int k; cin>>k;

    if(k==1)
    {

    }

    int l=0, r=n;

    while(l+1!=r)
    {
        int m = (r+l)/2;
        query(m);

        if(val>=k) r=m;
        else l=m;
    }

    cout<<"! "<<r<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}