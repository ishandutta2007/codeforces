#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << setw(3) << setfill('0') <<  __LINE__ << ": " << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef pair < int, int > pii;
typedef long long ll;

ostream& operator<<(ostream& out, vector<int> v){
  out << "{";
  REP(i,v.size()-1) out << v[i] << ", ";
  if (!v.empty()) out << v.back();
  return out << "}";
}

int n;
char c[20];
int r[20];
int b[20];

vector<int> memo[1<<16];
vector<int> dp(int bit){
  if (bit == 0) return {0};
  vector<int> &sol = memo[bit];
  if (!sol.empty()) return sol;
  sol = {0};

  int R = 0, B = 0;
  REP(i,n) if ((bit>>i)%2 == 0){if (c[i] == 'R') ++R; else ++B;}

  REP(i,n) if ((bit>>i)&1){
    vector<int> temp = dp(bit^(1<<i));
    int dR = min(R, r[i]);
    int dB = min(B, b[i]);
    vector<int> temp2(dR, temp.front());
    for (auto t : temp) temp2.pb(t); temp = temp2;
    for (auto &t : temp) t += dB;

    while (temp.size() > sol.size()) sol.pb(0);
    REP(ii,temp.size()) sol[ii] = max(sol[ii], temp[ii]);
  }

  return sol;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> c[i] >> r[i] >> b[i];

  int tempr = 0, tempb = 0;
  REP(i,n) tempr += r[i], tempb += b[i];
  int sol = 1e9;

  vector<int> v = dp((1<<n)-1);
  REP(i,v.size()) sol = min(sol, max(tempr-i, tempb-v[i]));

  cout << sol+n << endl;

  return 0;
}