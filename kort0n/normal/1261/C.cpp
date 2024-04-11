#include <bits/stdc++.h>
//#include <atcoder/all>
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

const int INF = 1e9;
//const ll mod = 1000000007;
ll H, W;
string S[1050000];
int dist[5050000];
int nowdist[5050000];
bool f(ll border) {
    for(int i = 0; i <= H*W; i++) nowdist[i] = INF;
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            if(dist[h*W+w] >= border + 1) {
                nowdist[h*W+w] = 0;
            }
        }
    }
    for(int h = 0; h < H; h++) {
        for(int w = 0; w + 1 < W; w++) {
            chmin(nowdist[h*W+w+1], nowdist[h*W+w] + 1);
            if(h+1<H) chmin(nowdist[(h+1)*W+w+1], nowdist[h*W+w] + 1);
        }
        for(int w = W - 1; w >= 1; w--) {
            chmin(nowdist[h*W+w-1], nowdist[h*W+w] + 1);
            if(h+1<H) chmin(nowdist[(h+1)*W+w-1], nowdist[h*W+w] + 1);
        }
    }
    for(int h = H - 1; h >= 0; h--) {
        for(int w = 0; w + 1 < W; w++) {
            if(h-1>=0) chmin(nowdist[(h-1)*W+w+1], nowdist[h*W+w] + 1);
        }
        for(int w = W - 1; w >= 1; w--) {
            if(h-1>=0) chmin(nowdist[(h-1)*W+w-1], nowdist[h*W+w] + 1);
        }
    }
    for(int w = 0; w < W; w++) {
        for(int h = 0; h + 1 < H; h++) {
            chmin(nowdist[(h+1)*W+w], nowdist[h*W+w] + 1);
        }
        for(int h = H - 1; h >= 1; h--) {
            chmin(nowdist[(h-1)*W+w], nowdist[h*W+w] + 1);
        }
    }
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            if((nowdist[h*W+w] <= border) ^ (S[h][w] == 'X')) return false;
        }
    }
    return true;
}

int main() {
    cin >> H >> W;
    H += 2;
    W += 2;
    for(int i = 0; i <= H * W; i++) dist[i] = INF;
    S[0] = string(W, '.');
    S[H-1] = string(W, '.');
    for(int h = 1; h < H - 1; h++) {
        cin >> S[h];
        S[h] = "." + S[h] + ".";
    }
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            if(S[h][w] == '.') {
                dist[h*W+w] = 0;
            }
        }
    }
    for(int h = 0; h < H; h++) {
        for(int w = 0; w + 1 < W; w++) {
            chmin(dist[h*W+w+1], dist[h*W+w] + 1);
            if(h+1<H) chmin(dist[(h+1)*W+w+1], dist[h*W+w] + 1);
        }
        for(int w = W - 1; w >= 1; w--) {
            chmin(dist[h*W+w-1], dist[h*W+w] + 1);
            if(h+1<H) chmin(dist[(h+1)*W+w-1], dist[h*W+w] + 1);
        }
    }
    for(int h = H - 1; h >= 0; h--) {
        for(int w = 0; w + 1 < W; w++) {
            if(h-1>=0) chmin(dist[(h-1)*W+w+1], dist[h*W+w] + 1);
        }
        for(int w = W - 1; w >= 1; w--) {
            if(h-1>=0) chmin(dist[(h-1)*W+w-1], dist[h*W+w] + 1);
        }
    }
    for(int w = 0; w < W; w++) {
        for(int h = 0; h + 1 < H; h++) {
            chmin(dist[(h+1)*W+w], dist[h*W+w] + 1);
        }
        for(int h = H - 1; h >= 1; h--) {
            chmin(dist[(h-1)*W+w], dist[h*W+w] + 1);
        }
    }
    /*
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) cerr << dist[h][w] << " ";
        cerr << endl;
    }
    ll ansT = INF;
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            if(dist[h][w] == 0) continue;
            bool ok = false;
            for(int newh = h - 1; newh <= h + 1; newh++) {
                for(int neww = w - 1; neww <= w + 1; neww++) {
                    if(dist[newh][neww] > dist[h][w]) ok = true;
                }
            }
            if(!ok) chmin(ansT, dist[h][w] - 1);
        }
    }
    */
    ll ok = 0;
    ll ng = H + W;
    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if(f(mid)) ok = mid;
        else ng = mid;
    }
    ll ansT = ok;
    cout << ansT << endl;
    for(int h = 1; h < H - 1; h++) {
        for(int w = 1; w < W - 1; w++) {
            if(dist[h*W+w] >= ansT + 1) cout << "X";
            else cout << ".";
        }
        cout << endl;
    }
    return 0;
}