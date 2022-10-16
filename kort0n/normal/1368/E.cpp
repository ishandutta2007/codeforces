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
ll N, M;
vector<int> paths[201000], inv[210000];
vector<int> ans;
bool used[201000];
int dist[201000];
random_device rd;
mt19937 mt(rd());
uniform_int_distribution<> test(0, 100);

void solve() {
    ans.clear();
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        used[i] = false;
        paths[i].clear();
        inv[i].clear();
    }
    for(int i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        paths[a].push_back(b);
        inv[b].push_back(a);
    }
    vector<int> v[3];
    for(int i = 0; i < N; i++) {
        vector<int> p;
        for(auto j : inv[i]) {
            if(used[j]) continue;
            p.push_back(j);
        }
        if(p.size() >= 2) {
            used[i] = true;
            ans.push_back(i);
        }
        if(p.size() == 1) {
            dist[i] = (dist[p[0]] + 1) % 3;
            v[dist[i]].push_back(i);
            if(dist[i] == 2) {
                used[i] = true;
                ans.push_back(i);
            }
        }
        if(p.size() == 0) {
            dist[i] = 0;
            v[dist[i]].push_back(i);
        }
    }
    /*
    int idx = 0;
    for(int i = 0; i < 3; i++) {
        if(v[i].size() < v[idx].size()) idx = i;
    }
    for(auto tmp : v[idx]) ans.push_back(tmp);
    */
    //cerr << N << " " << M << " " << 4 * N / 7 << endl;
    if(ans.size() > 4 * N / 7) {
        //cerr << "ERROR" << endl;
        //for(auto tmp : ans) cerr << tmp << " ";
        //cerr << endl;
        shuffle(ans.begin(), ans.end(), mt);
        ans.resize(4 * N / 7);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto tmp : ans) {
        cout << tmp + 1 << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}