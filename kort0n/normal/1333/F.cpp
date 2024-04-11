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
vector<ll> Div[500100];
ll num[500100];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    for(ll i = 1; i <= N; i++) {
        for(ll j = 2 * i; j <= N; j += i) {
            Div[j].push_back(i);
        }
    }
    priority_queue<l_l, vector<l_l>, greater<l_l>> que;
    que.push({1, 1});
    while(!que.empty()) {
        auto tmp = que.top();
        que.pop();
        ll val = tmp.second;
        if(val != 1) cout << tmp.first << " ";
        for(ll i = val * 2; i <= N; i += val) {
            num[i]++;
            if(num[i] == Div[i].size()) {
                que.push({Div[i].back(), i});
            }
        }
    }
    cout << endl;
    return 0;
}