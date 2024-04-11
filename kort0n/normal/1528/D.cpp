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

const long long INF = 1e18;
//const ll mod = 1000000007;
ll N, M;
bool checked[700];
ll c[700][700];
ll dist[700];
void f(int s) {
    for(int i = 0; i <= N; i++) {
        checked[i] = false;
        dist[i] = INF;
    }
    dist[N] = 0;
    for(int i = 0; i < N; i++) {
        c[N][i] = c[s][i];
    }
    for(int t = 0; t <= N; t++) {
        int now = -1;
        ll mini = INF;
        for(int i = 0; i <= N; i++) {
            if(checked[i]) continue;
            if(chmin(mini, dist[i])) now = i;
        }
        //cerr << t << " " << now << endl;
        checked[now] = true;
        if(now != N) {
            chmin(dist[(now+1)%N], dist[now] + 1);
        }
        int to = dist[now] % N;
        to--;
        for(int j = 0; j < N; j++) {
            to++;
            if(to == N) to = 0;
            if(c[now][j] == -1) continue;
            chmin(dist[to], dist[now] + c[now][j]);
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            c[i][j] = -1;
        }
    }
    for(int m = 0; m < M; m++) {
        int a, b, w;
        cin >> a >> b >> w;
        c[a][b] = w;
    }
    for(int i = 0; i < N; i++) {
        f(i);
        dist[i] = 0;
        for(int j = 0; j < N; j++) {
            if(j != 0) cout << " ";
            cout << dist[j];
        }
        cout << endl;
    }
    return 0;
}