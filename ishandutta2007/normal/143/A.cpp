//#include "stdafx.h";
/****************************************************************    
Author               : Ishan Dutta                                   
Email                : ishandutta2007@gmail.com                      
Facebook account     : https://www.facebook.com/ishan.dutta           
Google Plus account  : https://plus.google.com/103396620471988185074 
Blog                 : tessellationsoftechnology.wordpress.com       
Topcoder Handle      : Ishandutta2007                                
Codeforces Handle    : ishandutta2007                                
Codechef Username    : ishandutta2007                                
Spoj Username        : ishandutta2007                                
UVA Username         : ishandutta2007                                
Team Name            : Entropy                                       
/*******************************************************************/
// \_/\_/\_/\_/\_/\_/\_/\_/---Headers---\_/\_/\_/\_/\_/\_/\_/\_/\_/      
/*******************************************************************/
//C headers
#include<stdio.h>
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
using namespace std;
/********************************************************************/
// \_/\_/\_/\_/\_/\_/\_/---Frequently used macros---\_/\_/\_/\_/\_/\_/
/********************************************************************/

#define MOD 1000000007
#define INF 1000000000

/********************************************************************/
// \_/\_/\_/\_/\_/\_/\_/\_/\_/---Shorthands---\_/\_/\_/\_/\_/\_/\_/\_/
/********************************************************************/

#define ll long long
#define ld long double
#define F first
#define S second
#define PB push_back
#define PPB pop_back
#define MP make_pair

#define SZ(c)       (int)(c).size()
#define set(x,v)    memset((x),(int)(v),sizeof(x));

#define ALL(x)      (x).begin(),(x).end()
#define SORT(x)     sort(ALL(x))
#define REV(c)      reverse(ALL(c))

#define FOR(i,a,b)  for(int i=(int)(a);i<=(int)(b);i++)
#define REP(i,n)    FOR(i,0,(n-1))

#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define REPD(i,n)   FOR(i,(n-1),0)

#define IT(it,x)    for(typeof((x).begin()) it = (x).begin();it!=(x).end();++it)  

#define tst         int T;scanf("%d",&T);for(int testno=1;testno<=T;testno++)
#define s(x)        scanf("%d",&x)
#define sl(x)       scanf("%lld",&x)
#define ss(x)       scanf("%s",x)

#define p(x)        printf("%d",x)
#define pl(x)       printf("%lld",x)
#define ps(x)       printf("%s",x)

#define pn(x)       printf("%d\n",x)
#define pln(x)      printf("%lld\n",x)
#define psn(x)      printf("%s\n",x)

#define PII pair< int,int >
#define PIL pair< int,long long >
#define PLI pair< long long,int >
#define VI vector< int >
#define VLL vector< long long >
#define MII map< int,int >
#define PQ priority_queue

#define sp system("PAUSE")

template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
/********************************************************************/
// \_/\_/\_/\_/\_/---Fast I/P using getchar_unlocked---\_/\_/\_/\_/\_/
/********************************************************************/

int gi(){
   int c = 'a';
   while (!(c >= '0' && c <= '9') && c != '-') c = getchar();//_unlocked();//();//
   int c2;
   if (c != '-')
     c2 = c;
   else
     c2 = '0';
   int res = 0;
   while((c2 >= '0' && c2 <= '9')){
     res = (res << 3) + (res << 1) + (c2 - '0');
     c2 = getchar();//_unlocked();//();//
   }
   return res * (c == '-' ? -1 : 1);
}
int r1,r2,c1,c2,d1,d2;
int main(){
   s(r1);s(r2); 
   s(c1);s(c2); 
   s(d1);s(d2);
   int aa=(r1-d2+c1);
   int bb=(r1+d2-c1);
   int cc=(c1-d1+r2);
   int dd=(d1-c1+r2);
   if(aa==bb || aa==cc || aa==dd ||
      bb==cc ||bb==dd || 
      cc==dd || 
      aa<2|| bb<2|| cc<2|| dd<2||
      aa>18|| bb>18|| cc>18|| dd>18||
      ((aa&1)==1)||((bb&1)==1)||((cc&1)==1)||((dd&1)==1)
      ){
       cout<<"-1";
   }
   else{
       cout<<aa/2<<" "<<bb/2<<endl; 
       cout<<cc/2<<" "<<dd/2;
   }
//   sp; 
   return 0; 
}