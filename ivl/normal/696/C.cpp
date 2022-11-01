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

const int Mod = 1e9 + 7;

inline int add(int a, int b){a += b; if (a >= Mod) return a-Mod; return a;}
inline int mul(int a, int b){return (int)(((ll)a*b)%Mod);}

int kk;
ll a[100005];

int mat[2][2];
int tmp[2][2];
int tmp2[2][2];

int main(){
  ios_base::sync_with_stdio(false);

  cin >> kk;
  REP(i,kk) cin >> a[i];
  mat[0][0] = Mod-1;
  mat[0][1] = 0;
  mat[1][0] = 1;
  mat[1][1] = 2;
  REP(t,kk){
    ll n = a[t];
    tmp[0][0] = tmp[1][1] = 1, tmp[0][1] = tmp[1][0] = 0;
    while (n){
      if (n&1){
	memset(tmp2, 0, sizeof tmp2);
	REP(i,2) REP(j,2) REP(k,2) tmp2[i][j] = add(tmp2[i][j], mul(tmp[i][k], mat[k][j]));
	memcpy(tmp, tmp2, sizeof tmp);
      } n >>= 1;
      memset(tmp2, 0, sizeof tmp2);
      REP(i,2) REP(j,2) REP(k,2) tmp2[i][j] = add(tmp2[i][j], mul(mat[i][k], mat[k][j]));
      memcpy(mat, tmp2, sizeof mat);
    } memcpy(mat, tmp, sizeof mat);
  }

  cout << mul((Mod+1)/2, add(mat[0][0], mat[1][0])) << "/" << mul((Mod+1)/2, add(mat[0][1], mat[1][1])) << endl;
  
  return 0;
}