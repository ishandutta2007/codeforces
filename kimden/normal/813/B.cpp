#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int MAXN = 200005;
vector<int> g[MAXN];
int h[MAXN];
int maxh[MAXN];

int x, y = -1;
vector<int> path;


int main() {
    ios_base::sync_with_stdio(false);
    ll x, y, l, r;
    cin >> x >> y >> l >> r;
    vector<ll> v, w;
    ll cur = 1;
    for(int i = 0; 1; cur *= x){
        v.push_back(cur);
        if((ld)cur * (ld)x > 1e18 + 1e-9){
            break;
        }
    }
    cur = 1;
    for(int i = 0; 1; cur *= y){
        w.push_back(cur);
        if((ld)cur * (ld)y > 1e18 + 1e-9){
            break;
        }
    }
    vector<ll> a;
    for(int i = 0; i < v.size(); ++i){
        for(int j = 0; j < w.size(); ++j){
            a.push_back(v[i] + w[j]);
        }
    }
    a.push_back(l - 1);
    a.push_back(r + 1);
    sort(a.begin(), a.end());
    ll ans = 0;
    for(int i = 0; i < a.size(); ++i){
        if(a[i] < l){
            continue;
        }
        if(a[i] > r + 1){
            break;
        }
        ans = max(ans, a[i] - a[i - 1] - 1);
    }
    cout << ans << endl;
    return 0;
}