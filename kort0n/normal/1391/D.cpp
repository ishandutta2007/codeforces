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
ll H, W;
vector<string> S;
vector<ll> v;
void Rotate() {
    vector<string> A(W);
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            A[w].push_back(S[h][w]);
        }
    }
    swap(S, A);
    swap(H, W);
}

ll Prev[8], Next[8];

int main() {
    cin >> H >> W;
    S.resize(H);
    for(int h = 0; h < H; h++) cin >> S[h];
    if(H >= 4 and W >= 4) {
        cout << -1 << endl;
        return 0;
    }
    if(W >= 4) Rotate();
    for(int h = 0; h < H; h++) {
        int tmp = 0;
        for(int w = 0; w < W; w++) {
            if(S[h][w] == '1') tmp += (1 << w);
        }
        v.push_back(tmp);
    }
    for(int i = 0; i < (1 << W); i++) {
        Prev[i] = __builtin_popcount(v[0] ^ i);
    }
    for(int h = 1; h < H; h++) {
        for(int bits = 0; bits < (1 << W); bits++) {
            Next[bits] = INF;
        }
        for(int from = 0; from < (1 << W); from++) {
            for(int to = 0; to < (1 << W); to++) {
                bool ok = true;
                for(int w = 0; w + 1 < W; w++) {
                    int num = 0;
                    num += (1 & (to >> w));
                    num += (1 & (from >> w));
                    num += (1 & (to >> (w+1)));
                    num += (1 & (from >> (w+1)));
                    if(num % 2 == 0) ok = false;
                }
                if(!ok) continue;
                chmin(Next[to], Prev[from] + __builtin_popcount(to ^ v[h]));
            }
        }
        swap(Prev, Next);
    }
    ll ans = INF;
    for(int bits = 0; bits < (1 << W); bits++) {
        chmin(ans, Prev[bits]);
    }
    cout << ans << endl;
    return 0;
}