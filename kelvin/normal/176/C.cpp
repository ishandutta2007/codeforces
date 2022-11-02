#include <stdio.h>
#include <algorithm>

int r,c;

inline bool solve() {
   if(r>c) std::swap(r,c);
   if(r>=5) return 0;
   if(c>5) return 0;
   if(r==4&&c==5) return 0;
   return 1;
}

int main(void)
{
   int r1,r2,c1,c2;
   scanf("%*d %*d %d %d %d %d",&r1,&c1,&r2,&c2);
   r=r1-r2;
   if(r<0) r=-r;
   c=c1-c2;
   if(c<0) c=-c;
   r++;
   c++;
   puts(solve()?"First":"Second");
   return 0;
}