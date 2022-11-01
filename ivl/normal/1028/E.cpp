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
ll b[200005];
ll a[200005];

void f(){
  int maxid = -1;
  ll prev = b[n-1];
  REP(i,n){
    if (prev < b[i])
      if (maxid == -1 || b[maxid] > b[i])
	maxid = i;
    prev = b[i];
  }

  vector<ll> tmp(n);
  REP(i,n) tmp[i] = b[(maxid-i+n)%n];
  REP(i,n) b[i] = tmp[i];

  a[0] = b[0];
  FOR(i,1,n){
    ll prev = a[i-1];
    ll rem = b[i];
    ll bound = b[i==n-1 ? 0 : i+1];
    // prereq: prev > rem
    // nxt % prev = rem --> nxt = rem + prev*k, k >= 0
    // nxt > bound (equiv to prereq)
    // rem + prev*k > bound
    // prev*k > bound-rem
    // k > (bound-rem)/prev
    ll k;
    if (bound<rem) k = 0;
    else k = (bound-rem)/prev + 1;
    a[i] = rem + prev*k;
  }

  REP(i,n) tmp[i] = a[(maxid-i+n)%n];
  REP(i,n) a[i] = tmp[i];  
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> b[i];

  int maxid = 0, minid = 0;
  REP(i,n){
    if (b[maxid] < b[i]) maxid = i;
    if (b[minid] > b[i]) minid = i;
  }
  if (b[maxid] == b[minid]){
    if (b[0] == 0){
      cout << "YES" << endl;
      REP(i,n) cout << 1 << " "; cout << endl;
      return 0;
    } else {
      cout << "NO" << endl;
      return 0;
    }
  }

  f();

  cout << "YES" << endl;
  REP(i,n) cout << a[i] << " "; cout << endl;
  

  return 0;
}