#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXN 100050
#define ADD MAXN

using namespace std;

typedef pair<int,int> pii;

int n;
int a[MAXN],b[MAXN];
int apos[MAXN],bpos[MAXN];
int ds[MAXN],us[MAXN],ans[MAXN],cur[MAXN*3];
vector<int> din[MAXN],dout[MAXN];
vector<int> uin[MAXN],uout[MAXN];

inline int modn(int x) {
   if(x<0) return x+n;
   if(x>=n) return x-n;
   return x;
}

void dinsert(int l,int r,int x) {
   din[l].push_back(x);
   dout[r+1].push_back(x);
   //printf("dinsert %d %d %d\n",l,r,x);
}
void uinsert(int l,int r,int x) {
   uin[l].push_back(x);
   uout[r+1].push_back(x);
   //printf("uinsert %d %d %d\n",l,r,x);
}

void sub(vector<int> *ein,vector<int> *eout,int *rec) {
   priority_queue<int> pq;
   for(int i=-n+ADD;i<=2*n+ADD;i++)
      cur[i]=0;
   for(int i=0;i<n;i++) {
      for(int j=0;j<ein[i].size();j++) {
         int x=ein[i][j];
         if(!cur[x+ADD]) pq.push(-x);
         cur[x+ADD]++;
      }
      for(int j=0;j<eout[i].size();j++) {
         int x=eout[i][j];
         cur[x+ADD]--;
      }
      while(pq.size()&&!cur[-pq.top()+ADD]) pq.pop();
      //printf("[%d]\n",(int)pq.size());
      if(pq.size()) rec[i]=-pq.top();
      else rec[i]=2*n;
   }
}

void solve() {
   for(int i=0;i<n;i++) {
      apos[a[i]]=i;
      bpos[b[i]]=i;
   }
   for(int i=0;i<n;i++)
      ans[i]=n;
   for(int i=1;i<=n;i++) {
      int sh=modn(bpos[i]-apos[i]);
      if(bpos[i]>=apos[i]) {
         dinsert(0,sh,sh);
         uinsert(sh,bpos[i],-sh);
         dinsert(bpos[i]+1,n-1,n+sh);
      } else {
         uinsert(0,bpos[i],n-sh);
         dinsert(bpos[i]+1,sh,sh);
         uinsert(sh,n-1,-sh);
      }
   }
   sub(din,dout,ds);
   sub(uin,uout,us);
   for(int i=0;i<n;i++)
      ans[i]=min(ds[i]-i,us[i]+i);
   for(int i=0;i<n;i++)
      printf("%d\n",ans[i]);
}

int main(void)
{
   scanf("%d",&n);
   for(int i=0;i<n;i++)
      scanf("%d",a+i);
   for(int i=0;i<n;i++)
      scanf("%d",b+i);
   solve();
   return 0;
}