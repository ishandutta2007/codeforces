/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

set<int> st;

void put(int a, int b, int x, int y)
{
    int org = abs(a-x);

    int dif;
    int cnt = min(a, b);

    for(int i=0; i<=cnt; i++) st.insert(org+(2*i));
}

void solve()
{
    int a, b;
    cin>>a>>b;

    int n = a+b;
    int x = n/2;
    int y = (n+1)/2;

    st.clear();
    put(a, b, x, y);
    if(x!=y) put(a, b, y, x);

    cout<<st.size()<<endl;
    for(int x: st) cout<<x<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}