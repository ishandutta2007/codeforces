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
vector<int> paths[501000], children[501000];
int p[501000];
ll l[501000], r[501000];
ll ans = 0;

void dfs(int now) {
    for(auto to : paths[now]) {
        if(to == p[now]) continue;
        children[now].push_back(to);
        p[to] = now;
        dfs(to);
    }
}

void f(int now) {
    for(int i = 0; i < children[now].size(); i++) {
        f(children[now][i]);
    }
    l[now] = ++ans;
    for(int i = 0; i < children[now].size(); i++) {
        int a = children[now][children[now].size()-1-i];
        r[a] = ++ans;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    p[0] = -1;
    dfs(0);
    f(0);
    r[0] = ++ans;
    for(int i = 0; i < N; i++) {
        cout << l[i] << " " << r[i] << endl;
    }
    return 0;
}