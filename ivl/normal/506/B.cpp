#include <cstdio>
#include <vector>

using namespace std;

int n, m;
vector < int > veze[100005];
vector < int > veze2[100005];

vector < int > curr;
bool bio1[100005];
void dfs1(int pos){
     bio1[pos] = true;
     curr.push_back(pos);
     for (int i = 0; i < veze2[pos].size(); ++i){
         int nxt = veze2[pos][i];
         if (bio1[nxt]) continue;
         dfs1(nxt);
     }
}
int bio2[100005];
bool dfs2(int pos){
     bio2[pos] = 1;
     for (int i = 0; i < veze[pos].size(); ++i){
         int nxt = veze[pos][i];
         if (bio2[nxt] == 2) continue;
         if (bio2[nxt] == 1) return true;
         if (dfs2(nxt)) return true;
     }
     bio2[pos] = 2;
     return false;
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i){
        int a, b; scanf("%d%d", &a, &b);
        veze[a].push_back(b);
        veze2[a].push_back(b);
        veze2[b].push_back(a);
    }
    int r = 0;
    for (int i = 1; i <= n; ++i){
        if (bio1[i]) continue;
        dfs1(i);
        int cr = curr.size() - 1;
        for (int i = 0; i < curr.size(); ++i){
            int x = curr[i];
            if (bio2[x]) continue;
            if (dfs2(x)){++cr; break;}
        }
        r += cr;
        curr.clear();
    }
    printf("%d\n", r);
    return 0;
}