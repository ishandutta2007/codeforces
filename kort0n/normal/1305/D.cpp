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
vector<int> paths[1005];
int N;
int ret;
void query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    cin >> ret;
}
vector<int> v;
void dfs(int now, int from) {
    v.push_back(now);
    for(auto to : paths[now]) {
        if(to == from) continue;
        dfs(to, now);
    }
}

bool CUT(int root, int now, int from, int t) {
    if(now == t) return true;
    for(auto to : paths[now]) {
        if(to == from) continue;
        if(CUT(root, to, now, t)) {
            if(root == now) {
                auto itr = lower_bound(paths[now].begin(), paths[now].end(), to);
                //cerr << "CUT: " << now << " " << *itr << endl;
                paths[now].erase(itr);
                //cerr << paths[now].size() << endl;
            }
            return true;
        }
    }
    return false;
}

bool END = false;
void solve(int root) {
    v.clear();
    dfs(root, -1);
    //cerr << "sz: " << root << " " << v.size() << endl;
    if(v.size() == 1) {
        cout << "! " << root << endl;
        END = true;
        return;
    }
    if(v.size() == 2) {
        query(v[0], v[1]);
        cout << "! " << ret << endl;
        END = true;
        return;
    }
    bool ok = false;
    for(int i = 0; i < v.size(); i++) {
        if(ok) break;
        for(int j = 0; j < i; j++) {
            if(ok) break;
            auto itr = lower_bound(paths[v[i]].begin(), paths[v[i]].end(), v[j]);
            if(itr == paths[v[i]].end() or *itr != v[j]) {
                query(v[i], v[j]);
                if(ret == v[i]) {
                    CUT(v[i], v[i], -1, v[j]);
                }
                if(ret == v[j]) {
                    CUT(v[j], v[j], -1, v[i]);
                }
                if(ret != v[i] and ret != v[j]) {
                    CUT(ret, ret, -1, v[i]);
                    CUT(ret, ret, -1, v[j]);
                }
                ok = true;
            }
        }
    }
}

int main() {
    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    for(int i = 1; i <= N; i++) {
        sort(paths[i].begin(), paths[i].end());
    }
    ret = 1;
    while(true) {
        solve(ret);
        if(END) break;
    }
    return 0;
}