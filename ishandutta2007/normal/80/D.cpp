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
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define REP(i,n) FOR(i,0,(n-1))

#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define REPD(i,n) FOR(i,(n-1),0)

#define reset(x) memset((x),0,sizeof(x));
#define negset(x) memset((x),-1,sizeof(x));
#define set(x) memset((x),1,sizeof(x));

#define all(x) (x).begin(),(x).end()

#define test(t) int t;scanf("%d",&t);while(t--)
#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)

#define p(x) printf("%d",x)
#define pl(x) printf("%lld",x)
#define ps(x) printf("%s",x)

#define pn(x) printf("%d\n",x)
#define pln(x) printf("%lld\n",x)
#define psn(x) printf("%s\n",x)
#define sp system ("PAUSE")
using namespace std;
/* ****************************************************************** */
// \_/\_/\_/\_/\_/\_/---Actual Code Starts Here---\_/\_/\_/\_/\_/\_/
/* ****************************************************************** */
int main(){
  double a,b;
  test(t){
      scanf("%lf %lf",&a,&b);
      //if(a==0.0)printf("0.0000000000\n");
      if(a==0.0 && b==0.0) cout<<"1.0000000000\n";
      else if(a<=4*b) printf("%0.10lf\n",0.5+a/b/16);
      else printf("%0.10lf\n",1.0-b/a);
  }
//  sp;
  return 0;
}