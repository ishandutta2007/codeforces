#include <cstdio>
#include <vector>
#define x first
#define y second

using namespace std;

inline int h(int a, int b){return a + 1002 * b;}
inline int h(pair < int, int > x){return h(x.x, x.y);}

int n, m;
int in[1005][1005];
int sx, sy = -1;

int ps[1005][1005];
int mat_sz(int x1, int y1, int x2, int y2){
    return ps[x2][y2] - ps[x1 - 1][y2] - ps[x2][y1 - 1] + ps[x1 - 1][y1 - 1];
}

vector < pair < int, int > > nodes;
int deg[1005][1005];
int gr[2000000], sz[2000000];
int un(int p){
    if (p == gr[p]) return p;
    return gr[p] = un(gr[p]);
}
void join(int a, int b){
     a = un(a);
     b = un(b);
     if (a == b) return;
     gr[a] = b;
     sz[b] += sz[a];
}

int main(){
    for (int i = 0; i < 2000000; ++i){sz[i] = 1; gr[i] = i;}
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j){
        scanf("%d", in[i] + j);
        if (sy == -1 && in[i][j] == 1){sx = i; sy = j;}
    }
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
    ps[i][j] = in[i][j] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
    bool ex = false;
    for (int k = 2; k <= max(n, m); ++k){
        for (int i = 0; i < nodes.size(); ++i){
            sz[h(nodes[i])] = 1;
            gr[h(nodes[i])] = h(nodes[i]);
            deg[nodes[i].x][nodes[i].y] = 0;
        }
        nodes.clear();
        for (int i = sx % k; i <= n; i += k)
        for (int j = sy % k; j <= m; j += k)
        if (in[i][j] == 1) nodes.push_back(make_pair(i, j));
        int cnt = nodes.size();
        for (int i = 0; i < nodes.size(); ++i){
            if (mat_sz(nodes[i].x, nodes[i].y, nodes[i].x + k, nodes[i].y) == k + 1){
               join(h(nodes[i]), h(nodes[i].x + k, nodes[i].y));
               cnt += k - 1;
               ++deg[nodes[i].x][nodes[i].y];
               ++deg[nodes[i].x + k][nodes[i].y];
            }
            if (mat_sz(nodes[i].x, nodes[i].y, nodes[i].x, nodes[i].y + k) == k + 1){
               join(h(nodes[i]), h(nodes[i].x, nodes[i].y + k));
               cnt += k - 1;
               ++deg[nodes[i].x][nodes[i].y];
               ++deg[nodes[i].x][nodes[i].y + k];
            }
        }
        //printf("[%d]", nodes.size());
        //printf("(%d)(%d,%d)", k, cnt, ps[n][m]);
        if (cnt < ps[n][m]) continue;
        //printf("(%d)", k);
        //printf("(%d,%d)", sz[un(h(sx, sy))], nodes.size());
        if (sz[un(h(sx, sy))] < nodes.size()) continue;
        //printf("(%d)", k);
        int ch = 0;
        for (int i = 0; i < nodes.size(); ++i) if (deg[nodes[i].x][nodes[i].y] % 2 == 1) ++ch;
        if (ch > 2) continue;
        if (nodes.size() == 1) continue;
        printf("%d ", k);
        ex = true;
    }
    if (!ex) printf("-1");
    printf("\n");
    return 0;
}