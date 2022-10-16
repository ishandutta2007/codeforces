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
ll N;
ll p[201000];
bool visited[201000];
vector<l_l> ans;
ll moved[201000];

void h(int x, int y) {
    ans.push_back({x, y});
    swap(p[x], p[y]);
    moved[p[x]]++;
    moved[p[y]]++;
}

void f(vector<int> a) {
    assert(a.size() >= 3);
    for(int i = 1; i + 1 < a.size(); i++) {
        h(a[0], a[i]);
    }
    h(a[1], a.back());
    h(a[0], a.back());
    h(a[0], a[1]);
}

void g(vector<int> a, vector<int> b) {
    h(a[0], b[0]);
    for(int i = 1; i < a.size(); i++) {
        h(a[i], b[0]);
    }
    for(int i = 1; i < b.size(); i++) {
        h(a[0], b[i]);
    }
    h(a[0], b[0]);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> p[i];
        p[i]--;
    }
    vector<vector<int>> C;
    for(int i = 0; i < N; i++) {
        if(visited[i]) continue;
        vector<int> v;
        int now = i;
        while(!visited[now]) {
            visited[now] = true;
            v.push_back(now);
            now = p[now];
        }
        C.push_back(v);
    }
    /*
    for(auto v : C) {
        for(auto tmp : v) cerr << tmp << ", ";
        cerr << endl;
    }
    */
    if(C.size() == 1) {
        f(C[0]);
    } else {
        if(C.size() % 2 == 1) {
            int tmp = C[0][0];
            C.push_back({tmp});
        }
        for(int i = 0; i < C.size(); i += 2) {
            g(C[i], C[i+1]);
        }
    }
    /*
    for(int i = 0; i < N; i++) {
        cerr << p[i] << " ";
    }
    cerr << endl;
    for(int i = 0; i < N; i++) {
        cerr << moved[p[i]] % 2 << " ";
    }
    cerr << endl;
    */
    assert(ans.size() <= N + 1);
    for(int i = 0; i < N; i++) {
        assert(p[i] == i);
    }
    for(int i = 0; i < N; i++) {
        assert(moved[i] % 2 == 0);
    }
    cout << ans.size() << endl;
    for(auto tmp : ans) {
        cout << tmp.first + 1 << " " << tmp.second + 1 << endl;
    }
    return 0;
}