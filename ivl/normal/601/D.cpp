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

int loga[1000005];
void add(int p, int v){ ++p;
  for (; p < 1000005; p += p & -p)
    loga[p] += v;
}
int sum(int p){ ++p;
  int r = 0;
  for (; p; p -= p & -p)
    r += loga[p];
  return r;
}
int sum(int lo, int hi){
  return sum(hi) - sum(lo-1);
}

int n;
int c[1000005];
char let[1000005];
vector < int > Einput[1000005];

vector < int > ch[1000005];
void Rootaj(int id, int p){
  for (auto x : Einput[id]) if (x != p){
      ch[id].pb(x);
      Rootaj(x, id);
    }
}

int sol[1000005];
bool bio[1000005];

vector < int > red[1000005];

int poin;
vector < int > M[30];
int Solve(int id){
  if (bio[id]++) return sol[id];

  for (auto x : ch[id]) Solve(x);
  //sort(ch[id].begin(), ch[id].end(), [&](int a, int b){return let[a]<let[b];});
  for (auto x : ch[id]) M[let[x]-'a'].pb(x);

  for (auto &x : M){
    if (x.size() == 0) continue;
    if (x.size() == 1){red[id].pb(x.back()); x.clear(); continue;}
    int p = poin++;
    let[p] = let[x.back()];
    for (auto a : x)
      for (auto b : red[a])
	ch[p].pb(b);

    red[id].pb(p);
    x.clear();
  }

  int r = 1;
  for (auto x : red[id]) r += Solve(x);
  
  return sol[id] = r;
}

int main(){

  cin >> n;
  REP(i,n) scanf("%d", c+i);
  scanf("%s", let);
  REP(i,n-1){
    int a, b;
    scanf("%d%d", &a, &b), --a, --b;
    Einput[a].pb(b);
    Einput[b].pb(a);
  } poin = n;
  
  Rootaj(0, 0);
  Solve(0);
  
  int maks = -1000000000;
  REP(i,n) maks = max(maks, sol[i]+c[i]);

  int cnt = 0;
  REP(i,n) if (maks == sol[i]+c[i]) ++cnt;

  cout << maks << endl << cnt << endl;
  
  return 0;
}