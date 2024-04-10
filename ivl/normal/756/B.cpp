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

const int oo = 1e9;

int n;
int t[100005];

int cost[100005]; // cijena prvih k ticketa

vector<pii> all = {{1, 20}, {90, 50}, {1440, 120}};

int f(int x){
  int p = (int)(upper_bound(t, t+n, x) - t);
  return cost[p];
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> t[i];

  REP(i,n){
    int &sol = cost[i+1];
    sol = oo;

    for (auto p : all)
      sol = min(sol, p.y + f(t[i] - p.x));
    
    cout << sol-cost[i] << endl;
  }
  
  return 0;
}