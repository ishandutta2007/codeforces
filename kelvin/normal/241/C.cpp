#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;

class Mirror {
   public:
      int l,r,s;
      Mirror(int _l,int _r,int _s):l(_l),r(_r),s(_s) {}
      const bool operator<(const Mirror &b) const { return l<b.l; }
};

const int maxbounce=200000;
const double eps=1e-9;
const double w=1e5;
const double h=1e2;  

int nmirror;
double hl,hr;
vector<Mirror> tm,bm;

inline int cnt(double x,double d0,double d) {
   if(x<d0-eps) return 0;
   x-=d0;
   return int(x/d)+1;
}

inline int score(int n) {
   double toth;
   if(n&1) toth=(n-1)*h+hl+hr;
   else toth=(n-1)*h+hl+h-hr;
   double d0=w*hl/toth;
   double d=2*w*h/toth;
   int s=0;
   int totc=0;
   for(int i=0;i<bm.size();i++) {
      int rc=cnt(bm[i].r,d0,d);
      int lc=cnt(bm[i].l-eps,d0,d);
      if(rc-lc>1) return 0;
      if(rc-lc==1) {
         s+=bm[i].s;
         totc++;
      }
   }
   d0+=0.5*d;
   for(int i=0;i<tm.size();i++) {
      int rc=cnt(tm[i].r,d0,d);
      int lc=cnt(tm[i].l-eps,d0,d);
      if(rc-lc>1) return 0;
      if(rc-lc==1) {
         s+=tm[i].s;
         totc++;
      }
   }
   if(totc!=n) return 0;
   return s;
}

int solve() {
   int opt=0;
   //sort(tm.begin(),tm.end());
   //sort(bm.begin(),bm.end());
   for(int t=1;t<=maxbounce;t++)
      opt=max(opt,score(t));
   swap(tm,bm);
   hl=h-hl;
   hr=h-hr;
   for(int t=1;t<=maxbounce;t++)
      opt=max(opt,score(t));
   return opt;
}

int main(void)
{  
   scanf("%lf %lf %d",&hl,&hr,&nmirror);
   for(int i=0;i<nmirror;i++) {
      char ch[3];
      int lb,rb,sc;
      scanf("%d %s %d %d",&sc,ch,&lb,&rb);
      if(ch[0]=='T') tm.push_back(Mirror(lb,rb,sc));
      else bm.push_back(Mirror(lb,rb,sc));
   }
   printf("%d\n",solve());
   return 0;
}