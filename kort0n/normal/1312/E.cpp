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
int One[505][505];
ll N;
vector<ll> a;
ll dp[505];

int main() {
    cin >> N;
    a.resize(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            One[i][j] = -1;
        }
    }
    for(int i = 0; i < N; i++) {
        One[i][i+1] = a[i];
    }
    for(int delta = 2; delta <= N; delta++) {
        for(int i = 0; i + delta <= N; i++) {
            int j = i + delta;
            for(int k = i + 1; k < j; k++) {
                if(One[i][k] == -1) continue;
                if(One[k][j] == -1) continue;
                if(One[i][k] == One[k][j]) {
                    One[i][j] = One[i][k] + 1;
                    //cerr << i << " " << j << " " << One[i][j] << endl;
                    break;
                }
            }
        }
    }
    for(int i = 0; i < N; i++) {
        dp[i+1] = dp[i] + 1;
        for(int j = 0; j < i; j++) {
            if(One[j][i+1] == -1) {
                continue;
            } else {
                chmin(dp[i+1], dp[j] + 1);
            }
        }
        //cerr << i + 1 << " " << dp[i+1] << endl;
    }
    cout << dp[N] << endl;
    return 0;
}