#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define ll long long
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n;
int x[200005];

ll pref[200005];
ll sum(int lo, int hi){return pref[hi+1] - pref[lo];}

class frac{
public:
  ll a, b;
};
bool operator<(frac a, frac b){return a.a*b.b < a.b*b.a;}
bool operator>(frac a, frac b){return a.a*b.b > a.b*b.a;}

frac func(int m, int l){
  return {sum(m-l, m) + sum(n-l, n-1) - (ll)(2*l+1) * (ll)x[m], (2*l+1)};
}

int opt(int m){
  int lo = 0, hi = min(m, n-1-m), m1, m2;
  while (hi-lo > 2){
    m1 = (lo*2+hi) / 3;
    m2 = (lo+hi*2) / 3;
    if (func(m, m1) > func(m, m2)) hi = m2;
    else lo = m1;
  }
  while (lo != hi){
    if (func(m, lo) < func(m, hi)) ++lo;
    else --hi;
  }
  return lo;

}

int main(){
  cin >> n;
  REP(i,n) scanf("%d", x+i);
  sort(x, x+n);
  REP(i,n) pref[i+1] = pref[i] + x[i];

  int best = 0, b2 = 0;
  REP(i,n){
    int t = opt(i);
    if (func(i, t) > func(best, b2)) best = i, b2 = t;
  }

  cout << b2*2+1 << endl;
  REP(i,b2+1) printf("%d ", x[best-i]);
  REP(i,b2) printf("%d ", x[n-1-i]);
  cout << endl;
  
  return 0;
}