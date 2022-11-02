#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXK 16
//#define MAXLCM 360360

using namespace std;

const int inf=10000;
const int lcm=360360;

int k;
long long a,b;
bool vis[lcm];
int ts[lcm];
long long val[lcm];

long long solve() {
   //vis[a%lcm]=1;
   //ts[a%lcm]=0;
   long long tt=0;
   bool freepass=0;
   while(a>b) {
      if(!freepass) {
         int ra=a%lcm;
         if(vis[ra]) {
            long long diff=val[ra]-a;
            int per=tt-ts[ra];
            long long remain=a-b;
            long long maxreduce=max(remain-MAXK,0LL);
            long long q=maxreduce/diff;
            tt+=per*q;
            a-=diff*q;
            freepass=1;
         }
         vis[ra]=1;
         ts[ra]=tt;
         val[ra]=a;
      }
      long long na=a-1;
      for(int m=2;m<=k;m++) {
         long long aa=a/m*m;
         if(aa<b) continue;
         na=min(na,aa);
      }
      a=na;
      tt++;
   }
   return tt;
}

int main(void)
{
   cin >> a >> b >> k;
   cout << solve() << endl;
   return 0;
}