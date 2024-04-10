#include <cstdio>
#include <vector>
#define x first
#define y second

using namespace std;

int n;
vector < pair < int, int > > veze[100005];
int w[100005];
int tmp[100005];

int ss[100005], sse[100005];
void dfs(int pos, int par){
     ss[pos] = 1;
     for (int i = 0; i < veze[pos].size(); ++i){
         int nxt = veze[pos][i].x;
         if (nxt == par) continue;
         dfs(nxt, pos);
         ss[pos] += ss[nxt];
         sse[veze[pos][i].y] = ss[nxt];
     }
}

long double pov(long double x){return x * (x - 1) * (x - 2) / 6.0;}
long double exp;
void add(int edge, int val){
     long double x = val - w[edge];
     exp += 2.0 * x * (pov(ss[1]) - pov(sse[edge]) - pov(ss[1] - sse[edge])) / pov(ss[1]);
     w[edge] = val;
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i){
        int a, b, l; scanf("%d%d%d", &a, &b, &l);
        veze[a].push_back(make_pair(b, i));
        veze[b].push_back(make_pair(a, i));
        tmp[i] = l;
    }
    dfs(1, -1);
    for (int i = 0; i < n - 1; ++i) add(i, tmp[i]);
    int q; scanf("%d", &q);
    for (int i = 0; i < q; ++i){
        int r, w; scanf("%d%d", &r, &w); --r;
        add(r, w);
        printf("%.9lf\n", (double)exp);
    }
    return 0;
}