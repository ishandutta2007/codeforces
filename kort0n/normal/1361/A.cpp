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
vector<int> paths[500100];
int topic[500100];
int ans[500100];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    vector<int> t(N);
    queue<int> que;
    for(int i = 0; i < N; i++) {
        cin >> t[i];
        t[i]--;
    }
    for(int i = 0; i < N; i++) {
        for(auto j : paths[i]) {
            if(t[i] == t[j]) {
                cout << -1 << endl;
                return 0;
            }
        }
        if(t[i] == 0) que.push(i);
    }
    int num = 0;
    while(!que.empty()) {
        int now = que.front();
        que.pop();
        ans[num] = now;
        num++;
        for(auto to : paths[now]) {
            if(topic[to] == t[now]) {
                topic[to]++;
                if(topic[to] == t[to]) {
                    que.push(to);
                }
            }
        }
    }
    if(num != N) {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < N; i++) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}