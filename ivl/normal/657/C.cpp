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

const int oo = 1000000000;
const ll ool = (ll)oo * oo;

int n, k, b, c;
ll t[1<<20];
ll t2[1<<20];
ll cr[1<<20];

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> k >> b >> c;
  if (b > 5*c) b = 5*c;
  REP(i,n) cin >> t[i];
  sort(t, t+n);

  ll r = ool;

  REP(ttt,5){
    REP(i,n){
      t2[i] = t[i];
      cr[i] = 0;
      while (t2[i]%5 != ttt && t2[i]%5 != ttt-5) ++t2[i], cr[i] += c;
      t2[i] = (t2[i]-ttt) / 5;
    }
    multiset < ll > S;
    ll Sum = 0;
    REP(i,n){
      ll ct = cr[i]-t2[i]*b;
      Sum += ct;
      S.insert(ct);
      if (S.size() == k+1){
	auto it = S.end(); --it;
	Sum -= *it;
	S.erase(it);
      }
      if (S.size() == k){
	r = min(r, t2[i]*b*k + Sum);
      }
    }
  } cout << r << endl;

  return 0;
}