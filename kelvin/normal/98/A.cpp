#include <stdio.h>
#include <string.h>
#include <set>

using namespace std;

class Cube {
   public:
      char c[7];
      void r1() {
         char t=c[0];
         c[0]=c[1];
         c[1]=c[5];
         c[5]=c[3];
         c[3]=t;
      }
      void r2() {
         char t=c[1];
         c[1]=c[2];
         c[2]=c[3];
         c[3]=c[4];
         c[4]=t;
      }
      void r3() {
         char t=c[0];
         c[0]=c[2];
         c[2]=c[5];
         c[5]=c[4];
         c[4]=t;
      }
      const bool operator<(const Cube &b) const {
         int i;
         for(i=0;i<6;i++)
            if(c[i]!=b.c[i]) return c[i]<b.c[i];
         return 0;
      }
};

bool used[7];

inline void relax(Cube &x,Cube val) {
   if(val<x) x=val;
}
inline Cube getmin(Cube x) {
   int i;
   Cube m=x;
   for(i=0;i<4;i++) {
      relax(m,x);
      x.r2();
   }
   x.r1();
   for(i=0;i<4;i++) {
      relax(m,x);
      x.r3();
   }
   x.r1();
   for(i=0;i<4;i++) {
      relax(m,x);
      x.r2();
   }
   x.r1();
   for(i=0;i<4;i++) {
      relax(m,x);
      x.r3();
   }
   x.r1();
   x.r3();
   for(i=0;i<4;i++) {
      relax(m,x);
      x.r1();
   }
   x.r3();
   x.r3();
   for(i=0;i<4;i++) {
      relax(m,x);
      x.r1();
   }
   return m;
}

int main(void)
{
   int a,b,c,d,e,f;
   char str[7];
   set<Cube> st;
   Cube x;
   while(scanf("%s",str)!=EOF) {
      memset(used,0,sizeof(used));
      st.clear();
      for(a=0;a<6;a++) {
         used[a]=1;
         x.c[a]=str[0];
         for(b=0;b<6;b++) {
            if(used[b]) continue;
            used[b]=1;
            x.c[b]=str[1];
            for(c=0;c<6;c++) {
               if(used[c]) continue;
               used[c]=1;
               x.c[c]=str[2];
               for(d=0;d<6;d++) {
                  if(used[d]) continue;
                  used[d]=1;
                  x.c[d]=str[3];
                  for(e=0;e<6;e++) {
                     if(used[e]) continue;
                     used[e]=1;
                     x.c[e]=str[4];
                     for(f=0;f<6;f++) {
                        if(used[f]) continue;
                        used[f]=1;
                        x.c[f]=str[5];
                        st.insert(getmin(x));
                        used[f]=0;
                     }
                     used[e]=0;
                  }
                  used[d]=0;
               }
               used[c]=0;
            }
            used[b]=0;
         }
         used[a]=0;
      }
      printf("%d\n",st.size());
/*      for(set<Cube>::iterator it=st.begin();it!=st.end();it++) {
         for(int z=0;z<6;z++)
            printf("%c",it->c[z]);
         puts("");
      }*/
   }
   return 0;
}