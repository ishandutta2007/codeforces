// KINGPONYHEAD
# include<bits/stdc++.h>

using namespace std;

const int N = 500000 + 77 , Mod = 1000000007;
vector < int > all;
struct DSU {
   int P[N] , C[N];
   inline void __init() {
      memset(P , -1 , sizeof P);
      memset(C , 63 , sizeof C);
   }
   int Find(int x) { return P[x] <= 0 ? x : (P[x] = Find(P[x])); }
   inline bool Merge(int v , int u , int id) {
      v = Find(v); u = Find(u);
      if(v == u) return 0;
      all.push_back(id);
      if(P[v] < P[u]) swap(v , u);
      C[u] = min(C[u] , C[v]);
      P[u] += P[v];
      P[v] = u;
      return 1;
   }
} D;

int n , m , P2[N];
int ans = 1;
inline void Test() {
   D.__init();
   scanf("%d %d" , & m  , & n);
   for(int sz , v , u , i = 1;i <= m;++ i) {
      scanf("%d %d" , & sz , & v);
      if(sz == 1) {
         D.C[D.Find(v)] = min(D.C[D.Find(v)] , i);
      } else {
         scanf("%d" , & u);
         if(D.C[D.Find(v)] <= m && D.C[D.Find(u)] <= m)
            continue ;
         D.Merge(v , u , i);
      }
   }
   for(int i = 1;i <= n;++ i)
      if(D.Find(i) == i) {
         int pw = - D.P[i] - (D.C[i] > m);
         ans = ans * 1ll * P2[pw] % Mod;
         if(D.C[i] <= m)
            all.push_back(D.C[i]);
      }

   sort(all.begin() , all.end());
   printf("%d %d\n" , ans , (int) all.size());
   for(int x : all)
      printf("%d " , x);
   printf("\n");

}
int main() {
   P2[0] = 1;
   for(int i = 1;i < N;++ i)
      P2[i] = P2[i - 1] * 2ll % Mod;
   int te = 1;
   //scanf("%d"  ,& te);
   while(te --)
      Test();
   return 0;
}