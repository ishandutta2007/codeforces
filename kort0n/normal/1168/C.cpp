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

const long long INF = 1e9;
//const ll mod = 1000000007;
int N, Q;
int a[301000];
int nxt[300001][200];
int dist[20];
bool visited[20];
int g[20][20];
bool f(int l, int r) {
    for(int i = 0; i < 20; i++) {
        dist[i] = INF;
        visited[i] = false;
        if(a[l] & (1 << i)) dist[i] = l;
    }
    while(true) {
        int to = -1;
        for(int i = 0; i < 20; i++) {
            if(visited[i]) continue;
            if(to == -1 or dist[to] > dist[i]) to = i;
        }
        if(to == -1) break;
        if(dist[to] > r) break;
        visited[to] = true;
        for(int i = 0; i < 20; i++) {
            if(i == to) continue;
            chmin(dist[i], nxt[dist[to]][g[to][i]]);
        }
    }
    for(int i = 0; i < 20; i++) {
        if(dist[i] <= r and (a[r] & (1 << i))) return true;
    }
    return false;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> Q;
    int tmp = 0;
    for(int i = 0; i < 20; i++) {
        g[i][i] = -1;
        for(int j = 0; j < i; j++) {
            g[i][j] = tmp;
            tmp++;
        }
    }
    for(int i = 0; i < 20; i++) {
        for(int j = i + 1; j < 20; j++) {
            g[i][j] = g[j][i];
        }
    }
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        for(int j = 0; j < 20; j++) {
            for(int k = 0; k < j; k++) {
                nxt[i][g[j][k]] = INF;
                if((a[i] & (1 << j)) and (a[i] & (1 << k))) nxt[i][g[j][k]] = i;
            }
        }
    }
    for(int i = N - 2; i >= 0; i--) {
        for(int j = 0; j < 20; j++) {
            for(int k = 0; k < j; k++) {
                chmin(nxt[i][g[j][k]], nxt[i+1][g[j][k]]);
            }
        }
    }
    for(int q = 0; q < Q; q++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if(f(l, r)) cout << "Shi" << endl;
        else cout << "Fou" << endl;
    }
    return 0;
}