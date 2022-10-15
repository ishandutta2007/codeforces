/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    set<int> pos, neg;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    for(int i=2; i<=n; i++)
    {
        int diff = a[i]-a[i-1];
        if(diff>0) pos.insert(diff);
        else neg.insert(diff*(-1));
    }

    if( (pos.size()>1) || (neg.size()>1) ) { cout<<-1<<endl; return; }
    if( (pos.size()==0) || (neg.size()==0) ) { cout<<0<<endl; return; }

    int c = *pos.begin();
    int m = c + *neg.begin();

    a[0]=a[1]-c;
    for(int i=1; i<=n; i++)
    {
        int x = (a[i-1]+c)%m;
        if(a[i]!=x) { cout<<-1<<endl; return; }
    }

    cout<<m<<" "<<c<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}