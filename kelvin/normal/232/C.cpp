#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int fibn=78;
long long fib[fibn+1];

//typedef pair<long long,long long> pll;
//map<pll,int> dp;

class State {
   public:
      int fn;
      long long a,b;
      bool shortcut;
      State(int _fn,long long _a,long long _b,bool _shortcut):fn(_fn),a(_a),b(_b),shortcut(_shortcut) {}
      const bool operator<(const State &y) const {
         if(a!=y.a) return a<y.a;
         if(b!=y.b) return b<y.b;
         return shortcut<y.shortcut;
      }
};

//map<State,int> dp;
int dp[fibn+1][4][4][2];
bool calc[fibn+1][4][4][2];

//vector<long long> rec[fibn+1];
//int recn[fibn+1];
long long rec[fibn+1];

inline void init() {
   for(int f=0;f<=fibn;f++) {
      //rec[f].clear();
      //recn[f]=0;
      rec[f]=-1;
      for(int i=0;i<4;i++)
         for(int j=0;j<4;j++)
            if(i>1||j>1) {
               for(int c=0;c<2;c++)
                  calc[f][i][j][c]=0;
            }
   }
}

inline int get_ai(int fn,long long a) {
   if(a==1) return 0;
   if(a==fib[fn]) return 1;
  // if(recn[fn]==0) {
   if(rec[fn]<0) {
      rec[fn]=a;
      return 2;
   } else {
      if(rec[fn]==a) return 2;
      return 3;
   }
   //for(int i=0;i<rec[fn].size();i++)
   /*for(int i=0;i<recn[fn];i++)
      if(rec[fn][i]==a) return i+2;
   //rec[fn].push_back(a);
   rec[fn][recn[fn]++]=a;
   return rec[fn].size()+1;*/
}

inline int dist(int fn,long long a,long long b,bool sc) {
   if(a>b) swap(a,b);
   if(a==b) return 0;
   if(b<=3) return 1;
   int ai=get_ai(fn,a);
   int bi=get_ai(fn,b);
   //if(dp.find(State(fn,a,b,sc))==dp.end()) {
   if(!calc[fn][ai][bi][sc]) {
      //printf("<%d %d %d %d>\n",fn,(int)a,(int)b,sc);
      /*long long sz1,sz2,sz;
      for(int i=2;fib[i]<b;i++) {
         sz=fib[i];
         sz1=fib[i-1];
         sz2=fib[i-2];
      }*/
      long long sz=fib[fn];
      long long sz1=fib[fn-1];
      long long sz2=fib[fn-2];
      int ans;
      if(b<=sz1) {
         ans=dist(fn-1,a,b,1);
      } else if(a<=sz1) {
         ans=dist(fn-2,1,b-sz1,0)+dist(fn-1,1,a,0)+1;
         ans=min(ans,dist(fn-2,1,b-sz1,0)+dist(fn-1,sz1,a,0)+1);
         if(sc) {
            ans=min(ans,dist(fn-2,sz2,b-sz1,0)+dist(fn-1,1,a,1)+2);
         }
      } else {
         ans=dist(fn-2,a-sz1,b-sz1,0);
         if(sc) {
            ans=min(ans,dist(fn-2,a-sz1,1,0)+dist(fn-2,b-sz1,sz2,0)+3);
            ans=min(ans,dist(fn-2,b-sz1,1,0)+dist(fn-2,a-sz1,sz2,0)+3);
         }
      }
      //dp[State(fn,a,b,sc)]=ans;
      calc[fn][ai][bi][sc]=1;
      dp[fn][ai][bi][sc]=ans;
   }
   //return dp[State(fn,a,b,sc)];
   return dp[fn][ai][bi][sc];
}

int main(void)
{
   fib[0]=1;
   fib[1]=2;
   for(int i=2;i<=fibn;i++) {
      fib[i]=fib[i-2]+fib[i-1];
      //printf("%2d: %I64d\n",i,fib[i]);
   }
   //printf("    10000000000000000\n");
   int qn,order;
   //cin >> qn >> order;
   scanf("%d %d",&qn,&order);
   if(order>fibn)
      order=fibn;
   for(int qi=0;qi<qn;qi++) {
      long long a,b;
      cin >> a >> b;
      //scanf("%I64d %I64d",&a,&b);
      init();
      int sol=dist(order,a,b,0);
      //cout << sol << endl;
      printf("%d\n",sol);
   }
   return 0;
}