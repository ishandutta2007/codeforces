#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second
#define point pair < ll, ll >

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n;
pair < pii, pii > in[100005];

class cmp{
public:
  bool operator()(int a, int b){
    if (in[a].x.y != in[b].x.y) return in[a].x.y < in[b].x.y;
    return a < b;
  }
};

const int offset = (1<<19);
set < int, cmp > T[2*offset];

void remove(int id, int lo, int hi, int x, int y, int v){
  if (lo > x || hi < x) return;
  T[id].erase(v);
  if (lo == hi) return;
  int m = (lo+hi)/2;
  remove(id*2, lo, m, x, y, v);
  remove(id*2+1, m+1, hi, x, y, v);
}

vector < int > Rget;
void get(int id, int lo, int hi, int x, int y){
  if (lo > x) return;
  if (hi <= x){
    for (auto t : T[id]){
      if (in[t].x.y > y) break;
      Rget.pb(t);
    } return;
  }
  int m = (lo+hi)/2;
  get(id*2, lo, m, x, y);
  get(id*2+1, m+1, hi, x, y);
}

void add(int x, int y, int v){
  T[x+offset].insert(v);
}

void remove(int x, int y, int id){remove(1, 0, offset-1, x, y, id);}
vector < int > get(int x, int y){
  Rget.clear();
  get(1, 0, offset-1, x, y);
  return Rget;
}

int prevprev[100005];

int main(){
  cin >> n;
  REP(i,n) scanf("%d%d%d%d", &in[i].x.x, &in[i].x.y, &in[i].y.x, &in[i].y.y);

  vector < int > sazm = {0};
  REP(i,n){
    sazm.pb(in[i].x.x);
    sazm.pb(in[i].x.y);
    sazm.pb(in[i].y.x);
    sazm.pb(in[i].y.y);
  } sort(sazm.begin(), sazm.end());
  sazm.erase(unique(sazm.begin(), sazm.end()), sazm.end());
  REP(i,n){
    in[i].x.x = (int)(lower_bound(sazm.begin(), sazm.end(), in[i].x.x) - sazm.begin());
    in[i].x.y = (int)(lower_bound(sazm.begin(), sazm.end(), in[i].x.y) - sazm.begin());
    in[i].y.x = (int)(lower_bound(sazm.begin(), sazm.end(), in[i].y.x) - sazm.begin());
    in[i].y.y = (int)(lower_bound(sazm.begin(), sazm.end(), in[i].y.y) - sazm.begin());
  }

  memset(prevprev, -1, sizeof prevprev);

  REP(i,n) add(in[i].x.x, in[i].x.y, i);
  queue < pair < pii, int > > V;
  for (int id = offset-1; id; --id){
    if (T[id*2].size() > T[id*2+1].size()){
      T[id] = T[id*2];
      for (auto v : T[id*2+1]) T[id].insert(v);
    } else {
      T[id] = T[id*2+1];
      for (auto v : T[id*2]) T[id].insert(v);
    }
  }
  V.push({{0, 0}, -3});

  while (!V.empty()){
    pii t = V.front().x;
    int id = V.front().y;
    V.pop();
    vector < int > V2 = get(t.x, t.y);
    for (auto x : V2) remove(in[x].x.x, in[x].x.y, x);
    for (auto x : V2) V.push({in[x].y, x}), prevprev[x] = id;
  }

  if (prevprev[n-1] == -1){cout << -1 << endl; return 0;}

  int id = n-1;
  vector < int > R;
  while (id >= 0){
    R.pb(id+1);
    id = prevprev[id];
  } reverse(R.begin(), R.end());
  cout << R.size() << endl;
  for (auto x : R) printf("%d ", x); cout << endl;
  
  return 0;
}