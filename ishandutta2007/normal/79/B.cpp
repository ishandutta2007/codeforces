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
vector < pair<int,int> >w;
vector<  pair<int,int> >::iterator ub;    
int main(){
//freopen (file".in", "r", stdin);
//freopen (file".out", "w", stdout);
    int n,m,k,t,a,b,qa,qb;
    s(n);s(m);s(k);s(t);
    REP(i,k){s(a);s(b);w.push_back(make_pair(a,b));}
    SORT(w);
    REP(i,t){
      s(qa);s(qb);
      if(find(ALL(w),make_pair(qa,qb))!=w.end())   cout<<"Waste"<<endl;
      else{
        ub=upper_bound(ALL(w),make_pair(qa,qb));
        int ws=int(ub-w.begin()); 
//        cout<<ws<<endl;
        if((m*(qa-1)+qb-ws)%3==1)               cout<<"Carrots"<<endl;
        else if((m*(qa-1)+qb-ws)%3==2)               cout<<"Kiwis"<<endl;
        else cout<<"Grapes"<<endl;
      }
    }
//sp;
  return 0;
}