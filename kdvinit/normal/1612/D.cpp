/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool check(int a, int b, int x)
{
    if(x==a || x==b) return true;
    if(b>a) swap(a, b);

    //a>b
    if(b==0) return false;
    int r = a%b;

    if(x>=b && x<=a && x%b==r) return true;
    return check(b, r, x);
}

void solve()
{
    int a, b, x;
    cin>>a>>b>>x;

    if(check(a, b, x)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}