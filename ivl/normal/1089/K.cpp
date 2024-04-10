#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)

#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int MAX = 1<<20, TOUR = 1<<20;

struct tour {
  ll dur, kraj;
} t[2*TOUR];

tour merge(const tour &a, const tour &b) {
  return { a.dur + b.dur, max(a.kraj + b.dur, b.kraj) };
}

void init() {
  REP(i, TOUR)
    t[i+TOUR] = {0, i};
  for (int i=TOUR-1; i; i--)
    t[i] = merge(t[2*i], t[2*i+1]);
}

void stavi(int pos, int val) {
  pos += TOUR;
  t[pos].dur += val;
  t[pos].kraj += val;

  for (pos /= 2; pos; pos /= 2)
    t[pos] = merge(t[2*pos], t[2*pos+1]);
}

tour vrati(int pos, int lo, int hi, int begin, int end) {
  if (lo >= end || hi <= begin) return {0, -1};
  if (lo >= begin && hi <= end) return t[pos];
  return merge(vrati(2*pos+0, lo, (lo+hi)/2, begin, end),
	       vrati(2*pos+1, (lo+hi)/2, hi, begin, end));  
}

int vreme[MAX], trajanje[MAX];

int main(){
  ios_base::sync_with_stdio(false);

  init();
  
  int qq;
  scanf("%d", &qq);

  FOR(ii, 1, qq+1) {
    char st[3];
    scanf(" %s", st);

    if (st[0] == '?') {
      int tt;
      scanf("%d", &tt);
      printf("%lld\n", vrati(1, 0, TOUR, 0, tt+1).kraj - tt);       
    }
    else if (st[0] == '+') {
      int tt, d;
      scanf("%d%d", &tt, &d);
      trajanje[ii] = d;
      vreme[ii] = tt;
      stavi(tt, d);
    }
    else {
      int ind;
      scanf("%d", &ind);
      stavi(vreme[ind], -trajanje[ind]);
    }
  }
  
  return 0;
}