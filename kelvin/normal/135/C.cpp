#include <stdio.h>
#include <string.h>
#define MAXL 100050

int len,c0,c1,c2,r0,r1;
char str[MAXL];
char p[MAXL];

inline bool can00() {
   if(len&1) return c0-2+c2+1>=c1;
   return c0-2+c2>=c1;
}
inline bool can11() {
   if(len&1) return c1-2+c2-1>=c0;
   return c1-2+c2>=c0;
}
inline bool can01() {
   int cc0=len/2;
   int cc1=len-cc0;
   if(c0>cc0) return 0;
   if(c1>cc1) return 0;
   int m=cc0-c0;
   r0=r1=-1;
   for(int i=0;i<len;i++) {
      if(str[i]=='?') {
         if(m) {
            p[i]='0';
            m--;
         } else {
            p[i]='1';
         }
      } else p[i]=str[i];
      if(p[i]=='0') r0=i;
      else r1=i;
   }
   return r0<r1;
}
inline bool can10() {
   int cc0=len/2;
   int cc1=len-cc0;
   if(c0>cc0) return 0;
   if(c1>cc1) return 0;
   int m=cc1-c1;
   r0=r1=-1;
   for(int i=0;i<len;i++) {
      if(str[i]=='?') {
         if(m) {
            p[i]='1';
            m--;
         } else {
            p[i]='0';
         }
      } else p[i]=str[i];
      if(p[i]=='0') r0=i;
      else r1=i;
   }
   return r1<r0;
}

inline void solve() {
   if(can00()) puts("00");
   if(can01()) puts("01");
   if(can10()) puts("10");
   if(can11()) puts("11");
}

int main(void)
{
   scanf("%s",str);
   len=strlen(str);
   c0=c1=c2=0;
   for(int i=0;i<len;i++) {
      if(str[i]=='0') { c0++; r0=i; }
      else if(str[i]=='1') { c1++; r1=i; }
      else c2++;
   }
   solve();
   return 0;
}