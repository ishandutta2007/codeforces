#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXN 131072

using namespace std;

class Seg {
   public:
      int *a;
      Seg() { a=new int[MAXN*2+1]; }
      ~Seg() { delete [] a; }
      void insert(int x,int c) {
         for(int v=MAXN+x;v;v>>=1)
            a[v]+=c;
      }
      int query(int r) {
         if(r<0) return 0;
         int s=0;
         for(int v=MAXN+r;v;v>>=1) {
            if(!(v&1)) {
               s+=a[v];
               if(v==(v&-v)) break;
               v--;
            }
         }
         return s;
      }
      int query(int l,int r) {
         return query(r)-query(l-1);
      }
};

int n;
long long k;
int s[MAXN];
int scn,sc[MAXN];

long long solve() {
   long long cur=0,sol=0;
   Seg lseg,rseg;
   for(int i=n-1;i>0;i--) {
      rseg.insert(s[i],1);
      cur+=rseg.query(0,s[i]-1);
   }
   for(int l=0,r=1;l<n;l++) {
      cur+=lseg.query(s[l]+1,n)+rseg.query(0,s[l]-1);
      lseg.insert(s[l],1);
      while(r<=l||r<n&&cur>k) {
         cur-=lseg.query(s[r]+1,n)+rseg.query(0,s[r]-1);
         rseg.insert(s[r],-1);
         r++;
      }
      sol+=n-r;
   }
   return sol;
}

int main(void)
{
   cin >> n >> k;
   for(int i=0;i<n;i++) {
      scanf("%d",s+i);
      sc[i]=s[i];
   }
   sort(sc,sc+n);
   scn=unique(sc,sc+n)-sc;
   for(int i=0;i<n;i++)
      s[i]=lower_bound(sc,sc+scn,s[i])-sc;
   cout << solve() << endl;
   return 0;
}