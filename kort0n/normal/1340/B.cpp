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
int A[10];
string dust[10] = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
void initialize() {
    for(int i = 0; i < 10; i++) {
        //reverse(S[i].begin(), S[i].end());
        A[i] = stoi(dust[i], 0, 2);
        //cerr << i << " " << A[i] << endl;
    }
}

bool dp[2005][2005];
string dust2[2005];
int B[2005];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    initialize();
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> dust2[i];
        B[i] = stoi(dust2[i], 0, 2);
    }
    dp[N][0] = true;
    for(int i = N - 1; i >= 0; i--) {
        for(int d = 0; d < 10; d++) {
            if((B[i] & A[d]) != B[i]) continue;
            int tmp = A[d] & (~B[i]);
            int delta = __builtin_popcount(tmp);
            for(int k = 0; k <= K - delta; k++) {
                dp[i][k+delta] |= dp[i+1][k];
            }
        }
    }
    if(!dp[0][K]) {
        cout << -1 << endl;
        return 0;
    }
    int nowk = K;
    for(int i = 0; i < N; i++) {
        for(int d = 9; d >= 0; d--) {
            if((B[i] & A[d]) != B[i]) continue;
            int tmp = A[d] & (~B[i]);
            int delta = __builtin_popcount(tmp);
            if(nowk >= delta and dp[i+1][nowk-delta]) {
                cout << d;
                nowk -= delta;
                break;
            }
        }
    }
    cout << endl;
    return 0;
}