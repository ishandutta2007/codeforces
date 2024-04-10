#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pii pair < int, int >
#define pb push_back
#define x first
#define y second
#define ll long long

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n;
int p[1000005];

bool bio[1000005];
int calc(int id){
  int r = 0;
  while (!bio[id]++) id = p[id], ++r;
  return r;
}

map < int, vector < int > > M;
int q[1000005];

void join(int a, int b){
  int x = calc(a);
  REP(i,x){
    q[a] = b;
    a = p[a];
    q[b] = a;
    b = p[b];
  }
}

void neparan(int a){
  int x = calc(a);
  vector < int > v;
  REP(i,x) v.pb(a), a = p[a];
  int t = (x+1) / 2;
  int id = 0;
  REP(i,x){
    int nid = (id+t)%x;
    q[v[id]] = v[nid];
    id = nid;
  }
}

int main(){
  
  cin >> n;
  REP(i,n) scanf("%d", p+i), --p[i];

  REP(i,n) if (!bio[i]) M[calc(i)].pb(i);

  for (auto &x : M) if (x.x%2 == 0 && x.y.size()%2){cout << -1 << endl; return 0;}

  memset(bio, 0, sizeof bio);
  for (auto &x : M){
    if (x.x%2 == 0) REP(i,x.y.size()/2) join(x.y[i*2], x.y[i*2+1]);
    else for (auto y : x.y) neparan(y);
  }
  
  REP(i,n) printf("%d ", q[i]+1); cout << endl;
  
  return 0;
}