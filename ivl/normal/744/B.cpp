#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << setw(3) << setfill('0') <<  __LINE__ << ": " << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef pair < int, int > pii;
typedef long long ll;

int n;
int a[1005];
int b[1005];

int AskNum = 0;

vector < int > ask(vector < int > ind){
  ++AskNum;
  cout << ind.size() << endl;
  for (auto t : ind) cout << t+1 << " ";
  cout << endl;
  vector < int > out(n);
  for (auto &t : out) cin >> t;
  return out;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) a[i] = b[i] = (int)1e9+10;

  vector < pii > v;
  v = {{0, n-1}};
  while (!v.empty()){
    vector < int > ind;
    vector < int > rel;
    vector < pii > v2;
    for (auto t : v){
      int x = t.x, y = t.y;
      int m = (x+y)/2;
      FOR(i,m+1,y+1) rel.pb(i);
      FOR(i,x,m+1) ind.pb(i);
      v2.pb({x, m});
      v2.pb({m+1, y});
    }
    vector < int > resp = ask(ind);
    for (auto t : rel) a[t] = min(a[t], resp[t]);
    v.clear();
    for (auto t : v2)
      if (t.x != t.y)
	v.pb(t);
  }

  v = {{0, n-1}};
  while (!v.empty()){
    vector < int > ind;
    vector < int > rel;
    vector < pii > v2;
    for (auto t : v){
      int x = t.x, y = t.y;
      int m = (x+y)/2;
      FOR(i,m+1,y+1) ind.pb(i);
      FOR(i,x,m+1) rel.pb(i);
      v2.pb({x, m});
      v2.pb({m+1, y});
    }
    vector < int > resp = ask(ind);
    for (auto t : rel) b[t] = min(b[t], resp[t]);
    v.clear();
    for (auto t : v2)
      if (t.x != t.y)
	v.pb(t);
  }

  cout << -1 << endl;
  REP(i,n) cout << min(a[i], b[i]) << " ";
  cout << endl;

  TRACE(AskNum);
  
  return 0;
}