#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 100050

using namespace std;

int mod;
long long l,r,k;

class Matrix {
   public:
      int dim;
      int m[2][2];
      Matrix() {}
      void init(int _dim) {
         dim=_dim;
         memset(m,0,sizeof(m));
         for(int i=0;i<dim;i++) {
            for(int j=0;j<dim;j++)
               m[i][j]=0;
            m[i][i]=1;
         }
      }
      Matrix(int _dim) {
         init(_dim);
      }
      Matrix operator*(const Matrix &b) {
         Matrix c(dim);
         for(int i=0;i<dim;i++) {
            for(int j=0;j<dim;j++) {
               c.m[i][j]=0;
               for(int k=0;k<dim;k++)
                  c.m[i][j]=(c.m[i][j]+(long long)m[i][k]*b.m[k][j])%mod;
            }
         }
         return c;
      }
};

Matrix power(Matrix x,long long p) {
   Matrix m=x,r(2);
   while(p) {
      if(p&1) r=r*m;
      m=m*m;
      p>>=1;
   }
   return r;
}

int fib(long long p) {
   if(p<=2) return 1%mod;
   Matrix tran(2);
   tran.m[0][0]=0;
   tran.m[0][1]=1;
   tran.m[1][0]=1;
   tran.m[1][1]=1;
   Matrix f=power(tran,p-2);
   return (f.m[1][0]+f.m[1][1])%mod;
}

inline bool valid(long long d) {
   return r/d-(l-1)/d>=k;
}

int solve() {
   long long len=r-l+1;
   long long maxd=1;
   // floor(r/d)-floor((l-1)/d) >= k
   // enumerate d
   int sr=sqrt(r)+1;
   for(int d=1;d<=sr;d++)
      if(valid(d)) maxd=max(maxd,(long long)d);
   // enumerate floor(r/d)
   for(int fl=1;fl<=sr;fl++) {
      long long d=r/fl;
      if(valid(d)) maxd=max(maxd,d);
   }
   return fib(maxd);
}

int main(void)
{
   cin >> mod >> l >> r >> k;
   printf("%d\n",solve());
   return 0;
}