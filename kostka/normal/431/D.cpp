//Bartek Kostka

//Don't bother looking.
//You are not prepared. 

#include<algorithm>
#include<bitset>
#include<cassert>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>
#include<utility>

using namespace std;

#define VAR(a,b) __typeof(b) a=(b)
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define MP make_pair
#define PB push_back
#define FT first
#define SD second
#define SZ(x) ((int)((x).size()))
#define TAKE(a) int (a); scanf("%d",&(a));
#define TAKE2(a,b) int (a),(b); scanf("%d %d",&(a),&(b));
#define TAKE3(a,b,c) int (a),(b),(c); scanf("%d %d %d",&(a),&(b),&(c));
#define DEBUG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define DEBUGV(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS TAKE(ttt)while(ttt--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define MAXI(a,b) (a)=max((a),(b));
#define MINI(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);
#define ST static
#define IN inline
#define PII pair<int,int>
#define LL long long
#define VI vector<int>
#define VII vector < PII >
#define LD long double
ST IN void WRITE(int a) { printf("%d\n",a); }
ST IN void WRITE2(int a, int b) { printf("%d %d\n", a, b); }
const int S9 = 1000000007, S6 = 1000007, S5 = 100007, S4 = 10007, S3 = 1007 , S2 = 107;
const double E2 = 0.01, E4 = 0.0001, E6 = 0.000001, E8 = 0.00000001;

unsigned long long bity[65][65];

long long liczbabitow(long long t, int a)
{
  unsigned long long dwojki = 1LL;
  int count = 0;
  while(dwojki < t)
  {
    dwojki *= 2;
    count++; 
  }
  unsigned long long wyn = 0;
  for(int i=count; i>=0; i--)
  {
    if(t >= dwojki)
    {
      t -= dwojki;
      wyn += bity[i][a--];
      if(wyn > 1000LL*1000*1000*1000*1000*1000+7)
        return 1000LL*1000*1000*1000*1000*1000+7;
    }
    if(a<0)
      break;
    if(t==0)
      break;
    dwojki /= 2;
  }
  return wyn;
}

int main()
{
  long long m;
  int kk;
  scanf("%lld%d", &m, &kk);
  long long start = 1LL;
  int licz = 0;
  bity[0][1] = 1;
  while(licz != 64)
  {
    start *= 2;
    licz++;
    for(int i=1; i<=64; i++)
    {
      bity[licz][i] = bity[licz-1][i] + bity[licz-1][i-1];
      if(bity[licz][i] > 1000LL*1000*1000*1000*1000*1000+7)
        bity[licz][i] = 1000LL*1000*1000*1000*1000*1000+7;
    }
  }
  //printf("%d\n", liczbabitow(m, kk));
  long long p = 0, k = 1000LL*1000*1000*1000*1000*1000+7;
  while(p<k-1)
  {
    long long med = (p+k)/2;
    if(liczbabitow(med, kk) >= m)
      k = med;
    else
      p = med;
  }
  printf("%lld\n", p+1);
  return 0;
}