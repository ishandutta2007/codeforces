#include <stdio.h>
#include <iostream>

using namespace std;

long long initn;
int qn,mod;

long long ql,qr,qb,qt;
int sol;

inline long long min(long long a,long long b) { return a<b?a:b; }
inline long long max(long long a,long long b) { return a>b?a:b; }

inline int add(int a,int b) { return a+b<mod?a+b:a+b-mod; }

inline bool intersect(long long a,long long b,long long c,long long d) {
   return d>=a&&c<=b;
}

void g(long long s,long long d,long long len) {
   if(qt<s) return;
   if(qb>s+d*(len-1)) return;
   long long s1=(max(qb-s,0)+d-1)/d*d+s;
   long long s2=s+(min(qt,s+d*(len-1))-s)/d*d;
   int tmp;
   if((s1+s2)&1) tmp=(s1+s2)%mod*((((s2-s1)/d+1)%mod)/2)%mod;
   else tmp=((s1+s2)/2%mod*(((s2-s1)/d+1)%mod))%mod;
//   printf("%lld %lld %lld, %lld %lld, %lld %lld %d\n",s,d,len,qb,qt,s1,s2,tmp);
   if(s1<=s2) sol=add(sol,tmp);
}

void f(long long li,long long s,long long d,long long len) {
   long long ri=li+len-1;
   //printf("<%lld %lld %lld %lld> %lld %lld \n",li,s,d,len,ql,qr);
   if(ql<=li&&qr>=ri) {
      g(s,d,len);
      return;
   }
   long long ll=(len+1)/2;
   long long mi=li+ll-1;
   if(intersect(li,mi,ql,qr)) f(li,s,d*2,ll);
   if(intersect(mi+1,ri,ql,qr)) f(li+ll,s+d,d*2,len-ll);
}

inline int solve() {
   sol=0;
   f(1,1,1,initn);
   return sol;
}

int main(void)
{
   while(cin >> initn >> qn >> mod) {
      for(int i=0;i<qn;i++) {
         cin >> ql >> qr >> qb >> qt;
         printf("%d\n",solve());
      }
   }
   return 0;
}