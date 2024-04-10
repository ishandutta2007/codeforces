#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
pair<pii, pii> rect[200005];

// output size at most 4
vector<int> f(){
  vector<pii> sweep;
  REP(i,n){
    sweep.pb({rect[i].x.x, -1});
    sweep.pb({rect[i].y.x, +1});
  }
  vector<int> output;
  sort(sweep.begin(), sweep.end());
  int cnt = 0;
  for (auto t : sweep){
    bool check = false;
    check |= cnt >= n-1;
    cnt -= t.y;
    check |= cnt >= n-1;
    if (check) output.pb(t.x);
  }
  return output;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> rect[i].x.x >> rect[i].x.y >> rect[i].y.x >> rect[i].y.y;

  vector<int> vx, vy;
  vx = f();
  REP(i,n) swap(rect[i].x.x, rect[i].x.y), swap(rect[i].y.x, rect[i].y.y);
  vy = f();
  REP(i,n) swap(rect[i].x.x, rect[i].x.y), swap(rect[i].y.x, rect[i].y.y);

  for (auto x : vx)
    for (auto y : vy){
      int cnt = 0;
      REP(i,n)
	if (rect[i].x.x <= x && x <= rect[i].y.x)
	  if (rect[i].x.y <= y && y <= rect[i].y.y)
	    ++cnt;
      if (cnt >= n-1){
	cout << x << " " << y << endl;
	return 0;
      }
    }

  assert(false);

  return 0;
}