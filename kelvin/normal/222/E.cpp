#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int mod=1000000007;

inline int add(int a,int b) { return a+b<mod?a+b:a+b-mod; }

class Matrix {
   public:
      int dim;
      int m[52][52];
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

long long n;
int z,pn;
Matrix tran;

inline int c2d(char c) {
   if(c>='a'&&c<='z') return c-'a';
   else return c-'A'+26;
}

Matrix power(Matrix x,long long p) {
   Matrix m=x,r(z);
   while(p) {
      if(p&1) r=r*m;
      m=m*m;
      p>>=1;
   }
   return r;
}

int solve() {
   Matrix tp=power(tran,n-1);
   int sol=0;
   for(int i=0;i<z;i++)
      for(int j=0;j<z;j++)
         sol=add(sol,tp.m[i][j]);
   return sol;
}

int main(void)
{
   cin >> n >> z >> pn;
   tran.init(z);
   for(int i=0;i<z;i++)
      for(int j=0;j<z;j++)
         tran.m[i][j]=1;
   for(int i=0;i<pn;i++) {
      char str[5];
      scanf("%s",str);
      int s=c2d(str[0]);
      int t=c2d(str[1]);
      tran.m[t][s]=0;
   }
   printf("%d\n",solve());
   return 0;
}