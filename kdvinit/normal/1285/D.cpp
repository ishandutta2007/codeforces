/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int val(vector<int> a,int k)
{
    if(k==0) return 0;
    int x=pow(2,k-1);
    vector<int> b,c;

    for(int i=0;i<a.size();i++)
    {
        int y=a[i]/x;
        if(y%2==0) b.push_back(a[i]);
        else c.push_back(a[i]);
    }

    if(b.size()==0) return val(c,k-1);
    if(c.size()==0) return val(b,k-1);

    return ( x + min(val(b,k-1),val(c,k-1)) );
}

void solve()
{
    int n;
    cin>>n;

    vector<int> a;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        a.push_back(x);
    }

    cout<<val(a,30)<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}