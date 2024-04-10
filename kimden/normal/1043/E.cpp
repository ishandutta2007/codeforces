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
    int n, m;
    cin >> n >> m;
    vector<pii> p;
    vector<ll> ans(n);
    vector<ll> x(n), y(n);
    for(int i = 0; i < n; ++i){
        cin >> x[i] >> y[i];
        p.emplace_back(x[i] - y[i], i);
    }
    stable_sort(all(p));
    vector<ll> pref(n, 0), suff(n, 0);
    for(int i = 0; i < n; ++i){
        pref[i] = (i ? pref[i - 1] : 0) + x[p[i].second];
    }
    for(int i = n - 1; i >= 0; --i){
        suff[i] = (i < n - 1 ? suff[i + 1] : 0) + y[p[i].second];
    }
    for(int i = 0; i < n; ++i){
        int idx = p[i].second;
        ans[idx] = i * y[idx] + (n - 1 - i) * x[idx] + (i ? pref[i - 1] : 0) + (i < n - 1 ? suff[i + 1] : 0);
    }
    for(int i = 0; i < m; ++i){
            int p, q;
        cin >> p >> q;
        --p;
        --q;
        if(x[p] - y[p] < x[q] - y[q]){
            ans[p] -= x[p] + y[q];
            ans[q] -= x[p] + y[q];
        }else{
            ans[p] -= y[p] + x[q];
            ans[q] -= y[p] + x[q];
        }
    }
    for(int i = 0; i < n; ++i){
        cout << ans[i] << " ";
    }
    cout << endl;



}