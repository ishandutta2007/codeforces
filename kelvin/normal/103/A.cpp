#include <iostream>
#define MAXN 105

using namespace std;

typedef long long ll;

ll x[MAXN],re[MAXN];

int main(void)
{
   int i,j,n;
   ll s;
   while(cin >> n) {
      s=0;
      for(i=0;i<n;i++)
         cin >> x[i];
      re[n]=0;
      for(i=n-1;i>=0;i--)
         re[i]=re[i+1]+x[i]-1;
      for(i=0;i<n;i++)
         s+=x[i]+re[i+1];
      cout << s << endl;
   }
   return 0;
}