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
int a[1000005];
int inv[1000005];

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> a[i], --a[i];
  REP(i,n) inv[a[i]] = i;

  int cnt = n;
  REP(i,n) if (a[i] != i){
    ++cnt;
    int loc = inv[i];
    swap(a[i], a[loc]);
    inv[a[i]] = i;
    inv[a[loc]] = loc;
  }

  if (cnt % 2 == 0) cout << "Petr" << endl;
  else cout << "Um_nik" << endl;

  return 0;
}