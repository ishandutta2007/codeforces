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

void imp(){cout << -1 << endl; exit(0);}

int main(){
  ios_base::sync_with_stdio(false);

  int n, d, h;
  cin >> n >> d >> h;

  if (h*2 < d) imp();
  if (h > d) imp();

  if (h == 1){
    if (n != 2 && d != 2) imp();
    FOR(i,2,n+1) cout << 1 << " " << i << '\n';
    return 0;
  }

  int id = 2;
  int prev = 1;
  REP(i,h){
    cout << prev << " " << id << '\n';
    prev = id;
    ++id;
  } prev = 1;
  REP(i,d-h){
    cout << prev << " " << id << '\n';
    prev = id;
    ++id;
  } prev = 1;

  while (id != n+1){
    cout << 2 << " " << id << '\n';
    ++id;
  }

  return 0;
}