#include <cstdio>
#include <vector>
#define x first
#define y second

using namespace std;

int n;

vector < int > veze[100005];

vector < int > node[200005];
vector < pair < int, int > > Tveze;
int cp = 1;

void dfs(int pos, int parc = -1, int par = -1){
     if (veze[pos].size() == 1) return;/*
     int curr;
     if (veze[pos].size() == 2) curr = parc;
     else {
          curr = cp++;
          node[curr].push_back(pos);
          if (parc != -1) Tveze.push_back(make_pair(curr, parc));
     }*/
     for (int i = 0; i < veze[pos].size(); ++i){
         int nxt = veze[pos][i];
         if (nxt == par) continue;
         int c_nxt = cp++;
         node[c_nxt].push_back(pos);
         node[c_nxt].push_back(nxt);
         if (parc != -1) Tveze.push_back(make_pair(parc, c_nxt));
         else if (c_nxt != 1) Tveze.push_back(make_pair(1, c_nxt));
         dfs(nxt, c_nxt, pos);
     }
}

void dfs2(int pos, int par = -1, int c_par = -1){
     for (int i = 0; i < veze[pos].size(); ++i){
         int nxt = veze[pos][i];
         if (nxt == par) continue;
         int curr = cp++;
         node[curr].push_back(pos);
         node[curr].push_back(nxt);
         if (c_par != -1) Tveze.push_back(make_pair(c_par, curr));
         dfs2(nxt, pos, curr);
     }
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i < n; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        veze[a].push_back(b);
        veze[b].push_back(a);
    }
    if (n == 1){
       printf("1\n1 1\n");
       return 0;
    }
    if (n == 2){
       printf("1\n2 1 2\n");
       return 0;
    }
    bool ch = true;
    for (int i = 1; i <= n; ++i) if (veze[i].size() > 2){dfs(i); ch = false; break;}
    if (ch){
       int p;
       for (int i = 1; i <= n; ++i) if (veze[i].size() == 1){p = i; break;}
       dfs2(p);
    }
    printf("%d\n", cp - 1);
    for (int i = 1; i < cp; ++i){
        printf("%d ", node[i].size());
        for (int j = 0; j < node[i].size(); ++j) printf("%d ", node[i][j]);
        printf("\n");
    }
    for (int i = 0; i < Tveze.size(); ++i) printf("%d %d\n", Tveze[i].x, Tveze[i].y);
    return 0;
}