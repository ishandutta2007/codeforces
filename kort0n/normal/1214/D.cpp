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
int H, W;
string S[1050000];
vector<int> field[1050000];
vector<int> field2[1050000];

void dfs2(int h, int w) {
    if(h < 0 || w < 0) return;
    if(S[h][w] == '#') return;
    if(field2[h][w]) return;
    field2[h][w] = 1;
    dfs2(h-1, w);
    dfs2(h,w-1);
}
void dfs(int h, int w) {
    if(h >= H || w >= W) return;
    if(S[h][w] == '#') return;
    if(field[h][w]) return;
    field[h][w] = 1;
    dfs(h+1, w);
    dfs(h,w+1);
}

int main() {
    cin >> H >> W;
    for(int h = 0; h < H; h++) {
        cin >> S[h];
        field[h].resize(W);
        field2[h].resize(W);
    }
    dfs(0, 0);
    dfs2(H-1, W-1);
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            chmin(field[h][w], field2[h][w]);
            //cerr << field[h][w] << " ";
        }
        //cerr << endl;
    }
    int ans = 2;
    for(int x = 1; x < H + W - 2; x++) {
        int now = 0;
        for(int h = max(0, x - W + 1); h < H; h++) {
            int w = x - h;
            if(w < 0) break;
           // cerr << h << " " << w << " " << field[h][w] << endl;
            if(field[h][w]) now++;
        }
        //cerr << x << " " << now << endl;
        chmin(ans, now);
    }
    cout << ans << endl;
    return 0;
}