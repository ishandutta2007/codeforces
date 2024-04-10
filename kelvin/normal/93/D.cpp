#include <stdio.h>

const int mod=1000000007;
const int mod2=1000000007*2;

// brwy-
// 01234

// no same adj
// no wy/yw   : 23/32
// no rb/br   : 01/10
// no bwr/rwb : 021/120

inline int rep(int i,int j) { return i*5+j; }

class Matrix {
   public:
      int m[26][26];
      Matrix() {
         int i,j;
         for(i=0;i<26;i++) {
            for(j=0;j<26;j++)
               m[i][j]=0;
            m[i][i]=1;
         }
      }
      const Matrix operator*(const Matrix &b) const {
         int i,j,k;
         Matrix c;
         long long t;
         for(i=0;i<26;i++) {
            for(j=0;j<26;j++) {
               t=0;
               for(k=0;k<26;k++)
                  t+=(long long)m[i][k]*b.m[k][j]%mod2;
               c.m[i][j]=t%mod2;
            }
         }
         return c;
      }
      Matrix& operator*=(const Matrix &b) {
         *this=*this*b;
         return *this;
      }
};

Matrix power(Matrix x,int p) {
   Matrix s,m=x;
   while(p) {
      if(p&1) s*=m;
      m*=m;
      p>>=1;
   }
   return s;
}

Matrix tran;

inline bool forbid(int i,int j) {
   return i!=4&&i==j || (i==2&&j==3 || i==3&&j==2 || i==0&&j==1 || i==1&&j==0);
}
inline bool forbid(int i,int j,int k) {
   return i==0&&j==2&&k==1 || i==1&&j==2&&k==0;
}

inline void pre() {
   int i,j,k,f,t;
   for(i=0;i<26;i++)
      for(j=0;j<26;j++)
         tran.m[i][j]=0;
   for(i=0;i<5;i++) {
      for(j=0;j<5;j++) {
         if(forbid(i,j)) continue;
         for(k=0;k<4;k++) {
            if(forbid(j,k)) continue;
            if(forbid(i,j,k)) continue;
            f=rep(i,j);
            t=rep(j,k);
            tran.m[t][f]=1;
         }
      }
   }
   for(j=0;j<26;j++)
      tran.m[25][j]=1;
}

inline int countBelow(int n) {
   int c=rep(4,4);
   Matrix res;
   if(n==0) return 0;
   res=power(tran,n+1);
   return res.m[25][c]-1;
}
inline int countNoSym(int n) {
   return ((long long)countBelow(n)+countBelow((n+1)/2))/2%mod;
}

int main(void)
{
   int l,r,sol;
   pre();
   while(scanf("%d %d",&l,&r)==2) {
      sol=((long long)countNoSym(r)-countNoSym(l-1)+mod)%mod;
      printf("%d\n",sol);
   }
   return 0;
}