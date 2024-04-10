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

int n;
string s;

void fin(string r){
  sort(r.begin(), r.end());
  cout << r << endl;
  exit(0);
}

int main(){

  cin >> n >> s;
  int r = 0, g = 0, b = 0;
  for (auto c : s){
    if (c == 'R') ++r;
    if (c == 'G') ++g;
    if (c == 'B') ++b;
  }

  if (r && g && b) fin("RGB");

  int a = 0;
  for (auto t : {r,g,b}) if (t >= 2) ++a;
  if (a >= 2) fin("RGB");
  if (a == 0){
    if (r && g) r = g = 0, ++b;
    if (r && b) r = b = 0, ++g;
    if (b && g) b = g = 0, ++r;
  }

  a = 0;
  for (auto t : {r,g,b}) if (t >= 1) ++a;
  if (a == 1){
    if (r) fin("R");
    if (g) fin("G");
    if (b) fin("B");
  } else {
    if (r >= 2) fin("GB");
    if (g >= 2) fin("RB");
    if (b >= 2) fin("GR");
  }
  
  return 0;
}