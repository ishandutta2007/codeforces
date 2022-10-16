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
ll cost[500][26][26];
string S[500];
int field[500][500];
ll dp[500][26][26];
int ans[500][500];
int main() {
    int H, W;
    cin >> H >> W;
    for(int i = 0; i < H; i++) {
        cin >> S[i];
        for(int j = 0; j < W; j++) {
            field[i][j] = (int)(S[i][j] - 'a');
        }
    }
    for(int h = 0; h < H; h++) {
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                for(int k = 0; k < W; k++) {
                    if(k & 1) {
                        if(field[h][k] != j) cost[h][i][j]++;
                    } else {
                        if(field[h][k] != i) cost[h][i][j]++;
                    }
                    if(W > 1 and i == j) cost[h][i][j] = INF;
                }
            }
        }
    }
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            dp[0][i][j] = cost[0][i][j];
        }
    }
    for(int h = 1; h < H; h++) {
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                dp[h][i][j] = INF;
                for(int i1 = 0; i1 < 26; i1++) {
                    for(int j1 = 0; j1 < 26; j1++) {
                        if(i == i1) continue;
                        if(j == j1) continue;
                        chmin(dp[h][i][j], dp[h-1][i1][j1] + cost[h][i][j]);
                    }
                }
            }
        }
    }
    /*
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            cerr << i << " " << j << " " << dp[H-1][i][j] << endl;
        }
    }
    */
    int beforei = -1;
    int beforej = -1;
    ll ansval = 0;
    for(int h = H-1; h >= 0; h--) {
        ll maxi = INF;
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                if(i == j) continue;
                if(i == beforei) continue;
                if(j == beforej) continue;
                chmin(maxi, dp[h][i][j]);
            }
        }
        //cerr << h << " " << maxi << endl;
        if(h == H - 1) ansval = maxi;
        bool changed = false;
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                if(changed) break;
                if(i == j) continue;
                if(i == beforei) continue;
                if(j == beforej) continue;
                if(dp[h][i][j] != maxi) continue;
                cerr << h << " " << i << " " << j << endl;
                changed = true;
                for(int k = 0; k < W; k++) {
                    if(k & 1) ans[h][k] = j;
                    else ans[h][k] = i;
                }
                beforei = i;
                beforej = j;
            }
        }
    }
    cout << ansval << endl;
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            cout << (char)('a' + ans[h][w]);
        }
        cout << endl;
    }
    return 0;
}