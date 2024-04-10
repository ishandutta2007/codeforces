#include <cstdio>
#include <vector>

using namespace std;

int n, m;
vector < int > veze[100005];

int prt[100005];

vector < int > ch[100005];
int par[100005];
bool bio[100005];
void dfs(int pos, int pr){
     par[pos] = pr;
     bio[pos] = true;
     for (int i = 0; i < veze[pos].size(); ++i){
         int nxt = veze[pos][i];
         if (bio[nxt]) continue;
         ch[pos].push_back(nxt);
         dfs(nxt, pos);
     }
}

vector < int > path;
void add(int pos){
     path.push_back(pos + 1);
     prt[pos] = 1 - prt[pos];
}
void create(int pos){
     add(pos);
     for (int i = 0; i < ch[pos].size(); ++i){
         create(ch[pos][i]);
         add(pos);
     }
     if (prt[pos] == 0) return;
     if (par[pos] == -1){
        int x = ch[pos][0];
        add(x);
        add(pos);
        add(x);
        return;
     }
     int x = par[pos];
     add(x);
     add(pos);
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        veze[a - 1].push_back(b - 1);
        veze[b - 1].push_back(a - 1);
    }
    int p = -1;
    for (int i = 0; i < n; ++i){
        scanf("%d", prt + i);
        if (prt[i]) p = i;
    }
    if (p == -1){printf("0\n"); return 0;}
    dfs(p, -1);
    for (int i = 0; i < n; ++i) if (prt[i] == 1 && !bio[i]){printf("-1\n"); return 0;}
    create(p);
    printf("%d\n", path.size());
    for (int i = 0; i < path.size(); ++i) printf("%d ", path[i]);
    printf("\n");
    return 0;
}