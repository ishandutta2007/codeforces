#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define pll pair<ll,ll>
#define ff first
#define ss second
#define pb push_back
#define endl "\n"
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=5e5+10;
const ll mod=1e9+7  ;
const long long base=3e18;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("t.inp","r"))
    {
        freopen("test.inp","r",stdin);
        freopen("test.ans","w",stdout);
    }
    ll n;
    cin>> n;
    if (n%2==0) cout <<"Mahmoud"<<endl;
    else cout <<"Ehab"<<endl;
}
/*
5
1 2 3 4 5
5
0 2
2 4
4 6
0 8
1 4
*/