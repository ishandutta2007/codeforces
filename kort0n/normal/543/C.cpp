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
int N, M;
string S[21];
int a[21][21];
int ok[1 << 21];
int dp[1 << 21];
set<int> appeared;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < (1<<21); i++) {
        ok[i] = 1e9;
        dp[i] = 1e9;
    }
    dp[0] = 0;
    for(int i = 0; i < N; i++) cin >> S[i];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) cin >> a[i][j];
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            chmin(ok[(1 << i)], a[i][j]);
        }
        appeared.insert((1 << i));
    }
    for(int i = 0; i < M; i++) {
        for(char ch = 'a'; ch <= 'z'; ch++) {
            int bits = 0;
            int sum = 0;
            int maxi = 0;
            for(int j = 0; j < N; j++) {
                if(S[j][i] != ch) continue;
                sum += a[j][i];
                chmax(maxi, a[j][i]);
                bits |= (1 << j);
            }
            appeared.insert(bits);
            //cerr << bits << " " << sum-maxi << endl;
            chmin(ok[bits], sum - maxi);
        }
    }
    for(int bits = 1; bits < (1 << N); bits++) {
        for(auto itr = appeared.begin(); itr != appeared.end(); itr++) {
            int now = *itr;
            chmin(dp[bits], ok[now] + dp[bits & (~now)]);
        }
    }
    cout << dp[(1 << N) - 1] << endl;
    return 0;
}