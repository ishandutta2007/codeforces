/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
//#define endl "\n"

const int INF = 1e10;

const int N = 2e5;
int a[N];
int n;

int place_even(int strt)
{
    vector<int> pos;
    while(strt<=n)
    {
        pos.push_back(strt);
        strt+=2;
    }

    int m = pos.size();

    vector<int> even;
    for(int i=1; i<=n; i++)
    {
        if(a[i]==0) even.push_back(i);
    }

    int m2 = even.size();

    if(m!=m2) return INF;

    int ans = 0;
    for(int i=0; i<m; i++)
    {
        ans += abs(pos[i]-even[i]);
    }
    return ans;
}

void solve()
{
    cin>>n;
    for(int i=1; i<=n; i++) { cin>>a[i]; a[i]%=2; }

    int ans = place_even(1);
    int tmp = place_even(2);
    ans = min(ans, tmp);

    if(ans==INF) cout<<-1<<endl;
    else cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}