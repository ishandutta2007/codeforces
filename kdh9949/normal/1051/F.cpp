#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define X first
#define Y second

const int N = 100005, K = 23;
const ll INF = ll(1e18);

int n, m, q, cnt, ccnt, p[2 * K], sp[N][K], v[N];
vector<pii> e[N], t[N];
ll ad[2 * K][2 * K], dep[N], dp[N], d[2 * K];

void g(int x, int y){
    v[x] = ++ccnt;
    for(pii i : e[x]){
        if(i.X == y) continue;
        if(!v[i.X]){
            t[x].push_back(i);
            g(i.X, x);
        }
        else if(v[i.X] < v[x]){
            cnt += 2;
            p[cnt - 2] = x;
            p[cnt - 1] = i.X;
            ad[cnt - 2][cnt - 1] = ad[cnt - 1][cnt - 2] = i.Y;
        }
    }
}

void f(int x, int y, int z, ll d){
    dep[x] = d;
    dp[x] = z;
    sp[x][0] = y;
    for(int i = 1; i < K; i++) sp[x][i] = sp[sp[x][i - 1]][i - 1];
    for(pii i : t[x]){
        if(i.X == y) continue;
        f(i.X, x, z + 1, d + i.Y);
    }
}

ll l(int x, int y){
    if(dp[x] < dp[y]) swap(x, y);
    ll dx = dep[x], dy = dep[y];
    for(int i = K - 1; i >= 0; i--){
        if(dp[x] - (1 << i) >= dp[y]) x = sp[x][i];
    }
    if(x == y) return dx - dep[x];
    for(int i = K - 1; i >= 0; i--){
        if(sp[x][i] != sp[y][i]){
            x = sp[x][i];
            y = sp[y][i];
        }
    }
    return dx + dy - 2 * dep[sp[x][0]];
}

ll di(int x, int y){
    fill(d, d + cnt, INF);
    fill(v, v + cnt, 0);
    d[x] = 0;
    for(int c = x; ; ){
        if(c == y) return d[c];
        v[c] = 1;
        for(int i = 0; i < cnt; i++) d[i] = min(d[i], d[c] + ad[c][i]);
        int mi = -1;
        for(int i = 0; i < cnt; i++)
            if(!v[i] && (mi == -1 || d[i] < d[mi])){ mi = i; }
        c = mi;
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0, x, y, z; i < m; i++){
        scanf("%d%d%d", &x, &y, &z);
        e[x].push_back({y, z});
        e[y].push_back({x, z});
    }
    for(int i = 0; i < 2 * K; i++){ fill(ad[i], ad[i] + 2 * K, INF); ad[i][i] = 0; }
    g(1, 0);
    f(1, 0, 0, 0);
    for(int i = 0; i < cnt; i++){
        for(int j = i + 1; j < cnt; j++){
            ad[i][j] = ad[j][i] = min(ad[i][j], l(p[i], p[j]));
        }
    }
    scanf("%d", &q);
    cnt += 2;
    for(int x, y; q--; ){
        scanf("%d%d", &x, &y);
        p[cnt - 2] = x;
        p[cnt - 1] = y;
        for(int i = 0; i < cnt - 2; i++){
            ad[i][cnt - 2] = ad[cnt - 2][i] = l(p[i], x);
            ad[i][cnt - 1] = ad[cnt - 1][i] = l(p[i], y);
        }
        ad[cnt - 2][cnt - 1] = ad[cnt - 1][cnt - 2] = l(x, y);
        printf("%lld\n", di(cnt - 2, cnt - 1));
    }
}