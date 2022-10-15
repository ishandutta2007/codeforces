/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool solve()
{
    int s, n, k;
    cin>>s>>n>>k;

    if(k>s) return false;
    if(k==s) return true;

    int l = s-n;
    int r = (n/k)*k;

    if(l>=r) return false;
    else return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--)
    {
        if(solve()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}