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
int N;
vector<int> paths[105000];
vector<i_i> v;
void dfs(int now, int from, int fromt, int rett) {
    int nowt = fromt;
    int delta = paths[now].size();
    int maxit = fromt;
    int minit = maxit - delta;
    if(minit < 0) {
        maxit += (-minit);
        minit = 0;
    }
    for(auto to : paths[now]) {
        if(to == from) continue;
        if(nowt == maxit) {
            v.push_back({now, minit});
            nowt = minit;
        }
        v.push_back({to, nowt + 1});
        dfs(to, now, nowt + 1, nowt + 1);
        nowt = nowt + 1;
    }
    if(from == -1) return;
    if(nowt != rett - 1) {
        v.push_back({now, rett - 1});
        nowt = rett - 1;
    }
    v.push_back({from, rett});
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    v.push_back({0, 0});
    dfs(0, -1, 0, paths[0].size()+1);
    cout << v.size() << endl;
    for(auto tmp : v) {
        cout << tmp.first + 1 << " " << tmp.second << endl;
    }
    return 0;
}