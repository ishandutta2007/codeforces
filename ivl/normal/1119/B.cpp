#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)

#define x first
#define y second
#define pb push_back

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

ll f(vector<int> a){
  sort(a.begin(), a.end());
  ll out = a.size() % 2 == 0 ? 0 : a[0];
  REP(i,a.size()/2) out += a[a.size()-i*2-1];
  return out;
}

int main(){
  ios_base::sync_with_stdio(false);

  int n, h;
  cin >> n >> h;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  int lo = 1, hi = n, mid;
  while (lo != hi){
    mid = (lo+hi+1)/2;
    if (f(vector<int>(a.begin(), a.begin()+mid)) <= h) lo = mid;
    else hi = mid-1;
  }

  cout << lo << endl;

  return 0;
}