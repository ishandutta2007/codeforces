/*
***************************************************************
Author           : Ishan Dutta
Email            : ishandutta2007@gmail.com
Facebook         : http://www.facebook.com/ishan.dutta
Blog             : tessellationsoftechnology.wordpress.com
Topcoder Handle  : Ishandutta2007
Codeforces Handle: ishandutta2007
Codechef Username: ishandutta2007
Spoj Username    : ishandutta2007
UVA Username     : ishandutta2007
***************************************************************
*/
/* ***************************************************************** */
// \_/\_/\_/\_/\_/\_/\_/\_/---Headers---\_/\_/\_/\_/\_/\_/\_/\_/
/* ***************************************************************** */

//C headers
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<cctype>
#include<cassert>
#include<climits>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<clocale>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>

//containers
#include<vector>
#include<list>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<complex>
#include<string>
#include<stack>
#include<bitset>
#include<istream>
#include<valarray>

//IOs
#include<iostream>
#include<sstream>
#include<iomanip>
#include<fstream>
#include<exception>
#include<ios>
#include<iosfwd>
#include<ostream>
#include<iterator>
#include<stdexcept>
#include<streambuf>

//algorithm & miscellaneous
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<limits>
#include<locale>
#include<memory>
#include<new>

/* ****************************************************************** */
// \_/\_/\_/\_/\_/\_/\_/---Frequently used macros---\_/\_/\_/\_/\_/\_/\_/
/* ****************************************************************** */

#define MOD 1000000007
#define INF 1000000000

/* ****************************************************************** */
// \_/\_/\_/\_/\_/\_/\_/\_/\_/---Shorthands---\_/\_/\_/\_/\_/\_/\_/\_/\_/
/* ****************************************************************** */

#define ll long long
#define F first
#define S second
#define pb push_back

#define SZ(c) (c).size()
#define reset(x) memset((x),0,sizeof(x));
#define negset(x) memset((x),-1,sizeof(x));
#define set(x) memset((x),1,sizeof(x));

#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort(ALL(x))
#define REVERSE(c) reverse(ALL(c))

#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define REP(i,n) FOR(i,0,(n-1))

#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define REPD(i,n) FOR(i,(n-1),0)


#define tst int t;scanf("%d",&t);while(t--)
#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)

#define p(x) printf("%d",x)
#define pl(x) printf("%lld",x)
#define ps(x) printf("%s",x)

#define pn(x) printf("%d\n",x)
#define pln(x) printf("%lld\n",x)
#define psn(x) printf("%s\n",x)

#define sp system("PAUSE")

/* ****************************************************************** */
// \_/\_/\_/\_/\_/---Fast IO using getchar_unlocked---\_/\_/\_/\_/\_/
/* ****************************************************************** */
/*
int gi(){
   int c = 'a';
   while (!(c >= '0' && c <= '9') && c != '-') c = getchar_unlocked();//();//
   int c2;
   if (c != '-')
     c2 = c;
   else
     c2 = '0';
   int res = 0;
   while((c2 >= '0' && c2 <= '9')){
     res = (res << 3) + (res << 1) + (c2 - '0');
     c2 = getchar_unlocked();//();//
   }
   return res * (c == '-' ? -1 : 1);
}
*/
using namespace std;
/* ****************************************************************** */
// \_/\_/\_/\_/\_/\_/---Actual Code Starts Here---\_/\_/\_/\_/\_/\_/
/* ****************************************************************** */
int x,y;
bool read() {
         return (cin >>x>>y);
}
void solve() {
    int it;
    for(it=0;y>=2 && x*100+y*10>=220;it++){
       if(!(it&1)){
         if(x>=2){x-=2;y-=2;}
         else if(x==1 && y>=12){x=0;y-=12;}
         else if(x==0 && y>=22){y-=22;}
       }
       else{
         if(y>=22){y-=22;}
         else if(y>=12){x--;y-=12;}
         else if(y>=2){x-=2;y-=2;}
       }
    }
    if(it%2)cout<<"Ciel"<<endl;
    else cout<<"Hanako"<<endl;
}
int main() {
  while(read())solve();
}