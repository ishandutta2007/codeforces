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
int a[205][5];

int cnt[5];

int eval(int tm, ll ac, ll all){
  if (tm == -1) return 0;
  int maks = -1;
  if (ac*2 > all) maks = 500;
  else if (ac*4 > all) maks = 1000;
  else if (ac*8 > all) maks = 1500;
  else if (ac*16 > all) maks = 2000;
  else if (ac*32 > all) maks = 2500;
  else maks = 3000;
  return maks / 250 * (250 - tm);
}

int delta(int i, int num){
  if (a[0][i] == -1) return eval(a[0][i], cnt[i], n+num) - eval(a[1][i], cnt[i], n+num);
  return max(
	     eval(a[0][i], cnt[i], n+num) - eval(a[1][i], cnt[i], n+num),
	     eval(a[0][i], cnt[i]+num, n+num) - eval(a[1][i], cnt[i]+num, n+num)
	     );
}

int delta(int num){
  int sol = 0;
  REP(i,5) sol += delta(i, num);
  return sol;
}

const int MAKS = 1e9 + 7;

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) REP(j,5) cin >> a[i][j];
  REP(i,n) REP(j,5) if (a[i][j] != -1) ++cnt[j];

  REP(i,1000000)
    if (delta(i) > 0){
      cout << i << endl;
      return 0;
    }

  cout << -1 << endl;

  return 0;
}