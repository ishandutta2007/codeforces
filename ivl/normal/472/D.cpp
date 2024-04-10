#include <cstdio>
#include <vector>
#include <algorithm>
#define x first
#define y second

using namespace std;

int n;
int d[2005][2005];
int id[2005];

bool cmp(int a, int b){return d[0][a] < d[0][b];}

vector < int > ch[2005]; // root = 0
bool poss = true;

vector < pair < int, int > > edges[2005];

void make_edge(int a, int b){
     //printf("(%d,%d) = %d\n", a, b, d[a][b]);
     edges[a].push_back(make_pair(b, d[a][b]));
     edges[b].push_back(make_pair(a, d[a][b]));
}

void add(int cr, int root = 0){
     //printf("(%d) [%d]\n", cr, root);
     if (ch[root].size() == 0){
        ch[root].push_back(cr);
        make_edge(cr, root);
        return;
     }
     int c1 = ch[root][0];
     for (int i = 0; i < ch[root].size(); ++i){
         int nxt = ch[root][i];
         if (d[cr][nxt] + d[nxt][root] == d[root][cr]){
            add(cr, nxt);
            return;
         }
     }
     if (d[c1][root] + d[root][cr] == d[c1][cr]){
        //printf("%d + %d = %d\n", d[c1][root], d[root][cr], d[c1][cr]);
        ch[root].push_back(cr);
        make_edge(root, cr);
        return;
     }
     poss = false;
}

long long rd[2005][2005];

int start;
bool bio[2005];
void dfs(int pos, long long cd){
     if (bio[pos]++) return;
     rd[start][pos] = cd;
     for (int i = 0; i < edges[pos].size(); ++i) dfs(edges[pos][i].x, cd + edges[pos][i].y);
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) scanf("%d", d[i] + j);
    for (int i = 0; i < n; ++i) if (d[i][i] != 0){printf("NO\n"); return 0;}
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (d[i][j] != d[j][i] || (i != j && d[i][j] == 0)){printf("NO\n"); return 0;}
    if (n == 1){printf("YES\n"); return 0;}
    for (int i = 1; i < n; ++i) id[i - 1] = i;
    sort(id, id + n - 1, cmp);
    for (int i = 0; i < n - 1; ++i) add(id[i]);
    if (!poss){printf("NO\n"); return 0;}
    //printf("A");
    //gen_fst();
    //gen_dis();
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j) bio[j] = false;
        start = i;
        dfs(i, 0);
    }
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (rd[i][j] != d[i][j]){printf("NO\n"); return 0;}
    printf("YES\n");
    return 0;
}