#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

#define real long double

using namespace std;

class comp{
public:
  real x, y;
  comp(real a = 0, real b = 0) : x(a), y(b){}
};
comp operator+(comp a, comp b){return {a.x+b.x, a.y+b.y};}
void operator+=(comp &a, comp b){a = {a.x+b.x, a.y+b.y};}
comp operator-(comp a, comp b){return {a.x-b.x, a.y-b.y};}
comp operator*(comp a, comp b){return {a.x*b.x-a.y*b.y, a.x*b.y+a.y*b.x};}
void operator*=(comp &a, comp b){a = {a.x*b.x-a.y*b.y, a.x*b.y+a.y*b.x};}
void operator/=(comp &a, real b){a.x /= b, a.y /= b;}

const real pi = acosl(-1);

comp pw[2][1<<20];
void dft(comp *s, int len, bool inv){
  int ln = 0;
  while ((1<<ln) < len) ++ln;

  int bit = 0;
  FOR(i,1,len){
    int t = len/2;
    for (; bit >= t; t /= 2) bit -= t;
    bit += t;
    if (bit > i) swap(s[i], s[bit]);
  }

  int tmp = (1<<19);
  for (int t = 1; t < len; t *= 2, tmp /= 2)
    for (int i = 0; i < len; i += 2*t)
      REP(j,t){
	comp a = s[i+j], b = s[i+j+t];
	s[i+j] = a + pw[inv][tmp*j] * b;
	s[i+j+t] = a - pw[inv][tmp*j] * b;
      }

  if (inv)
    REP(i,len)
      s[i] /= len;
  
}

int n, k;
int a[1005];

comp p1[1<<20], p2[1<<20];

int main(){
  //ios_base::sync_with_stdio(false);

  REP(i,1<<20) pw[0][i] = {cosl(2*pi/(1<<20)*i), sinl(2*pi/(1<<20)*i)};
  REP(i,1<<20) pw[1][i] = {pw[0][i].x, -pw[0][i].y};

  cin >> n >> k;
  REP(i,n) cin >> a[i];

  int l1 = 0, l2 = 0;

  REP(i,n) p1[a[i]] = {1, 0}, l1 = max(l1, a[i]);
  p2[0] = {1, 0};

  while (k){
    int x = 1;
    while (x < max(l1+l1+1, l1+l2+1)) x *= 2;
    dft(p1, x, false);
    if (k & 1){
      dft(p2, x, false);
      REP(i,x) p2[i] *= p1[i];
      dft(p2, x, true);
      l2 += l1;
      REP(i,x){
	p2[i].y = 0;
	if (p2[i].x > 0.9) p2[i].x = 1;
	else p2[i].x = 0;
      }
    }
    REP(i,x) p1[i] *= p1[i];
    dft(p1, x, true);
    l1 *= 2;
    REP(i,x){
      p1[i].y = 0;
      if (p1[i].x > 0.9) p1[i].x = 1;
      else p1[i].x = 0;
    }
    k >>= 1;
  }

  REP(i,1<<20) if (p2[i].x > 0.9) printf("%d ", i); cout << endl;

  return 0;
}