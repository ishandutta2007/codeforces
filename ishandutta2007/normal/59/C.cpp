/*
***************************************************************
Author           : Ishan Dutta
Email            : ishandutta2007@gmail.com
Blog             : tessellationsoftechnology.wordpress.com
Topcoder Handle  : Ishandutta2007
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

using namespace std;

/* ***************************************************************** */
// \_/\_/\_/\_/\_/\_/\_/\_/\_/---BigInt---\_/\_/\_/\_/\_/\_/\_/\_/\_/
/* ***************************************************************** */

/* ****************************************************************** */
// \_/\_/\_/\_/\_/\_/\_/---Frequently usedno macros---\_/\_/\_/\_/\_/\_/\_/
/* ****************************************************************** */

#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9

/* ****************************************************************** */
// \_/\_/\_/\_/\_/\_/\_/\_/\_/---Shorthands---\_/\_/\_/\_/\_/\_/\_/\_/\_/
/* ****************************************************************** */

#define ll long long
#define ull unsigned long long

#define vi  vector <int>
#define vii vector <int>:: iterator
#define vl  vector <long long>
#define vli vector <long long>:: iterator


#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define REP(i,n) FOR(i,0,n-1)

#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REPD(i,n) FOR(i,n-1,0)

#define test(t) int t;scanf("%d",&t);while(t--)

#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(x) scanf("%s",&x)

#define p(x) printf("%d",x)
#define pn(x) printf("%d\n",x)

#define pl(x) printf("%lld",x)
#define pln(x) printf("%lld\n",x)


//#define sort(x) sort(x.begin(),x.end());

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(a)   ((a)>0?(a):-(a))
#define swap(a,b) (a)^=(b)^=(a)^=(b)

#define sp system("PAUSE")


/* ****************************************************************** */
// \_/\_/\_/\_/\_/---Fast IO using getchar_unlocked---\_/\_/\_/\_/\_/
/* ****************************************************************** */

int getint(){
   int c = 'a';
   while (!(c >= '0' && c <= '9') && c != '-'){
    //     #ifdef ONLINE_JUDGE
//           c = getchar_unlocked();
   //      #elseif
        c = getchar();
   //      #endif
   }
   int c2;
   if (c != '-')
     c2 = c;
   else
     c2 = '0';
   int res = 0;
   while((c2 >= '0' && c2 <= '9')){
     res = (res << 3) + (res << 1) + (c2 - '0');
//     #ifdef ONLINE_JUDGE
//       c2 = getchar_unlocked();// 
//     #elseif
       c2 = getchar();
//     #endif
 
}
   return res * (c == '-' ? -1 : 1);
}
 


/* ****************************************************************** */
// \_/\_/\_/\_/\_/---Fast IO using fread_unlocked---\_/\_/\_/\_/\_/
/* ****************************************************************** */

#ifndef FASTIO
char *ipos, *opos, InpFile[20000000], OutFile[20000000], DIP[20];

inline int input(int flag=0) { 
  while(*ipos <= 32) ++ipos;
  if ( flag ) return (*ipos++ - '0'); /* For getting Boolean Characters */
  int x=0, neg = 0;char c;
  while( true ) {
    c=*ipos++; if(c == '-') neg = 1;
    else {
      if (c<=32) return neg?-x:x;
      x=(x<<1)+(x<<3)+c-'0';
    }
  }
}

inline void output(int x,int flag) {
  int y,dig=0;
  while (x||!dig) { y=x/10;DIP[dig++]=x-((y << 3) + (y << 1))+'0';x=y;}
  while (dig--) *opos++=DIP[dig];
  *opos++= flag ? '\n' : ' ';
}

inline void InitFASTIO() {
  ipos = InpFile; opos = OutFile;
//  #ifdef ONLINE_JUDGE
//  fread_unlocked(InpFile,20000000,1,stdin);
//  #elseif
  fread(InpFile,20000000,1,stdin);
//  #endif
}

inline void FlushFASTIO() {
//  #ifdef ONLINE_JUDGE
//  fwrite_unlocked(OutFile,opos-OutFile,1,stdout);
//  #elseif
  fwrite(OutFile,opos-OutFile,1,stdout);
//  #endif
}
#endif 

/* ****************************************************************** */
// \_/\_/\_/\_/\_/\_/---Frequently needed templates---\_/\_/\_/\_/\_/\_/
/* ****************************************************************** */
inline int bitcount(int a){
  return a==0?0: bitcount(a>>1)+(a&01);
}
inline int gcd (int a,int b){
  if(a>b) return gcd(b,a);
  return a==0?b:gcd( (b)%(a),a);
}
inline ull gcd(ull a,ull b){
  if(a>b) return gcd(b,a);
  return a==0?b:gcd( (b)%(a),a);
}
inline ull bigpow(ull a, ull n, ull mod) {
	ull res = 1;
	ull p = a % mod;
	for (; n; n >>= 1){
		if (n & 1)res = (res * p) % mod;
		p = (p * p) % mod;
	}
	return res % mod;
}
inline ull inv(ull a, ull mod) {return bigpow(a,mod-2,mod);}
/* ****************************************************************** */
// \_/\_/\_/\_/\_/\_/---Actual Code Starts Here---\_/\_/\_/\_/\_/\_/
/* ****************************************************************** */
int target;
char a[1010];
map< char, int >m;

char getnewchar(){
     for(char i='a';i<='z';i++)
       if(m[i]==0){m[i]=1;return i;}
     return 0;
}

int main(){
   s(target);ss(a);
   int l=strlen(a);
   
   //auto filling
   REP(i,(l+1)/2/*+l%2*/) {
            if(a[i]=='?' && a[l-1-i]!='?') a[i]=a[l-1-i];
            else if(a[i]!='?' && a[l-1-i]=='?') a[l-1-i]=a[i];
   }
   //mow we can forget about palindrome

   //check if sting is input as impossible to become palindrome
   int flag=1;REP(i,(l+1)/2/*+l%2*/) if(a[i]!=a[l-1-i]) {flag=0;break;}
   if(flag==0){printf("IMPOSSIBLE\n");/*sp;*/return 0;}

   //count quetion marks in 1st half
   int maxnw=0; REP(i,(l+1)/2/*+l%2*/) if(a[i]=='?') maxnw++;

   //count no of letters usedno till now and mark them
   int usedno=0;
   REP(i,(l+1)/2/*+l%2*/){
        if(a[i]!='?')
              if(m[a[i]]==0){
                usedno++;m[a[i]]=1;
              }
   }

   if(usedno>target){printf("IMPOSSIBLE\n");/*sp;*/return 0;}
   if(usedno+maxnw<target){printf("IMPOSSIBLE\n");/*sp;*/return 0;}

//cout<<target<<" "<<usedno<<" "<<maxnw<<endl;
   REP(i,(l+1)/2/*+l%2*/){
     if(a[i]=='?'){
           if(target-usedno<maxnw) {a[i]=a[l-1-i]='a';maxnw--;}
           else if(target-usedno==maxnw){
                char t=getnewchar();if(t==0){flag=0;break;}
                a[i]=a[l-1-i]=t;usedno++;maxnw--;
           }
//           else {flag=0;break;}
     }
   }
   
   if(flag==0)printf("IMPOSSIBLE\n");
   else printf("%s\n",a);
//   sp;
   return 0;
}