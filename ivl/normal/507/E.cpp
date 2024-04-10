#include <cstdio>
#include <vector>
#include <set>
#define x first
#define y second

using namespace std;

const int oo = 1000000000;

class edge{
      public:
      int x, y, z;
      edge(int _x = 0, int _y = 0, int _z = 0) : x(_x), y(_y), z(_z){}
};

int n, m;
edge E[100005];
vector < int > veze[100005];

int back[100005];
pair < int, int > best[100005];
void dijkstra(int start){
     
     for (int i = 0; i <= 100003; ++i) best[i] = make_pair(oo, oo);
     best[start] = make_pair(0, 0);
     
     static set < pair < pair < int, int >, int > > S;
     S.insert(make_pair(best[start], start));
     while (!S.empty()){
           int x = S.begin()->y;
           S.erase(S.begin());
           for (int i = 0; i < veze[x].size(); ++i){
               int id = veze[x][i];
               int y, z;
               z = E[id].z;
               if (E[id].x != x) y = E[id].x; else y = E[id].y;
               
               if (best[y].x < best[x].x + 1) continue;
               if (best[y].x == best[x].x + 1 && best[y].y <= best[x].y + z) continue;
               
               S.erase(make_pair(best[y], y));
               best[y] = make_pair(best[x].x + 1, best[x].y + z);
               back[y] = id;
               S.insert(make_pair(best[y], y));
               
           }
     }
}

bool good[100005];

int main(){
    scanf("%d%d", &n, &m);
    int cnt = 0;
    for (int i = 0; i < m; ++i){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        veze[x].push_back(i);
        veze[y].push_back(i);
        z = 1 - z;
        cnt += z;
        E[i] = edge(x, y, z);
    }
    dijkstra(n);
    
    pair < int, int > p = best[1];
    printf("%d\n", m - cnt - p.x + p.y + p.y);
    
    int pos = 1;
    while (pos != n){
          //printf(" .. %d\n", back[pos]);
          good[back[pos]] = true;
          pos = E[back[pos]].x + E[back[pos]].y - pos;
    }
    
    for (int i = 0; i < m; ++i){
        if (good[i] && E[i].z == 0 || !good[i] && E[i].z == 1) continue;
        printf("%d %d %d\n", E[i].x, E[i].y, E[i].z);
    }
    
    return 0;
}