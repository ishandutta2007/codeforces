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

using namespace std;

int n;
int a[1<<20];

int main(){
  //ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) scanf("%d", a+i);

  vector < pii > v;
  int p = 0;
  set < int > S;
  REP(i,n){
    if (S.count(a[i])){
      v.pb({p, i});
      p = i+1;
      S.clear();
    } else S.insert(a[i]);
  }

  if (v.empty()){cout << -1 << endl; return 0;}
  v.back().y = n-1;
  cout << v.size() << endl;
  for (auto t : v) printf("%d %d\n", t.x+1, t.y+1);
  
  return 0;
}