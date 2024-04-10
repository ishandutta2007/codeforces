#include <stdio.h>
#include <string.h>
#include <vector>
#define MAXN 1000500

using namespace std;

int la,lb;
int sa[MAXN],sb[MAXN*2];
int posa[MAXN],posb[MAXN],next[MAXN*2];

vector<int> s;
bool vis[MAXN*2]={0};

inline int mod(int a,int m) {
   return a<m?a:a-m;
}

inline int sub(vector<int> &s) {
   int i,j,sz=s.size(),opt=0;
   for(i=0,j=0;i<sz;i++) {
      while(j<sz&&s[j]<s[i]+lb) j++;
      opt=max(opt,j-i);
   }
   return opt;
}

inline int solve() {
   for(int i=0;i<MAXN;i++)
      posb[i]=lb*2;
   for(int i=lb*2-1;i>=0;i--) {
      if(sb[i]<0) next[i]=lb*2;
      else {
         next[i]=posb[mod(sb[i]+1,la)];
         posb[sb[i]]=i;
      }
   }
   int opt=0;
   for(int i=0;i<lb;i++) {
      if(sb[i]<0||vis[i]) continue;
      s.clear();
      for(int j=i;j<lb*2;j=next[j]) {
         vis[j]=1;
         s.push_back(j);
      }
      opt=max(opt,sub(s));
   }
   return opt;
}

int main(void)
{
   scanf("%d %d",&la,&lb);
   memset(posa,-1,sizeof(posa));
   for(int i=0;i<la;i++) {
      scanf("%d",sa+i);
      posa[sa[i]]=i;
   }
   for(int i=0;i<lb;i++) {
      scanf("%d",sb+i);
      sb[i]=posa[sb[i]];
      sb[i+lb]=sb[i];
   }
   printf("%d\n",solve());
   return 0;
}