#include <stdio.h>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>
#define MAXN 100050

using namespace std;

typedef pair<int,int> pii;

int n,id,pos;
int s[MAXN];
pii ss[MAXN];
map<int,int> mp;

vector<pii> seq;

inline bool islucky(int w) {
   while(w) {
      int x=w%10;
      if(x!=4&&x!=7) return 0;
      w/=10;
   }
   return 1;
}

inline bool pre() {
   int i;
   id=-1;
   for(i=0;i<n;i++) {
      ss[i]=make_pair(s[i],i);
      if(islucky(s[i])) {
         id=s[i];
         pos=i;
      }
   }
   if(id<0) return 0;
   std::sort(ss,ss+n);
   for(i=0;i<n;i++)
      s[ss[i].second]=i;
   id=s[pos];
   return 1;
}

inline void myswap(int a,int b) {
   if(a!=b) {
      seq.push_back(make_pair(a,b));
      if(pos==a) pos=b;
      else if(pos==b) pos=a;
      swap(s[a],s[b]);
   }
}
inline void output() {
   int i;
   printf("%d\n",seq.size());
   for(i=0;i<seq.size();i++)
      printf("%d %d\n",seq[i].first+1,seq[i].second+1);
}

inline void critgo() {
   myswap(pos,id);
}

vector<int> arr;
inline void resolve(int x) {
   int i,orig=pos;
   arr.clear();
   arr.push_back(x);
   for(i=s[x];i!=x;i=s[i])
      arr.push_back(i);
   myswap(pos,arr[0]);
   for(i=arr.size()-1;i>0;i--)
      myswap(pos,arr[i]);
   myswap(pos,orig);
}
inline void dorest() {
   int i;
   for(i=0;i<n;i++)
      if(s[i]!=i) resolve(i);
}

inline void solve() {
   if(!pre()) {
      for(int i=0;i<n-1;i++) {
         if(s[i]>s[i+1]) {
            puts("-1");
            return;
         }
      }
      puts("0");
      return;
   }
   seq.clear();
   critgo();
   dorest();
   output();
}

int main(void)
{
   int i;
   while(scanf("%d",&n)==1) {
      for(i=0;i<n;i++)
         scanf("%d",s+i);
      solve();
   }
   return 0;
}