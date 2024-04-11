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
int N;
int a[105];
map<vector<int>, int> mp;
int f(int now) {
    if(now == 0) return 0;
    return (now & 1) + f(now >> 1);
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < (1 << 15); i++) {
        vector<int> v(N);
        for(int j = 0; j < N; j++) {
            int now = a[j];
            now &= (1 << 15) - 1;
            now ^= i;
            v[j] = f(now);
            //cerr << j << " " << v[j] << endl;
        }
        mp[v] = i + 1;
    }
    for(int i = 0; i < (1 << 15); i++) {
        int bits = (i << 15);
        vector<int> v(N);
        for(int j = 0; j < N; j++) {
            int now = a[j];
            now &= ~((1 << 15) - 1);
            now ^= bits;
            v[j] = -f(now);
        }
        for(int timer = 0; timer <= 40; timer++) {
            if(mp.count(v) == 0) {
                for(int j = 0; j < v.size(); j++) v[j]++;
                continue;
            }
            int ans = bits | (mp[v] - 1);
            cout << ans << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}