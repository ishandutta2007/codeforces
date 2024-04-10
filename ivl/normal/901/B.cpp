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

typedef vector<int> poly;

int n;

bool valid(poly P){
  if (P.back() != 1) return false;
  for (auto t : P)
    if (t != 0 && t != 1 && t != -1) return false;
  return true;
}

poly operator+(poly A, poly B){
  REP(i,B.size()) A[i] += B[i];
  return A;
}

poly operator-(poly A, poly B){
  REP(i,B.size()) A[i] -= B[i];
  return A;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;

  vector<poly> sve = {{1}, {0, 1}};
  REP(blatruc,155){
    poly P = sve.back();
    poly Q = sve[sve.size()-2];
    P.pb(0);
    for (int i = (int)P.size()-2; i >= 0; --i)
      P[i+1] = P[i];
    P[0] = 0;
    if (valid(P+Q)) sve.pb(P+Q);
    else if (valid(P-Q)) sve.pb(P-Q);
    else assert(false);
  }

  cout << n << endl;
  for (auto t : sve[n]) cout << t << " "; cout << endl;
  cout << n-1 << endl;
  for (auto t : sve[n-1]) cout << t << " "; cout << endl;
  
  return 0;
}