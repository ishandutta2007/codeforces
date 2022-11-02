#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 105000

using namespace std;

class Box {
   public:
      int k,n;
      void input() {
         scanf("%d %d",&k,&n);
      }
      int contain() {
         int nn=n,kk=k;
         while(nn>4) {
            nn=(nn+3)>>2;
            kk++;
         }
         return kk+1;
         /*while(nn>1) {
            nn>>=2;
            kk++;
         }
         return kk;*/
      }
      const bool operator<(const Box &b) const {
         return k<b.k;
      }
};

int n;
Box b[MAXN];

int solve() {
   //sort(b,b+n);
   int big=0;
   for(int i=0;i<n;i++)
      big=max(big,b[i].contain());
   return big;
}

int main(void)
{
   scanf("%d",&n);
   for(int i=0;i<n;i++)
      b[i].input();
   printf("%d\n",solve());
   return 0;
}