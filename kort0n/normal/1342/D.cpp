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
ll N, K;
vector<l_l> v;
ll c[201000];

vector<ll> ans[201000];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        v.push_back({a, i});
    }
    sort(v.begin(), v.end(), greater<l_l>());
    for(int i = 1; i <= K; i++) {
        cin >> c[i];
    }
    int idx = 0;
    int ansnum = 0;
    for(int i = 0; i < v.size(); i++) {
        if(i > 0) {
            if(v[i].first != v[i-1].first) {
                if(c[v[i].first] != c[v[i-1].first]) idx = 0;
            }
        }
        while(ans[idx].size() == c[v[i].first]) idx++;
        ans[idx].push_back(v[i].first);
        chmax(ansnum, idx);
    }
    cout << ansnum + 1 << endl;
    for(int i = 0; i <= ansnum; i++) {
        cout << ans[i].size();
        for(auto val : ans[i]) {
            cout << " " << val;
        }
        cout << endl;
    }
    return 0;
}