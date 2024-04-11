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
ll N;
ll u[100500], v[100500];
ll d[100500];
ll ans[100500];
ll num = 0;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;
        d[u[i]]++;
        d[v[i]]++;
        ans[i] = -1;
    }
    for(int i = 0; i < N - 1; i++) {
        if(d[u[i]] == 1 or d[v[i]] == 1) {
            ans[i] = num;
            num++;
        }
    }
    for(int i = 0; i < N - 1; i++) {
        if(ans[i] == -1) {
            ans[i] = num;
            num++;
        }
    }
    for(int i = 0; i < N - 1; i++) cout << ans[i] << "\n";
    return 0;
}