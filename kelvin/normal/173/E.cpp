#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAXN 100050

using namespace std;

class Coor {
   public:
      int x,y;
      const bool operator<(const Coor &b) const {
         return x<b.x;
      }
};

class Event {
   public:
      int x,y,val;
      Event() {}
      Event(int _x,int _y,int _val):x(_x),y(_y),val(_val) {}
      const bool operator<(const Event &b) const {
         return x>b.x;
      }
};

class Query {
   public:
      int id,x,y1,y2,sol;
      Query() {}
      Query(int _id,int _x,int _y1,int _y2):id(_id),x(_x),y1(_y1),y2(_y2) {}
      const bool operator<(const Query &b) const {
         return x>b.x;
      }
};

class Node1 {
   public:
      int vl,vr,sum;
      Node1 *_l,*_r;
      Node1(int _vl,int _vr):vl(_vl),vr(_vr) {
         sum=0;
         _l=_r=NULL;
      }
      Node1* left() {
         int m=(vl+vr)>>1;
         if(!_l) _l=new Node1(vl,m);
         return _l;
      }
      Node1* right() {
         int m=(vl+vr)>>1;
         if(!_r) _r=new Node1(m+1,vr);
         return _r;
      }
      void insert(int x) {
         sum++;
         if(vl==vr) return;
         int m=(vl+vr)>>1;
         if(x<=m) left()->insert(x);
         else right()->insert(x);
      }
      int query(int l,int r) {
         if(vl==l&&vr==r) {
            return sum;
         } else {
            int m=(vl+vr)>>1;
            if(r<=m) return left()->query(l,r);
            else if(l>m) return right()->query(l,r);
            else return left()->query(l,m)+right()->query(m+1,r);
         }
      }
};

class Node2 {
   public:
      int vl,vr,mval;
      Node2 *_l,*_r;
      Node2(int _vl,int _vr):vl(_vl),vr(_vr) {
         mval=-1;
         _l=_r=NULL;
      }
      Node2* left() {
         int m=(vl+vr)>>1;
         if(!_l) _l=new Node2(vl,m);
         return _l;
      }
      Node2* right() {
         int m=(vl+vr)>>1;
         if(!_r) _r=new Node2(m+1,vr);
         return _r;
      }
      void insert(int x,int val) {
         if(val>mval) mval=val;
         if(vl==vr) return;
         int m=(vl+vr)>>1;
         if(x<=m) left()->insert(x,val);
         else right()->insert(x,val);
      }
      int query(int l,int r) {
         if(vl==l&&vr==r) {
            return mval;
         } else {
            int m=(vl+vr)>>1;
            if(r<=m) return left()->query(l,r);
            else if(l>m) return right()->query(l,r);
            else return max(left()->query(l,m),right()->query(m+1,r));
         }
      }
};

int n,d,ysz;
int yc[MAXN*3];
Coor pt[MAXN];
int sol[MAXN];
vector<Event> ev;
vector<Query> qu;

const int inf=1000000001;

inline int get(int y) {
   return lower_bound(yc,yc+ysz,y)-yc;
}

inline void solve() {
   ysz=0;
   for(int i=0;i<n;i++) {
      yc[ysz++]=pt[i].y;
      yc[ysz++]=pt[i].y+d;
      yc[ysz++]=pt[i].y-d;
   }
   sort(yc,yc+ysz);
   ysz=unique(yc,yc+ysz)-yc;
   sort(pt,pt+n);
   Node1 st1(0,ysz);
   int i,j;
   //for(int j=0;j<n;j++)
      //printf("<%d %d %d>\n",get(pt[j].y),get(pt[j].y-d),get(pt[j].y+d));
   for(i=0;i<n;i=j) {
      for(j=i;pt[j].x==pt[i].x;j++)
         st1.insert(get(pt[j].y));
      for(j=i;pt[j].x==pt[i].x;j++)
         ev.push_back(Event(pt[j].x,pt[j].y,st1.query(get(pt[j].y-d),get(pt[j].y+d))));
   }
   sort(ev.begin(),ev.end());
   sort(qu.begin(),qu.end());
   int ei=0;
   Node2 st2(0,ysz);
   for(int qi=0;qi<qu.size();qi++) {
      int x=qu[qi].x;
      int y1=qu[qi].y1;
      int y2=qu[qi].y2;
      if(y1>y2) {
         qu[qi].sol=-1;
         continue;
      }
      while(ei<ev.size()&&ev[ei].x>=x) {
         st2.insert(get(ev[ei].y),ev[ei].val);
         ei++;
      }
      qu[qi].sol=st2.query(get(y1),get(y2));
   }
   for(int i=0;i<qu.size();i++)
      sol[qu[i].id]=qu[i].sol;
}

int main(void)
{
   scanf("%d %d",&n,&d);
   for(int i=0;i<n;i++)
      scanf("%d",&pt[i].x);
   for(int i=0;i<n;i++)
      scanf("%d",&pt[i].y);
   int qn;
   scanf("%d",&qn);
   for(int qi=0;qi<qn;qi++) {
      int i1,i2;
      scanf("%d %d",&i1,&i2);
      i1--; i2--;
      if(pt[i1].y>pt[i2].y) swap(i1,i2);
      qu.push_back(Query(qi,max(pt[i1].x,pt[i2].x),pt[i2].y-d,pt[i1].y+d));
   }
   solve();
   for(int i=0;i<qn;i++)
      printf("%d\n",sol[i]);
   return 0;
}