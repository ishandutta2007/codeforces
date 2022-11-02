#include <iostream>

using namespace std;

inline long long gcd(long long a,long long b) {
   long long t;
   while(b) {
      t=b;
      b=a%b;
      a=t;
   }
   return a;
}

inline long long max(long long a,long long b) {
   return a>b?a:b;
}
inline long long min(long long a,long long b) {
   return a<b?a:b;
}

int main(void)
{
   long long a,b,m;
   long long ai,bi,at,bt,na,nb,pt,t;
   bool flag;
   while(cin>>a>>b) {
      m=a*b/gcd(a,b);
      ai=bi=0;
      at=bt=0;
      pt=0;
      while(1) {
         na=ai+a;
         nb=bi+b;
         t=min(na,nb);
         if(na==t&&(nb>t||a>b)) flag=0;
         else flag=1;
         if(flag) bt+=t-pt;
         else at+=t-pt;
         if(na==t) ai=na;
         if(nb==t) bi=nb;
         if(t==m) break;
         pt=t;
      }
//      cout << at << bt << endl;
      if(at>bt) cout << "Dasha" << endl;
      else if(at<bt) cout << "Masha" << endl;
      else cout << "Equal" << endl;
   }
   return 0;
}