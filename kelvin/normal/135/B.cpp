#include <stdio.h>

inline int sqr(int x) { return x*x; }

class Coor {
   public:
      int x,y;
      void input() {
         scanf("%d %d",&x,&y);
      }
      Coor& operator-=(const Coor &b) {
         x-=b.x;
         y-=b.y;
         return *this;
      }
      const Coor operator-(const Coor &b) const {
         return Coor(*this)-=b;
      }
      const bool operator==(const Coor &b) const {
         return x==b.x&&y==b.y;
      }
      int len2() const {
         return x*x+y*y;
      }
      void print() {
         printf("(%d,%d)\n",x,y);
      }
};

Coor pt[8];

inline int dist2(Coor a,Coor b) { return (a-b).len2(); }
inline int dot(Coor a,Coor b) { return a.x*b.x+a.y*b.y; }
inline int dot(Coor o,Coor a,Coor b) { return dot(a-o,b-o); }

inline bool isSquare(Coor a,Coor b,Coor c,Coor d) {
   int d2=dist2(a,b);
   if(a==b) return 0;
   if(dist2(b,c)!=d2) return 0;
   if(dist2(c,d)!=d2) return 0;
   if(dist2(d,a)!=d2) return 0;
   if(dist2(a,c)!=dist2(b,d)) return 0;
   return 1;
}
inline bool ok1(Coor a,Coor b,Coor c,Coor d) {
   return    isSquare(a,b,c,d)
          || isSquare(a,b,d,c)
          || isSquare(a,c,b,d)
          || isSquare(a,c,d,b)
          || isSquare(a,d,b,c)
          || isSquare(a,d,c,b);
}

inline bool isRectangle(Coor a,Coor b,Coor c,Coor d) {
   if(a==b||b==c||c==d||d==a) return 0;
   if(dot(b,a,c)) return 0;
   if(dot(c,b,d)) return 0;
   if(dot(d,c,a)) return 0;
   if(dot(a,d,b)) return 0;
   return 1;
}
inline bool ok2(Coor a,Coor b,Coor c,Coor d) {
   return    isRectangle(a,b,c,d)
          || isRectangle(a,b,d,c)
          || isRectangle(a,c,b,d)
          || isRectangle(a,c,d,b)
          || isRectangle(a,d,b,c)
          || isRectangle(a,d,c,b);
}

int i1[4],i2[4];
Coor p1[4],p2[4];

bool dfs(int x,int c1,int c2) {
   if(x==8) {
      if(ok1(p1[0],p1[1],p1[2],p1[3])&&ok2(p2[0],p2[1],p2[2],p2[3])) {
         puts("YES");
         for(int i=0;i<4;i++)
            printf("%d%c",i1[i],i<3?' ':'\n');
         for(int i=0;i<4;i++)
            printf("%d%c",i2[i],i<3?' ':'\n');
         return 1;
      } else return 0;
   }
   if(c1<4) {
      i1[c1]=x+1;
      p1[c1]=pt[x];
      if(dfs(x+1,c1+1,c2)) return 1;
   }
   if(c2<4) {
      i2[c2]=x+1;
      p2[c2]=pt[x];
      if(dfs(x+1,c1,c2+1)) return 1;
   }
   return 0;
}

inline bool solve() {
   return dfs(0,0,0);
}

int main(void)
{
   for(int i=0;i<8;i++)
      pt[i].input();
   if(!solve()) puts("NO");
   return 0;
}