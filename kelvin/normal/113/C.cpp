#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

#define MAXVAL 300000010
#define MAXN MAXVAL/9


int l,r,sol;
unsigned int sieve[MAXVAL/20]={0};

#define MAP(x) ((sieve[x>>5]>>(x&31))&1)

bool isprime(int p)
{
   return (MAP((p-1)>>1)==0);
}

inline void gen() {
   int i,j,k,p;
   int bd=sqrt(r/2+1)+2;
   for (i=1; i<=bd; i++)
      if (MAP(i) == 0)
      {
         for (j=2*i*(i+1), k=2*i+1; j<r/2+1; j+=k)
            sieve[j>>5] |= 1<<(j&31);
         p=(i*2+1);
         if(l<=p&&p<=r&&(p&3)==1) sol++;
//         printf("<%d>",p);
      }
   i=i*2+1;
   i=(i+2)/4*4+1;
   for(;i<=r;i+=4) {
      if(l<=i&&isprime(i)) {
         sol++;
//         printf("<%d>\n",i);
      }
   }
}

/*inline void gean() {
  int i,j,bnd;
  np.resize(r+1);
  np[1]=1;
  bnd=sqrt(r)+10;
  for(i=3;i<=r;i+=2) {
  if(np[i]) continue;
//printf("<%d>\n",i);
if(i>bnd) continue;
for(j=i*i;j<=r;j+=i)
np[j]=1;
}
}*/

/*inline void gen() {
  int i,j;
  np.resize(r+1);
  for(i=2;i<=r;i++) {
  if(!np[i]) {
  pr[pn++]=i;
  }
  for(j=0;j<pn && i*pr[j]<=r; j++) {
  np[i*pr[j]]=1;
  if(i%pr[j]==0) break;
  }
  }
  }*/

/*inline void gogo() {
  int a,b;
  ok.resize(r+1);
  for(a=1;a*a<=r;a+=2) {
  for(b=2;a*a+b*b<=r;b+=2) {
  ok[a*a+b*b]=1;
  }
  }
  }*/

inline int solve() {
   int i;
   if(l<=2&&r>=2) sol++;
   gen();
   //   puts("!");
   //   gogo();
   //   puts("?");
   return sol;
}

int main(void)
{
   scanf("%d %d",&l,&r);
   printf("%d\n",solve());
   return 0;
}