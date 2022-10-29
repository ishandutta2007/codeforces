// KINGPONYHEAD
# include<bits/stdc++.h>

using namespace std;

const int N = 100 + 77;
int T;
int n , m;
char S[N][N];
bool M[N][N];
vector < vector < pair < int , int > > > A;
void Solve() {
   vector < pair < int , int > > O , Z;
   for(int i = n - 1;i <= n;++ i)
      for(int j = m - 1;j <= m;++ j) {
         if(M[i][j])
            O.push_back(make_pair(i , j));
         else
            Z.push_back(make_pair(i , j));
      }

   if((int) O.size() == 4) {
      vector < pair < int , int > > x;
      for(int i = 0;i < 3;++ i)
         x.push_back(O[i]) , M[O[i].first][O[i].second] ^= 1;
      A.push_back(x);
      Solve();
   } else if((int)O.size() == 1) {
      vector < pair < int , int > > x;
      for(int i = 0;i < 1;++ i)
         x.push_back(O[i]) , M[O[i].first][O[i].second] ^= 1;
      for(int i = 0;i < 2;++ i)
         x.push_back(Z[i]) , M[Z[i].first][Z[i].second] ^= 1;
      A.push_back(x);
      Solve();
   } else if((int) O.size() == 2) {
      vector < pair < int , int > > x;
      for(int i = 0;i < 1;++ i)
         x.push_back(O[i]) , M[O[i].first][O[i].second] ^=  1;
      for(int i = 0;i < 2;++ i)
         x.push_back(Z[i]) , M[Z[i].first][Z[i].second] ^= 1;

      A.push_back(x);
      Solve();
   } else if((int) O.size() == 3) {
      vector < pair < int , int > > x;
      for(int i = 0;i < 3;++ i)
         x.push_back(O[i]) , M[O[i].first][O[i].second] ^= 1;
      A.push_back(x);
   }
}
inline void Test() {
   A.clear();
   scanf("%d %d" , & n , & m);
   for(int i = 1;i <= n;++ i) {
      scanf("%s" , S[i] + 1);
      for(int j = 1;j <= m;++ j)
         M[i][j] = (S[i][j] == '1');
   }
   for(int i = 1;i <= n - 2;++ i)
      for(int j = 1;j <= m;++ j) {
         if(M[i][j] == 1) {
            vector < pair < int , int > > x;
            x.push_back(make_pair(i , j));
            M[i][j] ^= 1;
            x.push_back(make_pair(i + 1 , j));
            M[i + 1][j] ^= 1;
            if(j < m)
               x.push_back(make_pair(i + 1 , j + 1)) , M[i + 1][j + 1] ^= 1;
            else
               x.push_back(make_pair(i + 1 , j - 1)) , M[i + 1][j - 1] ^= 1;
            A.push_back(x);
         }
      }

   for(int j = 1;j <= m - 2;++ j)
      for(int i = n - 1;i <= n;++ i) {
         if(M[i][j] == 1) {
            vector < pair < int , int > > x;
            x.push_back(make_pair(i , j));
            M[i][j] ^= 1;
            x.push_back(make_pair(n - 1 , j + 1));
            M[n - 1][j + 1] ^= 1;
            x.push_back(make_pair(n , j + 1));
            M[n][j + 1] ^= 1;
            A.push_back(x);
         }
      }
   //
   Solve();
   printf("%d\n" , (int) A.size());
   for(int i = 0;i < (int) A.size();++ i)
      printf("%d %d %d %d %d %d\n" , A[i][0].first , A[i][0].second , A[i][1].first , A[i][1].second , A[i][2].first , A[i][2].second);

}

int main() {
   T = 1;
   scanf("%d" , & T);
   while(T --)
      Test();
   return 0;
}