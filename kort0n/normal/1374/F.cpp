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

void solve() {
    ll N;
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int inv = 0;
    bool same = false;
    int t = 0;
    for(int i = 0; i < N; i++) {
        chmax(t, a[i]);
        for(int j = 0; j < i; j++) {
            if(a[j] > a[i]) inv++;
            if(a[i] == a[j]) same = true;
        }
    }
    vector<int> ans;
    if(inv % 2 == 1 and !same) {
        cout << -1 << endl;
        return;
    }
    vector<i_i> v;
    for(int i = 0; i < N; i++) {
        v.push_back({a[i], i});
    }
    sort(v.begin(), v.end());
    if(inv % 2 == 1) {
        bool ok = false;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < i; j++) {
                if(ok) break;
                if(v[i].first == v[j].first) {
                    swap(v[i].second, v[j].second);
                    ok = true;
                }
            }
        }
    }
    for(int i = 0; i < v.size(); i++) {
        a[v[i].second] = i;
    }
    /*
    for(int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    */
    for(int i = 0; i < N; i++) {
        while(a[i] != i) {
            int idx = 0;
            for(int j = 0; j < N; j++) {
                if(a[j] == i) idx = j;
            }
            if(abs(idx - i) % 2 == 0 or idx == N - 1) {
                ans.push_back(idx-2);
                swap(a[idx], a[idx-1]);
                swap(a[idx-1], a[idx-2]);
            } else {
                ans.push_back(idx - 1);
                swap(a[idx+1], a[idx]);
                swap(a[idx], a[idx-1]);
            }
        }
    }
    cout << ans.size() << endl;
    for(auto tmp : ans) cout << tmp + 1 << " ";
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}