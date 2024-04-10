#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


int main()
{
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int mask = (1 << k) - 1;
    int dumb = 1 << (k - 1);
    vector<int> a(n);
    map<int, int> mp;
    int x = 0;
    ++mp[0];
    int y;
    for(int i = 0; i < n; ++i){
        cin >> y;
        x ^= y;
        if(x >= dumb){
            ++mp[x ^ mask];
        }else{
            ++mp[x];
        }
    }
    ll ans = ((n + 1) * ll(n)) / 2;
    for(auto u: mp){
        int q1 = (u.second + 1) / 2;
        int q2 = (u.second) / 2;
        ans -= q1 * ll(q1 - 1) / 2;
        ans -= q2 * ll(q2 - 1) / 2;
    }
    cout << ans << endl;


}
/*
5 30
998244353 998244353 998244353 998244353 998244353
11

*/