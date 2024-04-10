#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m, k, s;
int a[2005][2005];
int q[100005];

int dis[20][20];

bool bio[2005][2005];
int memo[2005][2005];
int memo2[2005][2005];
void bfs(int x){
     for (int i = 0; i < n; ++i){
         for (int j = 0; j < m; ++j){
             bio[i][j] = false;
             memo[i][j] = -1;
             memo2[i][j] = -1;
         }
     }
     
     for (int i = 0; i < n; ++i){
         //obrada retka/stupca
         int cr = -1;
         for (int j = 0; j < m; ++j){
             if (a[i][j] == x){cr = j; break;}
         }
         if (cr == -1) continue;
         for (int j = 0; j < m; ++j){
             memo[i][j] = abs(cr - j);
         }
         for (int j = m - 1; j + 1; --j){
             if (a[i][j] == x){cr = j; break;}
         }
         for (int j = 0; j < m; ++j){
             memo[i][j] = max(memo[i][j], abs(cr - j));
         }
     }
     
     for (int j = 0; j < m; ++j){ //obrada ostalog
         
         int last = -1;
         for (int i = 0; i < n; ++i){
             if (memo[i][j] > last) last = memo[i][j];
             if (last == -1) continue;
             memo2[i][j] = last++;
         }
         
         last = -1;
         for (int i = n - 1; i + 1; --i){
             if (memo[i][j] > last) last = memo[i][j];
             if (last == -1) continue;
             memo2[i][j] = max(memo2[i][j], last++);
         }
         
     }
     
     for (int i = 0; i < n; ++i){
         for (int j = 0; j < m; ++j){
             int y = a[i][j];
             dis[x][y] = max(dis[x][y], memo2[i][j]);
         }
     }
}

int main(){
    scanf("%d%d%d%d", &n, &m, &k, &s);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            scanf("%d", a[i] + j);
        }
    }
    for (int i = 0; i < s; ++i) scanf("%d", q + i);
    for (int i = 1; i <= k; ++i) bfs(i);
    int rez = -1;
    for (int i = 0; i < s - 1; ++i){
        rez = max(rez, dis[q[i]][q[i + 1]]);
        rez = max(rez, dis[q[i + 1]][q[i]]);
    }
    printf("%d\n", rez);
    return 0;
}