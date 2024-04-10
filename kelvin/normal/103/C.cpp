#include <iostream>

using namespace std;

typedef long long ll;

ll n,k;
int qn;
ll k1,k2,keven,kodd;

inline ll max(ll a,ll b) { return a>b?a:b; }
inline ll min(ll a,ll b) { return a<b?a:b; }

inline char qry(ll x) {
   x=n-x;
   if(x<kodd) {
      return 'X';
   } else if(x<kodd+2*keven) {
      if((x-kodd)&1) return '.';
      else return 'X';
   } else {
      return '.';
   }
}

int main(void)
{
   int i;
   ll x;
   while(cin>>n>>k>>qn) {
      keven=min(k-((n&1)?1:0),n-k);
      kodd=k-keven;
//      cout << "> "<<keven<<kodd<<endl;
      for(i=0;i<qn;i++) {
         cin>>x;
         if(k) cout<<qry(x);
         else cout<<'.';
      }
      cout << endl;
   }
   return 0;
}