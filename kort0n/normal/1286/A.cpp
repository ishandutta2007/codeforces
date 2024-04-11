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
int N;
int ans;
int p[105];
int num[2];
vector<i_i> V[2];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> p[i];
    for(int i = 1; i <= N; i++) {
        bool ok = true;
        for(int j = 0; j < N; j++) {
            if(p[j] == i) ok = false;
        }
        if(ok) {
            num[i % 2]++;
        }
    }
    int before = -1;
    for(int i = 0; i < N; i++) {
        if(p[i] == 0) continue;
        if(before == -1) {
            V[p[i] % 2].push_back({-1, i});
            before = i;
        } else {
            if(p[i] % 2 != p[before] % 2) {
                cerr << i << " " << before << endl;
                ans++;
            } else {
                V[p[i] % 2].push_back({-2, i - before - 1});
            }
        }
        before = i;
    }
    if(before == -1) {
        if(N == 1) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
        return 0;
    }
    V[p[before] % 2].push_back({-1, N - 1 - before});
    cerr << ans << endl;
    for(int parity = 0; parity <= 1; parity++) {
        sort(V[parity].begin(), V[parity].end());
        for(auto now : V[parity]) {
            //cerr << num[parity] << " " << now.first << " " << now.second << endl;
            if(num[parity] >= now.second) {
                num[parity] -= now.second;
            } else {
                ans += -now.first;
            }
        }
    }
    cout << ans << endl;
    return 0;
}