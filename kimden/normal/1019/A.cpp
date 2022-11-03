#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using itn = int;



int main()
{
    ios_base::sync_with_stdio(false);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> par(m);
  //  vector<vector<ll>> byidx(n);
    vector<ll> sumbyidx(n, 0);
    vector<ll> cnt(n, 0);
    vector<ll> acccnt(n, 0);
    for(int i = 0; i < n; ++i){
        int p;
        ll c;
        cin >> p >> c;
        --p;
        par[p].push_back(c);
    }
    ll mx = 0;
    for(int i = 0; i < m; ++i){
        sort(rall(par[i]));
        if(i > 0){
            mx = max(mx, (ll)par[i].size());
        }
    }
    for(int i = 1; i < m; ++i){
        for(int j = 0; j < par[i].size(); ++j){
         //   byidx[j].push_back(par[i][j]);
            sumbyidx[j] += par[i][j];
            ++cnt[j];
        }
    }
    for(int j = n - 1; j >= 0; --j){
        acccnt[j] = cnt[j];
    }
    for(int j = n - 2; j >= 0; --j){
        sumbyidx[j] += sumbyidx[j + 1];
        acccnt[j] += acccnt[j + 1];
    }
    ll ans = 1'000'000'000'000'000LL;
    for(int maxx = 0; maxx <= mx && maxx < n; ++maxx){
        ll cur = acccnt[maxx] + par[0].size();
        ll sum = sumbyidx[maxx];
        vector<ll> curcnt = cnt;
        ll ptr = maxx;
        set<pair<ll, pii>> st;
        for(int i = 1; i < m; ++i){
            for(int j = 0; j < maxx && j < par[i].size(); ++j){
                st.insert({par[i][j], {-j, i}});
            }
        }
        while(cur < ptr + 1){
            auto pp = *st.begin();
            st.erase(pp);
            int ii = pp.second.second;
            int jj = -pp.second.first;
            --curcnt[jj];
            sum += pp.first;
            ++cur;
            if(jj == ptr - 1 && curcnt[jj] == 0){
                --ptr;
            }
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;

    return 0;
}