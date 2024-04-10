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
typedef pair < int, int > pii;
typedef vector < int > perm;

perm operator*(perm a, perm b){
  perm c(a.size());
  REP(i,a.size()) c[i] = a[b[i]];
  return c;
}

int num(perm p){
  bitset < 22 > bio;
  bio.reset();
  int r = 0;
  REP(i,p.size()) if (!bio[i]){
    int tmp = 0;
    int x = i;
    while (!bio[x]){
      bio[x] = 1;
      ++tmp;
      x = p[x];
    } r += tmp-1;
  } return r;
}

pii tr(perm p){
  pii r = {-1, -1};
  REP(i,p.size()) if (p[i] != i) r.y = r.x, r.x = i;
  assert(r.y != -1);
  return r;
}

void no(){cout << "NO\n"; exit(0);}
void yes(){cout << "YES\n"; exit(0);}

int n, m;
vector < perm > v;

set < pii > trr(perm p){
  bitset < 22 > bio;
  bio.reset();
  set < pii > all;
  REP(i,p.size()) if (!bio[i]){
    vector < int > tmp = {i};
    while (!bio[tmp.back()]) bio[tmp.back()] = 1, tmp.pb(p[tmp.back()]);
    REP(a,tmp.size()) REP(b,tmp.size()) if (tmp[a] != tmp[b]) all.insert({tmp[a], tmp[b]});
  } return all;
}

set < pii > operator*(set < pii > a, set < pii > b){
  set < pii > r;
  for (auto t : a) if (b.count(t)) r.insert(t);
  return r;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  v.resize(n, perm(m));
  REP(i,n) REP(j,m) cin >> v[i][j], --v[i][j];

  vector < perm > v1, v2;

  REP(i,v.size()){
    if (v[i] == v[i]*v[i]){v.erase(v.begin()+i); --i; continue;}
    if (num(v[i]) > 2) no();
    if (num(v[i]) == 1) v1.pb(v[i]);
    else v2.pb(v[i]);
  }

  if (v2.empty()) yes();
  if (!v1.empty()){
    pii r = tr(v1.front());
    for (auto p : v1) if (tr(p) != r) no();
    for (auto p : v2) if (num(p*v1.front()) != 1) no();
    yes();
  }

  set < pii > r = trr(v2.front());
  for (auto p : v2) r = r*trr(p);
  if (r.empty()) no();
  else yes();
  
  return 0;
}