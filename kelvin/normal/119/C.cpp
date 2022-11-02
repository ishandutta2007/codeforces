#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#define MAXN 55
#define MAXD 150

using namespace std;

class Subject {
   public:
      long long l,r;
      int c,d,id;
      void input(int ii) {
         id=ii;
         cin>>l>>r>>c;
         d=r-l;
      }
      const bool operator<(const Subject &b) const {
         return c<b.c;
      }
};

const long long infll=1000000000000000000LL;

int day,sn,k;
Subject s[MAXN];
long long dp[MAXN][MAXN][MAXD]={0};
// day|which|displacement
int prev[MAXN][MAXN][MAXD][2];

typedef pair<int,long long> pil;
vector<pil> sol;

inline bool isin(long long x,long long l,long long r) { return x>=l && x<=r; }

inline bool solve() {
   sort(s,s+sn);
   for(int t=0;t<day;t++)
      for(int i=0;i<sn;i++)
         for(int j=0;j<=s[i].d;j++)
            dp[t][i][j]=-infll;
   for(int i=0;i<sn;i++)
      for(int j=0;j<=s[i].d;j++)
         dp[0][i][j]=s[i].l+j;
   for(int t=0;t<day-1;t++) {
      for(int i=0;i<sn;i++) {
         for(int dis=0;dis<=s[i].d;dis++) {
            if(dp[t][i][dis]<0) continue;
            long long x=s[i].l+dis,y,ss;
            // + *
            for(int ttt=0;ttt<2;ttt++) {
               if(!ttt) y=x+k;
               else y=x*k;
               ss=dp[t][i][dis]+y;
               for(int j=i+1;j<sn;j++) {
                  if(s[j].c<=s[i].c) continue;
                  long long ny=y-s[j].l;
                  if(isin(y,s[j].l,s[j].r)&&ss>dp[t+1][j][ny]) {
                     dp[t+1][j][ny]=ss;
                     prev[t+1][j][ny][0]=i;
                     prev[t+1][j][ny][1]=dis;
                  }
               }
            }
         }
      }
   }
   // output
   int i,dis,oi,od;
   long long opt=-infll;
   for(i=0;i<sn;i++) {
      for(dis=0;dis<=s[i].d;dis++) {
         if(dp[day-1][i][dis]>opt) {
            opt=dp[day-1][i][dis];
            oi=i;
            od=dis;
         }
      }
   }
   if(opt<0) return 0;
   i=oi;
   dis=od;
   sol.clear();
   for(int t=day-1;t>=0;t--) {
      sol.push_back(make_pair(s[i].id,s[i].l+dis));
      int ti=i;
      i=prev[t][ti][dis][0];
      dis=prev[t][ti][dis][1];
   }
   puts("YES");
   for(int i=0;i<day;i++) {
      pil z=sol[day-i-1];
      cout << z.first << " " << z.second << endl;
   }
   return 1;
}

int main(void)
{
   scanf("%d %d %d",&day,&sn,&k);
   for(int i=0;i<sn;i++)
      s[i].input(i+1);
   if(!solve()) puts("NO");
   return 0;
}