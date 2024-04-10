#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second
#define ll long long

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int gcd(int a, int b){
  while (b) a %= b, swap(a, b);
  return a;
}

int main(){
  int n;
  cin >> n;
  vector < int > v(n);
  REP(i,n) cin >> v[i];
  int s = 0;
  REP(i,n) s += v[i];
  if (n == 1){
    cout << v[0] << endl;
    REP(i,v[0]) printf("a"); cout << endl;
    return 0;
  }
  if (s%2 == 1){
    int cnt = 0;
    REP(i,n) if (v[i]%2) ++cnt;
    if (cnt != 1){
      cout << 0 << endl;
      REP(i,n) REP(j,v[i]) printf("%c", 'a'+i); cout << endl;
      return 0;
    } else {
      int g = s;
      REP(i,n) g = gcd(g, v[i]);
      cout << g << endl;
      int id = -1;
      REP(i,n) if (v[i]%2) id = i;
      char c1 = 'a'+id;
      v[id] -= g;
      string S;
      REP(i,n) REP(j,v[i]/2/g) S.pb('a'+i);
      for (int i = n-1; i >= 0; --i) REP(j,v[i]/2/g) S.pb('a'+i);
      REP(i,g){
	cout << S << c1;
      } cout << endl;
      return 0;
    }
  } else {
    REP(ttt,n) if (v[ttt]%2 == 1){
      cout << 0 << endl;
      REP(i,n) REP(j,v[i]) printf("%c", 'a'+i); cout << endl;
      return 0;
    }
    int g = s;
    REP(i,n) g = gcd(g, v[i]);
    cout << g << endl;
    string S;
    REP(i,n){
      int t = v[i]/g;
      char c = 'a'+i;
      REP(j,t) S.pb(c);
    }
    string S2 = S;
    reverse(S2.begin(), S2.end());
    REP(tt,g){
      if (tt%2) cout << S;
      else cout << S2;
    } cout << endl;
  }
  return 0;
}