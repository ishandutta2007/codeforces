#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define MAXL 2050

using namespace std;

const long long mod=3333331;

int tl,sbl,sel,seg;
char t[MAXL];
char sb[MAXL],se[MAXL];
bool bm[MAXL],em[MAXL];
int rev[MAXL];

int same[MAXL][MAXL];
vector<long long> arr;

inline void findsame() {
   int i,j,p;
   for(i=tl-1;i>=0;i--) {
      for(j=tl-1;j>=0;j--) {
         if(i==tl-1||j==tl-1) p=0;
         else p=same[i+1][j+1];
         if(t[i]==t[j]) same[i][j]=0;
         else same[i][j]=p+1;
      }
   }
}

inline int solve() {
   int i,j,l;
   tl=strlen(t);
   sbl=strlen(sb);
   sel=strlen(se);
//   findsame();
   //
   for(i=0;i+sbl<=tl;i++) {
      for(j=0;j<sbl;j++)
         if(t[i+j]!=sb[j]) break;
      bm[i]=(j==sbl);
   }
   for(;i<tl;i++)
      bm[i]=0;
   //
   for(i=0;i<sel-1;i++)
      em[i]=0;
   for(i=sel-1;i<tl;i++) {
      for(j=0;j<sel;j++)
         if(t[i-j]!=se[sel-j-1]) break;
      em[i]=(j==sel);
   }
   //
   int sol=0;
   long long h,mmm;
   seg=(sbl>sel?sbl:sel);
   for(l=seg;l<=tl;l++) {
      arr.clear();
      mmm=1;
      for(i=0;i<l;i++)
         mmm*=mod;
      h=0;
      for(i=0;i<l;i++)
         h=h*mod+t[i]-'a'+1;
      for(i=0;i+l<=tl;i++) {
         if(bm[i]&&em[i+l-1]) {
            arr.push_back(h);
         }
         h=h*mod-mmm*(t[i]-'a'+1)+(t[i+l]-'a'+1);
      }
      sort(arr.begin(),arr.end());
//      for(i=0;i<arr.size();i++)
//         printf("%lld ",arr[i]);puts("");
      int c=0;
      for(i=0;i<arr.size();i++)
         if(!i||arr[i]!=arr[i-1]) c++;
      sol+=c;
   }
   return sol;
}

int main(void)
{
   scanf("%s %s %s",t,sb,se);
   printf("%d\n",solve());
   return 0;
}