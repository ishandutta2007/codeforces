#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ld = long double;
using ull = unsigned long long;



const ll MAXN = 101005;
vector<ll> g[MAXN];
vector<ll> h;
vector<ll> a;
vector<ll> st, fin;
vector<vector<ll>> sparse;

void dfs(ll v, ll p = -1){
    st[v] = a.size();
    a.push_back(v);
    for(auto u: g[v]){
        if(u == p){
            continue;
        }
        h[u] = h[v] + 1;
        dfs(u, v);
        a.push_back(v);
    }
    fin[v] = -1 + (ll)a.size();
}

vector<ll> vv;

ll lca(ll x, ll y){
    if(st[x] > st[y]){
        swap(x, y);
    }
    ll len = st[y] - st[x] + 1;
    ll cur = len;
    ll log1 = vv[len];
    ll xx = sparse[log1][st[x]];
    ll yy = sparse[log1][st[y] - (1LL << log1) + 1];
    if(h[xx] < h[yy]){
        return xx;
    }else{
        return yy;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    ll n, q;
    cin >> n >> q;
//    n = q = 100000;
//    srand(time(nullptr));
    ll x, y, z;
    h.resize(n, 0);
    st.resize(n, 0);
    fin.resize(n, 0);
    for(ll i = 1; i < n; ++i){
//        x = 1;
//        x = rand() % i + 1;
        cin >> x;
        --x;
        g[x].push_back(i);
    }
    h[0] = 0;
    dfs(0);
    ll cur = -1 + (ll)a.size();
    ll log = 1;
    while(cur > 0){
        cur >>= 1LL;
        ++log;
    }
    vv.resize(a.size() + 5, 0);
    for(ll i = 3; i < a.size() + 5; ++i){
        vv[i] = vv[i - 1];
        if(((i - 1LL) & (i - 2LL)) == 0){
            ++vv[i];
        }
    }

    sparse.resize(log, vector<ll>(a.size(), 0));
    for(ll i = 0; i < a.size(); ++i){
        sparse[0][i] = a[i];
    }
    for(ll i = 1; i < log; ++i){
        for(ll j = 0; j < a.size(); ++j){
            if(j + (1LL << (i - 1)) >= a.size()){
                sparse[i][j] = sparse[i - 1][j];
            }else {
                sparse[i][j] = (h[sparse[i - 1][j]] < h[sparse[i - 1][j + (1LL << (i - 1))]] ? sparse[i - 1][j] : sparse[i - 1][j + (1LL << (i - 1))]);
            }
        }
    }

    for(ll i = 0; i < q; ++i){
        vector<ll> o(3);
//        o[0] = rand() % n;
//        o[1] = rand() % n;
//        o[2] = rand() % n;
        for(ll u = 0; u < 3; ++u){
            cin >> o[u];
            --o[u];
        }
        sort(o.begin(), o.end());
        if(o[0] == o[1] && o[0] == o[2]){
            cout << 1 << endl;
        }else{
            if(o[0] == o[1]){
                cout << h[o[0]] + h[o[2]] - 2 * h[lca(o[0], o[2])] + 1 << endl;
            }else{
                if(o[1] == o[2]){
                    cout << h[o[0]] + h[o[1]] - 2 * h[lca(o[0], o[1])] + 1 << endl;
                }else{
                    ll x01 = lca(o[0], o[1]);
                    ll x12 = lca(o[1], o[2]);
                    ll x02 = lca(o[0], o[2]);
                    ll xxx = lca(x01, o[2]);
                    if(x01 == x12 && x01 == x02){
                        cout << 1 + max(max(h[o[0]], h[o[1]]), h[o[2]]) - h[xxx] << endl;
                    }else{
                        if(x01 == xxx && x02 == xxx){
                            cout << 1 + max(max(h[o[0]] + h[x12] - 2 * h[xxx], h[o[1]] - h[x12]), h[o[2]] - h[x12]) << endl;
                        }else{
                            if(x01 == xxx && x12 == xxx){
                                cout << 1 + max(max(h[o[1]] + h[x02] - 2 * h[xxx], h[o[0]] - h[x02]), h[o[2]] - h[x02]) << endl;
                            }else{
                                cout << 1 + max(max(h[o[2]] + h[x01] - 2 * h[xxx], h[o[0]] - h[x01]), h[o[1]] - h[x01]) << endl;
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}