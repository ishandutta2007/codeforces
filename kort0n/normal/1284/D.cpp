#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll N;
ll sa[105000], ea[105000], sb[105000], eb[105000];
bool Clear = true;

void solve() {
    multiset<ll> S, E;
    map<ll, vector<ll>> mp;
    for(int i = 0; i < N; i++) {
        mp[sa[i]].push_back(-i - 1);
        mp[ea[i]].push_back(i);
    }
    for(auto tmp : mp) {
        auto v = tmp.second;
        sort(v.begin(), v.end());
        for(auto val : v) {
            if(val < 0) {
                val = -(val + 1);
                if(!E.empty()) {
                    auto itr = E.begin();
                    if(*itr < sb[val]) {
                        Clear = false;
                    }
                    itr = S.end();
                    itr--;
                    if(*itr > eb[val]) {
                        Clear = false;
                    }
                }
                S.insert(sb[val]);
                E.insert(eb[val]);
            } else {
                auto itr = S.lower_bound(sb[val]);
                S.erase(itr);
                itr = E.lower_bound(eb[val]);
                E.erase(itr);
            }
        }
    }
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> sa[i] >> ea[i] >> sb[i] >> eb[i];
    }
    solve();
    for(int i = 0; i < N; i++) {
        swap(sa[i], sb[i]);
        swap(ea[i], eb[i]);
    }
    solve();
    if(Clear) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}