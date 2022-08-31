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

using namespace std;
/********************************************************************/
// \_/\_/\_/\_/\_/\_/---Actual Code Starts Here---\_/\_/\_/\_/\_/\_/
/********************************************************************/

int n,m;
string nam, nam1, nam2;
map< string , int > mp1;
map< int ,string  > mp2;
vector<string>ans;
int anslen;
bool ad [20][20];
void fillans(int i){
   ans.clear();
   for(int j=0;j<n;j++){
     if(i&(1<<j))ans.PB(mp2[j]);
   }
   anslen=ans.size();
}

int main(int argc, char * argv[]){
//time_t seconds;  time(&seconds); srand((unsigned int)seconds);
//freopen("A-small.in", "r", stdin); freopen ("file.out", "w", stdout);
   cin>>n>>m;
   REP(i,n){
     cin>>nam;
     mp1[nam]=i;
     mp2[i]=nam;
   }
   
   REP(i,m){
      cin>>nam1>>nam2;
      int i1=mp1[nam1];
      int i2=mp1[nam2];
      ad[i1][i2]=1;
      ad[i2][i1]=1;
   }   
  // REP(i,n){REP(j,n)cout<<mp[MP(nam[i],nam[j])]<< " ";cout<<endl;}
   anslen=0;
   for(int i=1;i<(1<<n);i++){
     if(__builtin_popcount(i)<=anslen)continue;
     int flag=1;
     for(int j=0;j<n && flag==1;j++){
      for(int k=0;k<n && flag==1;k++){
        if(j==k)continue;
        if(  i&(1<<j) && i&(1<<k)  ){
             if(ad[j][k]==1 ||  ad[k][j]==1)flag=0;
        }
        if(flag==0)break;
      }
      if(flag==0)break;
     }
     if(flag==1)fillans(i);
   }
   cout<<ans.size()<<endl;
   SORT(ans);
   for(int i=0;i<ans.size();i++)cout<<ans[i]<<endl;
//sp;
  return 0; 
}