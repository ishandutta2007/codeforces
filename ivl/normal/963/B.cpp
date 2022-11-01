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
int p[200005];

vector<int> E[200005];
int cnt[200005];

vector<int> preorder;

void rootaj(int id, int par){
  for (auto t : E[id])
    if (t != par)
      rootaj(t, id);
  preorder.pb(id);
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  FOR(i,1,n+1){
    cin >> p[i];
    if (p[i]) E[i].pb(p[i]), E[p[i]].pb(i);
  }

  FOR(i,1,n+1) cnt[i] = (int)E[i].size();

  if (n%2 == 0){cout << "NO" << endl; return 0;}

  cout << "YES" << endl;
  rootaj(1, 1);
  vector<int> prev;
  for (auto t : preorder){
    prev.pb(t);
    while (!prev.empty() && cnt[prev.back()]%2 == 0){
      cout << prev.back() << endl;
      for (auto u : E[prev.back()])
	--cnt[u];
      prev.pop_back();
    }
  }

  assert(prev.empty());  

  return 0;
}