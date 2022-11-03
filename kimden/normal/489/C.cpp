#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(x,n) for(int i=0;i<n;i++)cout<<(x)
int main()
{
   int m,s;
   char c;
   cin >> m >> s;
   if(s==0){
      if(m-1){
         cout << "-1 -1";
      }else{
         cout << "0 0";
      }
      return 0;
   }
   if(s>9*m){
      cout << "-1 -1";
      return 0;
   }
   if(9*m-s<=8){
      c = '9';
      c -= (9*m-s);
      rep(c,1);
      rep('9',m-1);
      rep(' ',1);
      rep('9',m-1);
      rep(c,1);
      return 0;
   }
   int j = (s-1)%9;
   c = '9';
   c += j-9;
   rep('1',1);
   rep('0',m-2-(int)((s-1)/9));
   rep(c,1);
   rep('9',(int)((s-1)/9));
   rep(' ',1);
   j = s%9;
   c = '9';
   c += j-9;
   rep('9',(int)(s/9));
   rep(c,1);
   rep('0',m-1-(int)(s/9));
   return 0;
}