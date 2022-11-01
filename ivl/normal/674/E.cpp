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
//#define double long double

const double eps = 1e-10;

const int MS = 50;
class Magic{
public:
  double p[MS];
  Magic(){memset(p, 0, sizeof p);}
  double& operator[](int x){return p[x];}
  void display(){
    REP(i,MS) cout << p[i] << " "; cout << endl;
  }
};

Magic All[500005];
int par[500005];

int main(){
  ios_base::sync_with_stdio(false);

  All[1][0] = 1;
  
  int q;
  cin >> q;

  int CNT = 2;
  REP(j,q){
    int t, v;
    cin >> t >> v;
    if (t == 1){
      par[CNT] = v;
      double curr = 1;
      double prev = 0;
      int id = CNT;
      REP(i,MS-1){
	id = par[id];
	double tmp = All[id][i+1];
	All[id][i+1] = (All[id][i+1] - prev/2) / (1 - prev/2);
	All[id][i+1] = All[id][i+1] + curr/2 - All[id][i+1]*curr/2;
	prev = tmp;
	curr = All[id][i+1];
	if (id == 1) break;
      } ++CNT;
    } else {
      double e = 0;
      FOR(ii,1,MS) e += All[v][ii];
      cout << setprecision(25) << e << endl;
    }
  }
  
  return 0;
}