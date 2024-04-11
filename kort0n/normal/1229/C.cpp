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
vector<ll> over[100050];
ll nowval[100050];
ll ans = 0;
ll degree[100050];
ll value[100050];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 1; i <= M; i++) {
        ll a, b;
        cin >> a >> b;
        if(a < b) swap(a, b);
        over[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    for(int i = 1; i <= N; i++) {
        nowval[i] = (ll)over[i].size() * (degree[i] - over[i].size());
        ans += nowval[i];
    }
    cout << ans << "\n";
    ll Q;
    cin >> Q;
    while(Q--) {
        ll v;
        cin >> v;
        ans -= nowval[v];
        nowval[v] = 0;
        while(!over[v].empty()) {
            ll to = over[v].back();
            ans -= nowval[to];
            over[to].push_back(v);
            nowval[to] = (ll)over[to].size() * (degree[to] - over[to].size());
            ans += nowval[to];
            over[v].pop_back();
        }
        cout << ans << "\n";
        /*
        cerr << "----" << Q << "----" << endl;
        for(int i = 1; i <= N; i++) {
            cerr << "-" << i << "-" << endl;
            for(auto itr = over[i].begin(); itr != over[i].end(); itr++) cerr << *itr << " ";
            cerr << endl;
            for(auto itr = under[i].begin(); itr != under[i].end(); itr++) cerr << *itr << " ";
            cerr << endl;
        }
        */
    }
    return 0;
}