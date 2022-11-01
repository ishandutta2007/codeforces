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

set<ll> output;

void solve(int d){
  int len = n/d;
  int first = 1;
  int last = 1 + d * (len-1);
  output.insert((ll)(first + last) * (len) / 2);
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i*i <= n; ++i)
    if (n%i == 0){
      solve(i);
      if (i*i != n) solve(n/i);
    }

  for (auto t : output) cout << t << " "; cout << endl;
  
  return 0;
}