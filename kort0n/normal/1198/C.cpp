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
ll N, M;
bool used[500050];
vector<int> edge;
 
 
void solve() {
    cin >> N >> M;
    edge.clear();
    for(int i = 1; i <= N * 3; i++) {
        used[i] = false;
    }
    for(int i = 1; i <= M; i++) {
        ll u, v;
        cin >> u >> v;
        if(!used[u] && !used[v]) {
            used[u] = true;
            used[v] = true;
            edge.push_back(i);
        }
    }
    if(edge.size() >= N) {
        cout << "Matching" << endl;
        for(int i = 0; i < N; i++) {
            cout << edge[i] << " ";
        }
        cout << endl;
        return;
    } else {
        cout << "IndSet" << endl;
        int num = 0;
        for(int i = 1; i <= 3 * N; i++) {
            if(num >= N) break;
            if(used[i]) continue;
            cout << i << " ";
            num++;
        }
        cout << endl;
    }
}
 
int main() {
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}