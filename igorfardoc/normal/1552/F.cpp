#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> a(n);
    set<pair<int, int>> s;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].first.first >> a[i].first.second >> a[i].second;
        s.insert({a[i].first.first, i});
    }
    int now = 1;
    int res = (a[n - 1].first.first + 1) % mod;
    vector<int> minus(n, 0);
    for(int i = n - 1; i >= 0; i--)
    {   
        int here = now;
        if(a[i].second == 0)
        {
            here = (here + mod - 1) % mod;
        }
        res = (res + (ll)here * (a[i].first.first - a[i].first.second)) % mod;
        now = (now + here) % mod;
        auto it = s.lower_bound({a[i].first.second, -1});
        minus[(*it).second] = (minus[(*it).second] + here) % mod;
        now = ((ll)now - minus[i] + mod) % mod;
    }
    cout << res;
}