#include <stdio.h>
#define MAXN 160000

const double inf=1e20;

inline double min(double a,double b) { return a<b?a:b; }
inline double min(double a,double b,double c) { return min(a,min(b,c)); }

class Node {
   public:
      int vl,vr;
      double val,lmin,rmin,minval;
      Node *_l,*_r;
      Node(int l,int r):vl(l),vr(r) {
         val=minval=lmin=rmin=0.0;
         _l=_r=NULL;
      }
      ~Node() {
         if(_l) delete _l;
         if(_r) delete _r;
      }
      Node *left() {
         int m=(vl+vr)>>1;
         if(!_l) _l=new Node(vl,m);
         return _l;
      }
      Node *right() {
         int m=(vl+vr)>>1;
         if(!_r) _r=new Node(m+1,vr);
         return _r;
      }
      void up() {
         lmin=min(left()->lmin,left()->val+right()->lmin);
         rmin=min(right()->rmin,right()->val+left()->rmin);
         minval=min(left()->minval,right()->minval,left()->rmin+right()->lmin);
      }
      void insert(int l,int r,double a) {
         if(l>r) return;
         int m=(vl+vr)>>1;
         val+=a;
         if(vl==l&&vr==r) {
            //printf("<i %.4lf>\n",a);
            lmin=rmin=minval=min(a,0);
            return;
         } else {
            if(r<=m) left()->insert(l,r,a);
            else if(l>m) right()->insert(l,r,a);
            else {
               left()->insert(l,m,a);
               right()->insert(m+1,r,a);
            }
            up();
         }
      }
      double query(int l,int r,int sg=0) {
         int m=(vl+vr)>>1;
         if(l>r) return 0;
         if(vl==l&&vr==r) {
            if(sg==0) return minval;
            else if(sg<0) return lmin;
            else return rmin;
         } else {
            if(r<=m) return left()->query(l,r,sg);
            else if(l>m) return right()->query(l,r,sg);
            else {
               if(sg==0) return min(left()->query(l,m),
                                    right()->query(m+1,r),
                                    left()->query(l,m,1)+right()->query(m+1,r,-1));
               else if(sg<0) return min(left()->lmin,
                                        left()->val+right()->query(m+1,r,-1));
               else return min(right()->rmin,
                               right()->val+left()->query(l,m,1));
            }
         }
      }
};

int n,m,pp;
double punish;
int xx[MAXN];
double x[MAXN];
double pr[MAXN];
double seg[MAXN],ss[MAXN];

int main(void)
{
   scanf("%d %d %d",&n,&m,&pp);
   punish=pp;
   Node st(0,n);
   for(int i=0;i<n;i++) {
      scanf("%d",xx+i);
      if(i) x[i-1]=xx[i]-xx[i-1];
   }
   for(int i=0;i<n-1;i++) {
      int ppp;
      scanf("%d",&ppp);
      pr[i]=(double)ppp/100;
   }
   ss[0]=0.0;
   for(int i=0;i<n-1;i++) {
      seg[i]=-(x[i]*0.5-punish*pr[i]);
      st.insert(i,i,seg[i]);
      ss[i+1]=ss[i]+seg[i];
   }
   /*for(int i=0;i<n-1;i++)
      printf("%.3lf ",seg[i]);puts("");*/
   double sol=0.0;
   for(int i=0;i<m;i++) {
      int l,r;
      scanf("%d %d",&l,&r);
      l--;
      r--;
      //printf("[%d %d %.4lf]\n",l,r,st.query(l,r-1));
      //sol+=(ss[r]-ss[l])-min(0.0,st.query(l,r-1));
      sol+=-min(0.0,st.query(l,r-1));
   }
   printf("%.9lf\n",sol);
   return 0;
}