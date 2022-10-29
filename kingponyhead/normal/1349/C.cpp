# include<bits/stdc++.h>

using namespace std;

const int N = 1000 + 77;

struct DSU {
   int P[N * N];
   inline void __init() { memset(P , -1 , sizeof P); }
   int Find(int x) { return P[x] <= 0 ? x : (P[x] = Find(P[x])); }
   inline bool Merge(int v , int u) {
      v = Find(v); u = Find(u);
      if(v == u) return 0;
      if(P[v] < P[u]) swap(v , u);
      P[u] += P[v];
      P[v] = u;
      return 1;
   }
};

DSU D;
int n , m , q;
char S[N][N];
vector < int > adj[N * N];
int d[N * N];
int main() {
   memset(d , 63 , sizeof d);
   D.__init();
   scanf("%d %d %d" , & n , & m , & q);
   for(int i = 1;i <= n;++ i)
      scanf("%s" , S[i] + 1);

   for(int i = 1;i <= n;++ i)
      for(int j = 1;j <= m;++ j) {
         if(i > 1) {
            if(S[i][j] == S[i - 1][j])
               D.Merge((i - 1) * m + j , (i - 2) * m + j);
         }
         if(j > 1) {
            if(S[i][j] == S[i][j - 1])
               D.Merge((i - 1) * m + j , (i - 1) * m + j - 1);
         }
      }

   for(int i = 1;i <= n;++ i)
      for(int j = 1;j <= m;++ j) {
         if(i > 1) {
            int v = D.Find((i - 1) * m + j);
            int u = D.Find((i - 2) * m + j);
            adj[v].push_back(u);
            adj[u].push_back(v);
         }
         if(j > 1) {
            int v = D.Find((i - 1) * m + j);
            int u = D.Find((i - 1) * m + j - 1);
            adj[v].push_back(u);
            adj[u].push_back(v);
         }
      }

   queue < int > dq;
   for(int i = 1;i <= n;++ i)
      for(int j = 1;j <= m;++ j) {
         int c = (i - 1) * m + j;
         if(D.P[c] < -1)
            d[c] = 0 , dq.push(c);
      }
   while(! dq.empty()) {
      int v = dq.front();
      dq.pop();
      for(int u : adj[v])
         if(d[u] > d[v] + 1)
            d[u] = d[v] + 1 , dq.push(u);
   }
   const int inf = n * m + 100;
   while(q --) {
      int x , y;
      long long c;
      scanf("%d %d %lld" , & x , & y , & c);
      int p = D.Find((x - 1) * m + y);
      if(d[p] >= inf) {
         printf("%c\n" , S[x][y]);
      } else {
         if(c <= d[p])
            printf("%c\n" , S[x][y]);
         else {
            c -= d[p];
            if(c & 1) {
               if(S[x][y] == '0')
                  printf("1\n");
               else
                  printf("0\n");
            } else {
               printf("%c\n" , S[x][y]);
            }
         }
      }
   }



   return 0;
}