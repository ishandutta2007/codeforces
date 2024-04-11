#include <bits/stdc++.h>
#define endl "\n"
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

const long long INF = 1e18;
//const ll mod = 1000000007;

vector<ll> idx[201000];

void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N);
    vector<ll> cmp;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        cmp.push_back(a[i]);
    }
    for(int i = 0; i <= N; i++) {
        idx[i].clear();
    }
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    for(int i = 0; i < N; i++) {
        auto itr = lower_bound(cmp.begin(), cmp.end(), a[i]);
        a[i] = itr - cmp.begin();
        idx[a[i]].push_back(i);
    }
    ll ans = 0;
    for(int i = 0; i < N; i++) {
        chmax(ans, ll(idx[i].size()));
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < idx[i].size(); j++) {
            auto itr = lower_bound(idx[i+1].begin(), idx[i+1].end(), idx[i][j]);
            ll tmp = j + 1 + (idx[i+1].end() - itr);
            chmax(ans, tmp);
        }
    }
    ll before = 0;
    for(int i = 0; i < N; i++) {
        if(idx[i].empty()) break;
        if(idx[i+1].size() and idx[i+1][0] > idx[i].back()) continue;
        ll tmp = 0;
        for(int j = before; j <= i; j++) {
            tmp += idx[j].size();
        }
        //cerr << before << " " << i << " " << tmp << endl;
        if(before > 0) {
            auto itr = lower_bound(idx[before-1].begin(), idx[before-1].end(), idx[before][0]);
            tmp += itr - idx[before-1].begin();
            //cerr << before << " " << i << " " << tmp << endl;
        }
        auto itr = lower_bound(idx[i+1].begin(), idx[i+1].end(), idx[i].back());
        tmp += idx[i+1].end() - itr;
        //cerr << before << " " << i << " " << tmp << endl;
        chmax(ans, tmp);
        //cerr << before << " " << i << " " << tmp << endl;
        before = i+1;
    }
    cout << N - ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}