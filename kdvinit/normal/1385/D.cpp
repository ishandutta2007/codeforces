/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

string s;
int n;

int Value(int strt, int nd, char c)
{
    if(strt==nd)
    {
        if(s[strt]==c) return 0;
        else return 1;
    }

    int l1 = 0;
    int l2 = 0;

    int mid = (strt+nd)/2;

    for(int i=strt; i<=mid; i++) l1+=(s[i]!=c);
    for(int i=mid+1; i<=nd; i++) l2+=(s[i]!=c);

    return min(l1+Value(mid+1, nd, c+1), l2+Value(strt, mid, c+1));
}

void solve()
{
    cin>>n;

    s.clear();
    cin>>s;

    int ans = Value(0, n-1, 'a');
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}