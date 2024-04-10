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

int val[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

ll v(int t){
  ll r = 0;
  while (t) r += val[t%10], t /= 10;
  return r;
}

ll f(int t){
  ll r = 0;
  FOR(i,1,t+1) r += v(i);
  return r;
}

int main(){
  //ios_base::sync_with_stdio(false);

  int a, b;
  cin >> a >> b;
  cout << f(b)-f(a-1) << endl;
  
  return 0;
}