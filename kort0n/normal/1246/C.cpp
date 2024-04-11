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
const ll mod = 1000000007;
ll H, W;
ll dp[2005][2005][2];
ll dpsumLeft[2005][2005][2];
ll dpsumUp[2005][2005][2];
string field[2005];
ll Left[2005][2005];
ll Up[2005][2005];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    for(int h = 1; h <= H; h++) {
        cin >> field[h];
        field[h] = "#" + field[h];
    }
    if(H == 1 && W == 1) {
        cout << 1 << endl;
        return 0;
    }
    dp[1][1][0] = 1;
    dp[1][1][1] = 1;
    dpsumLeft[1][1][0] = 1;
    dpsumLeft[1][1][1] = 1;
    dpsumUp[1][1][0] = 1;
    dpsumUp[1][1][1] = 1;
    for(int h = 1; h <= H; h++) {
        ll num = 0;
        for(int w = W; w > 0; w--) {
            if(field[h][w] == 'R') {
                Left[h][W - num] = w - 1;
                num++;
            }
        }
    }
    for(int w = 1; w <= W; w++) {
        ll num = 0;
        for(int h = H; h > 0; h--) {
            if(field[h][w] == 'R') {
                Up[H - num][w] = h - 1;
                num++;
            }
        }
    }
    /*
    for(int h = 1; h <= H; h++) {
        for(int w = 1; w <= W; w++) {
            cerr << Up[h][w] << " ";
        }
        cerr << endl;
    }
    */
    for(int h = 1; h <= H; h++) {
        for(int w = 1; w <= W; w++) {
            dp[h][w][0] += dpsumLeft[h][w-1][1] - dpsumLeft[h][Left[h][w]][1] + mod;
            dp[h][w][1] += dpsumUp[h-1][w][0] - dpsumUp[Up[h][w]][w][0] + mod;
            dp[h][w][0] %= mod;
            dp[h][w][1] %= mod;
            //cerr << h << " " << w << " " << dp[h][w][0] << " " << dp[h][w][1] << endl;
            for(int k = 0; k <= 1; k++) {
                dpsumLeft[h][w][k] = dpsumLeft[h][w-1][k] + dp[h][w][k];
                dpsumUp[h][w][k] = dpsumUp[h-1][w][k] + dp[h][w][k];
                dpsumLeft[h][w][k] %= mod;
                dpsumUp[h][w][k] %= mod;
            }
        }
    }
    cout << (dp[H][W][0] + dp[H][W][1]) % mod << endl;
    return 0;
}