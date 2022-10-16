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
ll N, M, K;
ll p[105000];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    for(int i = 1; i <= M; i++) cin >> p[i];
    ll removed = 0;
    ll index = 1;
    for(ll timer = 1; ; timer++) {
        ll page = (p[index] - removed - 1) / K + 1;
        while(index <= M && (p[index] - removed - 1) / K + 1 == page) index++;
        if(index == M + 1) {
            cout << timer << endl;
            return 0;
        }
        removed = index - 1;
    }
    return 0;
}