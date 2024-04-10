#include <stdio.h>
#include <set>

using namespace std;

class Dice {
   public:
      int s[4];
      void input() {
         char r1[3],r2[3];
         scanf("%s %s",r1,r2);
         s[0]=r1[0];
         s[1]=r1[1];
         s[2]=r2[1];
         s[3]=r2[0];
         *this=minrep();
      }
      Dice minrep() {
         Dice b=*this;
         for(int i=0;i<4;i++) {
            if(*this<b) b=*this;
            leftshift();
         }
         return b;
      }
      void leftshift() {
         int t=s[0];
         for(int i=0;i<3;i++)
            s[i]=s[i+1];
         s[3]=t;
      }
      const bool operator<(const Dice &b) const {
         for(int i=0;i<4;i++)
            if(s[i]!=b.s[i]) return s[i]<b.s[i];
         return 0;
      }
};

int main(void)
{
   int n;
   Dice d;
   set<Dice> ds;
   scanf("%d",&n);
   for(int i=0;i<n;i++) {
      if(i) scanf("%*s");
      d.input();
      ds.insert(d);
   }
   printf("%d\n",ds.size());
}