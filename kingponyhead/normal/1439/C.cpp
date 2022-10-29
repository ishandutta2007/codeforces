// KINGPONYHEAD
# include<bits/stdc++.h>
# define md ((l + r) >> 1)
# define lc (id << 1)
# define rc (lc ^ 1)
using namespace std;

const int N = 200000 + 77;
int n , q , a[N];
int lz[N << 2] , Mn[N << 2];
long long S[N << 2];
int gy , ansg;

void Shift(int l , int r , int id) {
   if(lz[id] == -1)
      return ;
   S[id] = lz[id] * 1ll * (r - l);
   Mn[id] = lz[id];
   if(r - l > 1)
      lz[lc] = lz[id] , lz[rc] = lz[id];
   lz[id] = -1;
}
void Set(int ql , int qr , int x , int l = 1 , int r = n + 1 , int id = 1) {
   Shift(l , r , id);
   if(qr <= l || r <= ql)
      return ;
   if(ql <= l && r <= qr) {
      lz[id] = x;
      Shift(l , r , id);
      return ;
   }
   Set(ql , qr , x , l , md , lc);
   Set(ql , qr , x , md , r , rc);
   S[id] = S[lc] + S[rc];
   Mn[id] = min(Mn[lc] , Mn[rc]);
}
int Find(int x , int l = 1 , int r = n + 1 , int id = 1) {
   Shift(l , r , id);
   if(r <= x)
      return r;
   if(x <= l && S[id] <= gy) {
      gy -= S[id];
      ansg += r - l;
      return r;
   }
   if(r - l < 2)
      return l;
   int idx = Find(x , l , md , lc);
   if(idx < md)
      return idx;
   return Find(x , md , r , rc);
}
int Find2(int x , int y , int l = 1 , int r = n + 1 , int id = 1) {
   Shift(l , r , id);
   if(r <= x || Mn[id] > y)
      return N;
   if(r - l < 2) {
      if(Mn[id] <= y)
         return l;
      return N;
   }
   int idx = Find2(x , y , l , md , lc);
   if(idx != N)
      return idx;
   return Find2(x , y , md , r , rc);
}
int main() {
   memset(lz , -1, sizeof lz);
   scanf("%d %d" , & n , & q);
   for(int i = 1;i <= n;++ i)
      scanf("%d" , a + i);
   for(int i = 1;i <= n;++ i)
      Set(i , i + 1 , a[i]);
   while(q --) {
      int t , x , y;
      scanf("%d %d %d" , & t , & x , & y);
      gy = ansg = 0;
      if(t == 2) {
         gy = y;
         while(1) {
            x = Find2(x , gy);
            if(x > n)
               break ;
            x = Find(x);
         }
         printf("%d\n" , ansg);
      } else {
         int nxt = Find2(1 , y);
         if(nxt <= x)
            Set(nxt , x + 1 , y);
      }
   }
   return 0;
}