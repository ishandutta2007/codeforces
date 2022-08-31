/*
***************************************************************
Author           : Ishan Dutta
Email            : ishandutta2007@gmail.com
Facebook         : http://www.facebook.com/ishan.dutta
Blog             : tessellationsoftechnology.wordpress.com
Topcoder Handle  : Ishandutta2007
Codeforces Handle: ishandutta2007
Spoj Username    : ishandutta2007
Codechef Username: ishandutta2007
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

#define sp system("PAUSE")

/* ****************************************************************** */
// \_/\_/\_/\_/\_/---Fast IO using getchar_unlocked---\_/\_/\_/\_/\_/
/* ****************************************************************** */
/*
void getint(int &res){
   int c = 'a';
   while (!(c >= '0' && c <= '9') && c != '-') c = getchar_unlocked();//
   int c2;
   if (c != '-')
     c2 = c;
   else
     c2 = '0';
   res = 0;
   while((c2 >= '0' && c2 <= '9')){
     res = (res << 3) + (res << 1) + (c2 - '0');
     c2 = getchar_unlocked();
   }
   //return res * (c == '-' ? -1 : 1);
}
*/
using namespace std;
/* ****************************************************************** */
// \_/\_/\_/\_/\_/\_/---Actual Code Starts Here---\_/\_/\_/\_/\_/\_/
/* ****************************************************************** */
bool isP[101001];
int primes[101010];
int primecnt,f;
int sieve(){
  int ctr=0;
  for(int i=2;i<10000;i++)isP[i]=1;
  for(int i=2;i<10000;i++){
    if(isP[i]==1){
      primes[ctr++]=i;
      for(int j=i*i;j<100000 && i<10000;j+=i){
          isP[j]=0;
      }
    }
  }    
  return ctr;
}
  
vector <int> fac;
int factorise(int num){
  fac.clear();
  int ctr=0;
  while(num!=1 && ctr<primecnt){
    while(num%primes[ctr]==0){
      num/=primes[ctr];
      fac.push_back(primes[ctr]);
    }
    ctr++;
  }
  if(num>1){fac.push_back(num);ctr++;}
  return fac.size();
}
map <int,bool> mp;
set <int >s;
set<int>::iterator it,itlow,itup;

void check(int fno,int p){
  s.insert(p);
  if(fno==f)return;
  check(fno+1,p*fac[fno]);
  check(fno+1,p);
}
int main(){
//freopen (file".in", "r", stdin);
//freopen (file".out", "w", stdout);
  primecnt=sieve();
  int a,b;s(a);s(b);
  int g=__gcd(a,b);
  //lagest factor of g within a b
  f=factorise(g);
  mp.clear();
  s.clear();
  check(0,1);
//  cout<<g<<endl;
  //REP(i,f)cout<<fac[i]<<" ";cout<<endl;
//  for(itlow=s.begin();itlow!=s.end();itlow++)cout<<*itlow<<" ";cout<<endl;
  
  int n;s(n);
  while(n--){
  int l,h;s(l);s(h);//  for(itlow=s.begin();itlow!=s.end();itlow++)cout<<*itlow<<" ";cout<<endl;
    if(*s.rbegin()<h){
       if(*s.rbegin()>=l )pn(*s.rbegin());
       else psn("-1");
       continue;
    }
    itlow=s.lower_bound (h);//cout<<*itlow<<endl;
    if(*itlow==h)pn(h);
    else {
       --itlow;
       if(*itlow>=l)pn(*itlow);
       else psn("-1");
    }
  }
//sp;
  return 0;
}