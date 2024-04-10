#include <bits/stdc++.h>
#define int LL
using namespace std;
#define PII pair<int, int>
#define VI vector<int>
#define VPII vector<PII>
#define LL long long
#define LD long double
#define f first
#define s second
#define MP make_pair
#define PB push_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for(int i = (b); i <= (int)(e); ++i)
#define FORD(i, b, e) for(int i = (b); i >= (int)(e); --i)
 
#define sim template<class n
sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
sim> auto operator << (ostream &p, n y) ->
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type 
{int o = 0; p << "{"; for(auto c: y) {if(o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
sim, class s> void mini(n &p, s y) {if(p>y) p = y;}
sim, class s> void maxi(n &p, s y) {if(p<y) p = y;}
#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif 
 
#define I(x) #x " =", (x), " "
#define A(a, i) #a "[" #i " =", i, "] =", a[i], " "
 
LL sumn(LL n)
  {
  return n * (n+1) / 2;
  }
LL sum_seg(LL a, LL b)
  {
  return sumn(b) - sumn(a-1);
  }
 
void solve()
  {
  int n;
  cin >> n;
  LL x;
  cin >> x;
  VI V;
  REP(i, n)
    {
    int a;
    cin >> a;
    V.PB(a);
    }
  REP(i, n)V.PB(V[i]);
  int end = 0;
  LL sum = 0;
  LL sum2 = 0;
  LL best_res = 0;
  REP(i, n)
    {
    while(sum < x)
      {
      sum += V[end];
      sum2 += sumn(V[end]);
      end++;
      }
    // przedzia [i, end-1], end -1 jest czciowo
 
    LL ile = x - (sum - V[end-1]);
    maxi(best_res, sum2 - sumn(V[end-1]) + sumn(ile));
 
    debug(i, end-1, best_res);
 
    sum -= V[i];
    sum2 -= sumn(V[i]);
    }
  debug(best_res);
 
  end = 2*n-1;
  sum = 0;
  sum2 = 0;
  FORD(i, 2*n-1, n)
    {
    while(sum < x)
      {
      sum += V[end];
      sum2 += sumn(V[end]);
      end--;
      }
    // przedzia [i, end-1], end -1 jest czciowo
 
    LL ile = x - (sum - V[end+1]);
    maxi(best_res, sum2 - sumn(V[end+1]) + sum_seg(V[end+1]-ile+1, V[end+1]));
 
    sum -= V[i];
    sum2 -= sumn(V[i]);
    }
  cout << best_res << endl;
  }
 
int32_t main()
  {
  ios_base::sync_with_stdio(0);
  solve();
  }