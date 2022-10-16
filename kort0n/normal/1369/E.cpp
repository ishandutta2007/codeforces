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
bool usedperson[201000];
bool usedfood[200100];
ll x[201000], y[201000];
vector<ll> ans;
ll need[201000];
vector<ll> inv[201000];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<ll> w(N);
    for(int i = 0; i < N; i++) cin >> w[i];
    for(int i = 0; i < M; i++) {
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
        inv[x[i]].push_back(i);
        inv[y[i]].push_back(i);
        need[x[i]]++;
        need[y[i]]++;
    }
    queue<int> que;
    for(int i = 0; i < w.size(); i++) {
        if(w[i] >= need[i]) que.push(i);
    }
    while(!que.empty()) {
        int now = que.front();
        //cerr << now << endl;
        que.pop();
        if(usedfood[now]) continue;
        usedfood[now] = true;
        for(auto person : inv[now]) {
            if(usedperson[person]) continue;
            ans.push_back(person);
            usedperson[person] = true;
            need[x[person]]--;
            need[y[person]]--;
            if(w[x[person]] >= need[x[person]]) que.push(x[person]);
            if(w[y[person]] >= need[y[person]]) que.push(y[person]);
        }
    }
    reverse(ans.begin(), ans.end());
    if(ans.size() != M) {
        cout << "DEAD" << endl;
    } else {
        cout << "ALIVE" << endl;
        for(auto tmp : ans) cout << tmp + 1 << " ";
        cout << endl;
    }
    return 0;
}