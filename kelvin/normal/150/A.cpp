#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXVAL 10000000

using namespace std;

long long x;
int pn;
long long pr[MAXVAL];
bool np[MAXVAL]={0};

inline void gen() {
   pn=0;
   pr[pn++]=2;
   for(int i=3;i<MAXVAL;i+=2) {
      if(np[i]) continue;
      pr[pn++]=i;
      if(i>4000) continue;
      for(int j=i*i;j<MAXVAL;j+=i)
         np[j]=1;
   }
}

inline void solve() {
   vector<long long> fac;
   long long m=x;
   for(int i=0;i<pn&&pr[i]*pr[i]<=m;i++) {
      while(m%pr[i]==0) {
         m/=pr[i];
         fac.push_back(pr[i]);
      }
   }
   if(m>1) fac.push_back(m);
   if(fac.size()==2) {
      puts("2");
      return;
   }
   if(fac.size()<=1) {
      puts("1\n0");
      return;
   }
   cout << 1 << endl << fac[0]*fac[1] << endl;
}

int main(void)
{
   gen();
   while(cin>>x)
      solve();
   return 0;
}