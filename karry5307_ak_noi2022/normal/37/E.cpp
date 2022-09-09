#include<bits/stdc++.h>
using namespace std;
#define id(x,y) ((x)*(m+2)+(y))
int c[3010], w[4],fi[3010],tot;
struct edge {
    int nx, to, w;
}e[12001];
void ps(int x, int y, int z) {
    // cout << x << ' ' << y << ' ' << z << endl;
    e[++tot] = (edge){ fi[x],y,z };
    fi[x] = tot;
}
int vod[3010],d[3010],p;
priority_queue<pair<int, int> >q;
void dij(int s) {
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;p = s;
    q.push(make_pair(0, s));
    while (q.size()) {
        int x = q.top().second, g = (q.top().first == -d[x]);
        // cout << x << endl;
        q.pop();if (!g)continue;
        if (d[p] < d[x])p = x;
        for (int i = fi[x], y;(y = e[i].to);i = e[i].nx) {
            if (d[y] > d[x] + e[i].w) {
                d[y] = d[x] + e[i].w;
                q.push(make_pair(-d[y], y));
            }
        }
    }
}
int main() {
    int n,m,t=0;
    scanf("%d%d", &n, &m);
    memset(c, -1, sizeof(c));
    w[0] = 1;w[1] = -1;w[2] = m + 2;w[3] = -m - 2;
    for (int i = 1;i <= n;i++)for (int j = 1;j <= m;j++) {
        char ch;
        scanf(" %c", &ch);
        c[id(i, j)] = (ch == 'B');
        vod[++t] = id(i, j);
    }
    for (int i = 1;i <= t;i++) {
        for (int j = 0;j < 4;j++) if(c[vod[i]+w[j]]!=-1){
            ps(vod[i], vod[i] + w[j], c[vod[i]] ^ c[vod[i] + w[j]]);
        }
    }
    int ans = 1e9;
    for (int i = 1;i <= t;i++) {
        dij(vod[i]);
        // cout << vod[i] << ' '<<p<<' '<<d[p]<<c[p]<<endl;
        ans = min(ans, d[p] + c[p]);
    }
    printf("%d\n", ans);
}