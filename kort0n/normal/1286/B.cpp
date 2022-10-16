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

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
//const ll mod = 1000000007;
int val;
int N;
int p[2005];
vector<int> children[2005];
int c[2005];
int SIZE[2005];
int ans[2005];
int root;
void f(int now) {
    SIZE[now] = 1;
    for(auto to : children[now]) {
        f(to);
        SIZE[now] += SIZE[to];
    }
}

void g(int now) {
    SIZE[now]--;
    //cerr << "g:" << now << endl;
    if(p[now] != -1) g(p[now]);
}

bool dfs(int now) {
    if(SIZE[now] - 1 == c[now]) {
        ans[now] = val;
       // cerr << now << " " << val << endl;
        g(now);
        return true;
    }
    for(auto to : children[now]) {
        if(dfs(to)) return true;
    }
    return false;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> p[i] >> c[i];
        p[i]--;
    }
    for(int i = 0; i < N; i++) {
        if(p[i] == -1) {
            root = i;
            continue;
        }
        children[p[i]].push_back(i);
    }
    val = N;
    f(root);
    for(int i = 0; i < N; i++) {
        dfs(root);
        val--;
    }
    for(int i = 0; i < N; i++) {
        if(ans[i] == 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}