#include <bits/stdc++.h>
//#include <atcoder/all>
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
ll a[201000];
vector<ll> ans;

void YES() {
    cout << "YES" << endl;
    assert(ans.size() == 4);
    assert(a[ans[0]] + a[ans[1]] == a[ans[2]] + a[ans[3]]);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < i; j++) {
            assert(ans[i] != ans[j]);
        }
        if(i != 0) cout << " ";
        cout << ans[i] + 1;
    }
    cout << endl;
    exit(0);
}

l_l dp[7000000];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    for(int i = 0; i < 7e6; i++) {
        dp[i] = {-1, -1};
    }
    ll N;
    cin >> N;
    map<ll, vector<ll>> mp;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    vector<ll> two;
    for(auto tmp : mp) {
        if(tmp.second.size() >= 4) {
            for(int i = 0; i < 4; i++) {
                ans.push_back(tmp.second[i]);
            }
            YES();
        }
        if(tmp.second.size() >= 2) {
            two.push_back(tmp.first);
        }
    }
    if(two.size() >= 2) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                ans.push_back(mp[two[j]][i]);
            }
        }
        YES();
    }
    for(int i1 = 0; i1 < N; i1++) {
        for(int j1 = 0; j1 < i1; j1++) {
            int i = i1;
            int j = j1;
            ll val = a[i] + a[j];
            if(dp[val].first == -1) {
                dp[val] = {i, j};
            } else {
                if(i == dp[val].first) continue;
                if(i == dp[val].second) continue;
                if(j == dp[val].first) continue;
                if(j == dp[val].second) continue;
                ans.push_back(dp[val].first);
                ans.push_back(dp[val].second);
                ans.push_back(i);
                ans.push_back(j);
                YES();
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}