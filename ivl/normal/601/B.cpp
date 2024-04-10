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

int n, q;
ll a[100005];

ll seq[100005];
ll seq2[100005];

ll Solve(int lo, int hi){
  //TRACE(lo _ hi);
  if (lo == hi) return seq[lo];

  int mid = (lo+hi)/2;
  ll r = Solve(lo, mid) + Solve(mid+1, hi);
  //TRACE(r);
  
  FOR(i,lo,hi+1) seq2[i] = seq[i]; //TRACE(seq[i]);

  FOR(i,mid+1,hi) seq[i+1] = max(seq[i], seq[i+1]);
  for (int i = mid; i > lo; --i) seq[i-1] = max(seq[i], seq[i-1]);

  int poin = mid;
  FOR(i,mid+1,hi+1){
    if (seq[i] < seq[poin]) continue;

    while (poin >= lo && seq[poin] <= seq[i]) --poin; ++poin;
    r += seq[i] * (mid-poin+1);
  }

  poin = mid+1;
  for (int i = mid; i >= lo; --i){
    if (seq[i] <= seq[poin]) continue;

    while (poin <= hi && seq[poin] < seq[i]) ++poin; --poin;
    r += seq[i] * (poin-mid);
  }

  FOR(i,lo,hi+1) seq[i] = seq2[i];

  return r;
}

int main(){
  cin >> n >> q;
  REP(i,n) scanf("%I64d", a+i);

  REP(ttt,q){
    int x, y;
    cin >> x >> y, --x, --y;
    FOR(i,x,y) seq[i] = abs(a[i] - a[i+1]);
    cout << Solve(x, y-1) << endl;
  }
  
  return 0;
}