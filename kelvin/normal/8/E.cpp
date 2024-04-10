#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 55

using namespace std;

const long long infll=100000000000000000LL;

long long tp[MAXN];
long long dpflip[MAXN];
long long dpfinv[MAXN];

int n;
long long k;
char s[MAXN];

inline long long add(long long a,long long b) { return a+b>infll?infll:a+b; }

inline void pre() {
   tp[0]=1;
   for(int i=1;i<MAXN;i++)
      tp[i]=add(tp[i-1],tp[i-1]);
   dpflip[0]=1;
   dpflip[1]=2;
   for(int i=2;i<MAXN;i++)
      dpflip[i]=add(add(dpflip[i-2],dpflip[i-2]),tp[i-2]);
   dpfinv[0]=dpfinv[1]=1;
   for(int i=2;i<MAXN;i++)
      dpfinv[i]=add(add(dpfinv[i-2],dpfinv[i-2]),tp[i-2]);
}

inline bool valid() {
   char t[MAXN];
   if(s[n-1]=='0') {
      for(int i=0;i<n;i++)
         t[i]=s[n-i-1];
   } else {
      for(int i=0;i<n;i++)
         t[i]='1'-s[n-i-1]+'0';
   }
   s[n]=t[n]='\0';
   return strcmp(s,t)<=0;
}

inline bool solve() {
   int i,j;
   if(add(dpflip[n-2],dpfinv[n-2])<=k) return 0;
   s[0]='0';
   for(i=1;i<n;i++) {
      long long c=0;
      s[i]='0';
      if(i<n-1) {
         // flip
         s[n-1]='0';
         for(j=1;j<=i&&n-j-1>i;j++) {
            if(s[j]=='0') c=add(c,tp[n-j-i-2]);
            s[n-j-1]=s[j];
         }
         if(j>i) c=add(c,dpflip[n-j-i-1]);
         else c=add(c,valid());
         // finv
         s[n-1]='1';
         for(j=1;j<=i&&n-j-1>i;j++) {
            if(s[j]=='0') c=add(c,tp[n-j-i-2]);
            s[n-j-1]='1'-s[j]+'0';
         }
         if(j>i) c=add(c,dpfinv[n-j-i-1]);
         else c=add(c,valid());
      } else {
         c=valid();
      }
      if(c<=k) {
         k-=c;
         s[i]='1';
      }
      //s[i+1]=0;
      //puts(s);
      //printf("> %lld\n",c);
   }
   s[n]='\0';
   puts(s);
   return 1;
}

int main(void)
{
   pre();
   while(cin >> n >> k)
      if(!solve()) cout << "-1" << endl;
   return 0;
}