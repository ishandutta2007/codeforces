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
vector<ll> PAIRS[1005];
ll inv = 0;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(v[j] < v[i]) {
                PAIRS[i].push_back(j);
                inv++;
            }
        }
    }
    vector<l_l> V;
    for(int i = 0; i < N; i++) {
        V.push_back({v[i], i});
    }
    vector<ll> a(N);
    sort(V.begin(), V.end());
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            l_l tmp = {v[i], i};
            if(tmp == V[j]) a[i] = j;
        }
    }
    vector<l_l> ans;
    for(int i = 0; i < N; i++) {
        sort(PAIRS[i].begin(), PAIRS[i].end(), [&](ll q, ll w) {
            return a[q] > a[w];
        });
        for(auto tmp : PAIRS[i]) {
            ans.push_back({i, tmp});
            swap(a[i], a[tmp]);
        }
    }
    for(int i = 1; i < N; i++) {
        assert(a[i-1] <= a[i]);
    }
    cout << ans.size() << endl;
    for(auto tmp : ans) {
        cout << tmp.first + 1 << " " << tmp.second + 1 << endl;
    }
    return 0;
}