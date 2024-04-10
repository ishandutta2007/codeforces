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

int main(){
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  int a = 1, b = 1;
  while (a*b < n) ++a, swap(a, b);
  cout << 2*(a+b) << endl;
  
  return 0;
}