#include <bits/stdc++.h>
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

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
bool visited[5005];
bool visiting[5005];
int n, m;
vector<int> pathes[5005];
bool circuit = false;

void f(int now) {
    visiting[now] = true;
    for(auto to: pathes[now]) {
        if(visiting[to]) {
            circuit = true;
            return;
        }
        if(!visited[to]) f(to);
    }
    visiting[now] = false;
    visited[now] = true;
}

bool enlarge[5005];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        pathes[u].push_back(v);
        if(v > u) enlarge[i] = true;
    }
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) f(i);
    }
    if(!circuit) {
        cout << 1 << endl;
        for(int i = 1; i <= m; i++) cout << "1 ";
        cout << endl;
        return 0;
    } else {
        cout << 2 << endl;
        for(int i = 1; i <= m; i++) {
            if(enlarge[i]) cout << 1;
            else cout << 2;
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}