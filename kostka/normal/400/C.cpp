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

int a[S5], b[S5], c[S5], d[S5], e[S5], f[S5];

int main()
{
  TAKE2(n,m);
  LL x, y, z;
  scanf("%lld%lld%lld", &x, &y, &z);
  TAKE(p);
  FOR(i,p)
    scanf("%d%d", &a[i], &b[i]);
  LL obrot = (x % 4);
  if(obrot==0)
  {
    FOR(i,p)
    {
      c[i] = a[i];
      d[i] = b[i];
    }
  }
  if(obrot==1)
  {
    FOR(i,p)
    {
      d[i] = n-a[i]+1;
      c[i] = b[i];
    }
        swap(m,n);
  }
  if(obrot==2)
  {
    FOR(i,p)
    {
      d[i] = m-b[i]+1;
      c[i] = n-a[i]+1;
    }
  }
  if(obrot==3)
  {
    FOR(i,p)
    {
      c[i] = m-b[i]+1;
      d[i] = a[i];
    }
    swap(m,n);
  }
  if(y%2 != 0)
    FOR(i,p)
      d[i] = m-d[i]+1;
  obrot = ((z*3) % 4);
  if(obrot==0)
  {
    FOR(i,p)
    {
      e[i] = c[i];
      f[i] = d[i];
    }
  }
  if(obrot==1)
  {
    FOR(i,p)
    {
      f[i] = n-c[i]+1;
      e[i] = d[i];
    }
  }
  if(obrot==2)
  {
    FOR(i,p)
    {
      f[i] = m-d[i]+1;
      e[i] = n-c[i]+1;
    }
  }
  if(obrot==3)
  {
    FOR(i,p)
    {
      e[i] = m-d[i]+1;
      f[i] = c[i];
    }
  }
  FOR(i,p)
    printf("%d %d\n", e[i], f[i]);
  return 0;
}