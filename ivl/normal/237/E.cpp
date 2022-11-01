#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector < int > veze[205];
int dirw[205][205];
int pt, source, sink;
void add_edge(int pt1, int pt2, int w){
     //printf("%d %d %d\n", pt1, pt2, w);
     veze[pt1].push_back(pt2);
     veze[pt2].push_back(pt1);
     dirw[pt1][pt2] = w;
     dirw[pt2][pt1] = 0;
}
void init(){
     pt = 200;
     source = 0;
     sink = 1;
}
bool dbio[205];
vector < int > path;
bool flow_dfs(int pos){
     if (dbio[pos]++) return false;
     path.push_back(pos);
     if (pos == sink) return true;
     for (int i = 0; i < veze[pos].size(); ++i){
         int nxt = veze[pos][i];
         if (dirw[pos][nxt]) if (flow_dfs(nxt)) return true;
     }
     path.pop_back();
     return false;
}
bool flow_dfs(){
     for (int i = 0; i <= pt; ++i) dbio[i] = false;
     path.clear();
     return flow_dfs(source);
}
int flow(){
    int r = 0;
    while (flow_dfs()){
          int cr = 1000000000;
          for (int i = 0; i < path.size() - 1; ++i) cr = min(cr, dirw[path[i]][path[i + 1]]);
          for (int i = 0; i < path.size() - 1; ++i){
              dirw[path[i]][path[i + 1]] -= cr;
              dirw[path[i + 1]][path[i]] += cr;
          }
          r += cr;
    }
    return r;
}
char t[105];
int n;
char s[105][105];
int a[105];

int cnt[30];

int main(){
    init();
    scanf("%s%d", t, &n);
    for (int i = 0; i < n; ++i) scanf("%s%d", s[i], a + i);
    int l = 0;
    while (t[l] != '\0') ++l;
    int ll = l;
    for (int i = 0; i < l; ++i) ++cnt[t[i] - 'a'];
    for (int i = 0; i < 26; ++i){add_edge(source, i + 2, cnt[i]); cnt[i] = 0;}
    for (int i = 0; i < n; ++i){
        l = 0;
        while (s[i][l] != '\0') ++l;
        for (int j = 0; j < l; ++j) ++cnt[s[i][j] - 'a'];
        for (int j = 0; j < 26; ++j){add_edge(j + 2, i + 28, cnt[j]); cnt[j] = 0;}
    }
    int r = 0, rr = 0;
    for (int i = 0; i < n; ++i){
        add_edge(i + 28, sink, a[i]);
        int cr = flow();
        r += (i + 1) * cr;
        rr += cr;
    }
    if (rr != ll) printf("-1\n");
    else printf("%d\n", r);
    return 0;
}