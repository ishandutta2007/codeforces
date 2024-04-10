#include <iostream>
#include <string>
#define MAXL 100050

using namespace std;

#define A 0
#define N 1
#define V 2
#define NIL -1

#define M 0
#define F 1

int n;
int s[MAXL];
bool g[MAXL];

inline string sub(const string &t,int x) {
   x=-x;
   if(t.length()<x) return "";
   return t.substr(t.length()-x);
}

inline bool rec(string t) {
   if(sub(t,-4)=="lios") {
      s[n]=A;
      g[n]=M;
   } else if(sub(t,-5)=="liala") {
      s[n]=A;
      g[n]=F;
   } else if(sub(t,-3)=="etr") {
      s[n]=N;
      g[n]=M;
   } else if(sub(t,-4)=="etra") {
      s[n]=N;
      g[n]=F;
   } else if(sub(t,-6)=="initis") {
      s[n]=V;
      g[n]=M;
   } else if(sub(t,-6)=="inites") {
      s[n]=V;
      g[n]=F;
   } else {
      return 0;
   }
   n++;
   return 1;
}

inline bool check() {
   int i,m;
   if(n==1) return 1;
   for(i=1;i<n;i++)
      if(g[i]!=g[i-1]) return 0;
   for(m=0;m<n;m++)
      if(s[m]==N) break;
   if(m==n) return 0;
   for(i=0;i<m;i++)
      if(s[i]!=A) return 0;
   for(i=m+1;i<n;i++)
      if(s[i]!=V) return 0;
   return 1;
}

int main(void)
{
   int i;
   string t;
   n=0;
   while(cin>>t) {
      if(!rec(t)) {
         cout<<"NO"<<endl;
         return 0;
      }
   }
   cout<<(check()?"YES":"NO")<<endl;
   return 0;
}