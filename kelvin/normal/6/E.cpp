#include <stdio.h>
#include <vector>
#define MAXN 100050

using namespace std;

bool gt(int a,int b) { return a>b; }
bool lt(int a,int b) { return a<b; }

class Unit {
   public:
      int x,h;
      Unit() {}
      Unit(int _x,int _h):x(_x),h(_h) {}
};

class Queue {
   public:
      int ql,qr;
      Unit *que;
      bool (*cmp)(int,int);
      Queue(bool (*_cmp)(int,int)):cmp(_cmp) {
         ql=qr=0;
         que=new Unit[MAXN];
      }
      ~Queue() {
         delete [] que;
      }
      bool empty() { return ql==qr; }
      Unit front() { return que[ql]; }
      Unit back() { return que[qr-1]; }
      Unit pop_front() { return que[ql++]; }
      Unit pop_back() { return que[--qr]; }
      void push_back(Unit u) {
         while(!empty()&&cmp(u.h,back().h)) pop_back();
         que[qr++]=u;
      }
      void pop_until(int x) {
         while(!empty()&&front().x<x) pop_front();
      }
      void print() {
         printf(">");
         for(int i=ql;i<qr;i++)
            printf(" %d",que[i].h);puts("");
      }
};

int n,maxd;
int ht[MAXN];

int opt;
vector<int> st;

inline void solve() {
   Queue minq(lt),maxq(gt);
   opt=0;
   st.clear();
   for(int i=0,j=0;i<n;i++) {
      minq.push_back(Unit(i,ht[i]));
      maxq.push_back(Unit(i,ht[i]));
      //minq.print();
      //maxq.print();
      while(maxq.front().h-minq.front().h>maxd) {
         ++j;
         minq.pop_until(j);
         maxq.pop_until(j);
      }
      if(i-j+1>opt) {
         opt=i-j+1;
         st.clear();
      }
      if(i-j+1==opt) st.push_back(j);
   }
   printf("%d %d\n",opt,st.size());
   for(vector<int>::iterator it=st.begin();it!=st.end();it++)
      printf("%d %d\n",*it+1,*it+opt);
}

int main(void)
{
   while(scanf("%d %d",&n,&maxd)==2) {
      for(int i=0;i<n;i++)
         scanf("%d",ht+i);
      solve();
   }
   return 0;
}