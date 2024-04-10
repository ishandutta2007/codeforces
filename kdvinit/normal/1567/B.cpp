/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 3e5 + 5;
int a[N];

void solve()
{
    int b, c;
    cin>>b>>c;
    int y = c^a[b-1];
    if(y==0) cout<<b<<endl;
    else if(y!=b) cout<<b+1<<endl;
    else cout<<b+2<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    a[0]=0; for(int i=1; i<N; i++) a[i] = a[i-1]^i;
    int t; cin>>t; while(t--) solve();
    return 0;
}