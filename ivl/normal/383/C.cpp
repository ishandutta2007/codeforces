#include <cstdio>
#include <vector>
#define x first
#define y second

using namespace std;

const int oo = 1000000000;

int n, m;
int a[200005];

vector < int > veze[200005];
int color[200005];
bool bio[200005];
pair < int, int > in[2][200005];

int disc[200005];
int dcnt;

void dfs(int pos, int c){
     bio[pos] = true;
     color[pos] = c;
     disc[pos] = dcnt++;
     in[c][pos] = make_pair(disc[pos], disc[pos]);
     in[1 - c][pos] = make_pair(oo, -oo);
     for (int i = 0; i < veze[pos].size(); ++i){
         int x = veze[pos][i];
         if (bio[x]) continue;
         dfs(x, 1 - c);
         for (int j = 0; j < 2; ++j){
             in[j][pos].x = min(in[j][pos].x, in[j][x].x);
             in[j][pos].y = max(in[j][pos].y, in[j][x].y);
         }
     }
}

int t0[1 << 19], t1[1 << 19], l0[1 << 19], l1[1 << 19], slo, shi, sval;

void update(int *tur, int *lazy, int pos, int lo, int hi){
     lazy[pos * 2] += lazy[pos];
     lazy[pos * 2 + 1] += lazy[pos];
     tur[pos * 2] += lazy[pos];
     tur[pos * 2 + 1] += lazy[pos];
     lazy[pos] = 0;
}

void add(int *tur, int *lazy, int pos = 1, int lo = 0, int hi = (1 << 18) - 1){
     if (lo > shi || hi < slo) return;
     if (lo >= slo && hi <= shi){
        tur[pos] += sval;
        lazy[pos] += sval;
        return;
     }
     update(tur, lazy, pos, lo, hi);
     add(tur, lazy, pos * 2, lo, (lo + hi) >> 1);
     add(tur, lazy, pos * 2 + 1, (lo + hi + 1) >> 1, hi);
}

int calc(int *tur, int *lazy, int pos = 1, int lo = 0, int hi = (1 << 18) - 1){
    if (lo > shi || hi < slo) return 0;
    if (lo == hi) return tur[pos];
    update(tur, lazy, pos, lo, hi);
    return calc(tur, lazy, pos * 2, lo, (lo + hi) >> 1) + calc(tur, lazy, pos * 2 + 1, (lo + hi + 1) >> 1, hi);
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < n - 1; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        --y;
        veze[x].push_back(y);
        veze[y].push_back(x);
    }
    dfs(0, 0);
    //for (int i = 0; i < n; ++i) printf("%d %d %d %d\n", in[0][i].x, in[0][i].y, in[1][i].x, in[1][i].y);
    //printf("\n");
    for (int i = 0; i < m; ++i){
        int c;
        scanf("%d", &c);
        if (c == 1){
           int x, y;
           scanf("%d%d", &x, &y);
           --x;
           slo = in[0][x].x;
           shi = in[0][x].y;
           sval = y;
           if (color[x]) sval = -y;
           add(t0, l0);
           sval = -sval;
           slo = in[1][x].x;
           shi = in[1][x].y;
           add(t1, l1);
        }
        else {
             int x;
             scanf("%d", &x);
             --x;
             slo = shi = disc[x];
             int y;
             if (color[x]) y = calc(t1, l1);
             else y = calc(t0, l0);
             printf("%d\n", a[x] + y);
        }
    }
    return 0;
}