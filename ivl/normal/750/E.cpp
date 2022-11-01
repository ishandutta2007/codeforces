#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << setw(3) << setfill('0') << __LINE__ << ": " << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

int n, q;
int s[200005];

const int BS = 512;
const int oo = 1e9;

int out[200005];

int brute(int lo, int hi){
  int pref[5] = {0, oo, oo, oo, oo};
  FOR(i,lo,hi+1){
    int t = s[i];
    if (t > 4) continue;
    if (t < 4) pref[t+1] = min(pref[t+1], pref[t]), ++pref[t];
    if (t == 4) ++pref[3], ++pref[4];
  }
  if (pref[4] >= oo) return -1;
  else return pref[4];
}

vector<pair<pii, int>> buckets[200005];

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> q;
  {string tmp; cin >> tmp; REP(i,n) s[i] = tmp[i]-'0';}

  REP(i,n){
    if (s[i] == 2){s[i] = 0; continue;}
    if (s[i] == 0){s[i] = 1; continue;}
    if (s[i] == 1){s[i] = 2; continue;}
    if (s[i] == 7){s[i] = 3; continue;}
    if (s[i] == 6){s[i] = 4; continue;}
    if (s[i] == 3){s[i] = 6; continue;}
    if (s[i] == 4){s[i] = 7; continue;}
  }

  REP(i,q){
    int a, b;
    cin >> a >> b;
    --a, --b;
    if (b-a <= BS){out[i] = brute(a, b); continue;}
    buckets[a/BS].pb({{a, b}, i});
  }

  REP(iii,n) if (!buckets[iii].empty()){
    auto &v = buckets[iii];
    sort(v.begin(), v.end(), [](pair<pii, int> a, pair<pii, int> b){return a.x.y < b.x.y;});
    int lo = BS*(iii+1);
    int mat[5][5];
    REP(i,5) REP(j,5) mat[i][j] = (i != j) * oo;
    int curr = lo;
    for (auto p : v){
      for (; curr <= p.x.y; ++curr){
	int t = s[curr];
	if (t > 4) continue;
	if (t < 4){
	  REP(x,5) mat[x][t+1] = min(mat[x][t+1], mat[x][t]);
	  REP(x,5) ++mat[x][t];
	}
	if (t == 4){
	  REP(x,5) ++mat[x][3], ++mat[x][4];
	}
      }

      int pref[5] = {0, oo, oo, oo, oo};
      FOR(i,p.x.x,lo){
	int t = s[i];
	if (t > 4) continue;
	if (t < 4) pref[t+1] = min(pref[t+1], pref[t]), ++pref[t];
	if (t == 4) ++pref[3], ++pref[4];
      }

      int sol = oo;
      REP(i,5) sol = min(sol, pref[i] + mat[i][4]);
      if (sol == oo) out[p.y] = -1;
      else out[p.y] = sol;
    }
  }

  REP(i,q) cout << out[i] << endl;

  return 0;
}