#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define x first
#define y second

const int N = 100005, L = 17, M = int(1e9) + 7;

int n, m, dig[N], d[N], dep[N], p[L][N], ten[L];
string ps[N];
vector<pair<int, pair<int, string>>> e[N], ee[N];
vector<int> tord;
priority_queue<pii, vector<pii>, greater<pii>> pq;

int pv(int x, int z){
    int dd = dep[x] - dep[z] - 1;
    for(int i = 0; i < L; i++) if((dd >> i) & 1) x = p[i][x];
    return x;
}

int lca(int x, int y){
    if(dep[x] < dep[y]) swap(x, y);
    int dd = dep[x] - dep[y];
    for(int i = 0; i < L; i++) if((dd >> i) & 1) x = p[i][x];
    if(x == y) return x;
    for(int i = L-1; i >= 0; i--) if(p[i][x] != p[i][y]){
        x = p[i][x];
        y = p[i][y];
    }
    return p[0][x];
}

int cmp(int x, string xl, int y, string yl){
    int z = lca(x, y);
    vector<char> xv, yv;
    int xs = 0, ys = 0;
    int xx = z, yy = z;
    while(xx >= 0 || yy >= 0){
        if(xs < ys){
            xx = (x != xx ? pv(x, xx) : -1);
            string cs = (xx >= 0 ? ps[xx] : xl);
            for(char i : cs){
                xv.push_back(i); xs++;
                if(xs <= ys && xv[xs-1] != yv[xs-1]) return (xv[xs-1] < yv[xs-1]);
            }
        }
        else{
            yy = (y != yy ? pv(y, yy) : -1);
            string cs = (yy >= 0 ? ps[yy] : yl);
            for(char i : cs){
                yv.push_back(i); ys++;
                if(ys <= xs && xv[ys-1] != yv[ys-1]) return (xv[ys-1] < yv[ys-1]);
            }
        }
    }
    return 0;
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1, x, y; i <= m; i++){
        cin >> x >> y;
        e[x].push_back(make_pair(y, make_pair(i, to_string(i))));
        e[y].push_back(make_pair(x, make_pair(i, to_string(i))));
    }
    dig[1] = 0;
    fill(dig + 2, dig + n + 1, M);
    pq.push(pii(0, 1));
    while(!pq.empty()){
        pii c = pq.top(); pq.pop();
        if(c.x != dig[c.y]) continue;
        tord.push_back(c.y);
        for(auto &i : e[c.y]){
            int nd = dig[c.y] + i.y.y.length();
            if(dig[i.x] < nd) continue;
            if(dig[i.x] > nd) ee[i.x].clear();
            ee[i.x].push_back(make_pair(c.y, i.y));
            if(dig[i.x] > nd){
                dig[i.x] = nd;
                pq.push(pii(nd, i.x));
            }
        }
    }
    ten[0] = 1;
    for(int i = 1; i < L; i++) ten[i] = ten[i - 1] * 10LL % M;
    for(int i : tord){
        if(i == 1) continue;
        auto t = ee[i][0];
        for(int j = 1; j < ee[i].size(); j++){
            if(cmp(ee[i][j].x, ee[i][j].y.y, t.x, t.y.y)) t = ee[i][j];
        }
        d[i] = (1LL * d[t.x] * ten[t.y.y.length()] + t.y.x) % M;
        p[0][i] = t.x;
        dep[i] = dep[t.x] + 1;
        ps[i] = t.y.y;
        for(int j = 1; j < L; j++) p[j][i] = p[j - 1][p[j - 1][i]];
    }
    for(int i = 2; i <= n; i++) cout << d[i] << '\n';
}