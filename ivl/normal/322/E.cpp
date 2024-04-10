#include <cstdio>
#include <vector>
#define x first
#define y second

using namespace std;

char out[100005];

int n;
vector < pair < int, int > > vz;

vector < int > veze[100005];
int cnt[100005], par[100005];
int dfs(int pos){
    int &r = cnt[pos];
    r = 1;
    for (int i = 0; i < veze[pos].size(); ++i)
    if (veze[pos][i] != par[pos]){
       par[veze[pos][i]] = pos;
       r += dfs(veze[pos][i]);
    }
    return r;
}
vector < int > vpts;
vector < pair < int, int > > vsk;
int par2[100005];
void dfs2(int pos){
     vpts.push_back(pos);
     for (int i = 0; i < veze[pos].size(); ++i)
     if (veze[pos][i] != par2[pos]){
        vsk.push_back(make_pair(pos, veze[pos][i]));
        par2[veze[pos][i]] = pos;
        dfs2(veze[pos][i]);
     }
}
void color(vector < int > pts, vector < pair < int, int > > sk, char rank = 'A'){
     //printf("A");
     if (pts.size() == 1){out[pts[0]] = rank; return;}
     for (int i = 0; i < pts.size(); ++i){/*printf("%d ", pts[i]); */veze[pts[i]].clear(); cnt[pts[i]] = par[pts[i]] = 0;}
     //printf("\n");
     for (int i = 0; i < sk.size(); ++i){veze[sk[i].x].push_back(sk[i].y); veze[sk[i].y].push_back(sk[i].x);}
     //printf("A");
     dfs(pts[0]);
     //printf("A");
     int sp = pts[0], smin = 1000000000;
     for (int i = 0; i < pts.size(); ++i){
         int cr = pts.size() - cnt[pts[i]];
         for (int j = 0; j < veze[pts[i]].size(); ++j)
         if (veze[pts[i]][j] != par[pts[i]])
            cr = max(cr, cnt[veze[pts[i]][j]]);
         if (cr < smin){smin = cr; sp = pts[i];}
     }
     //printf("A");
     out[sp] = rank;
     vector < pair < vector < int >, vector < pair < int, int > > > > V;
     for (int i = 0; i < veze[sp].size(); ++i){
         par2[veze[sp][i]] = sp;
         dfs2(veze[sp][i]);
         V.push_back(make_pair(vpts, vsk));
         vpts.clear();
         vsk.clear();
     }
     //printf("A");
     for (int i = 0; i < V.size(); ++i) color(V[i].x, V[i].y, rank + 1);
}

int main(){
    scanf("%d", &n);
    vector < int > vv;
    for (int i = 1; i < n; ++i){
        int a, b;
        vv.push_back(i);
        scanf("%d%d", &a, &b);
        vz.push_back(make_pair(a, b));
    }
    vv.push_back(n);
    color(vv, vz, 'A');
    for (int i = 1; i <= n; ++i) printf("%c ", out[i]);
    printf("\n");
    return 0;
}