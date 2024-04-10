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

map < pii, int > M;

int main(){
  cin >> n >> s;
  int x = 0, y = 0;
  int r = 0;
  for (auto c : s){
    r += M[{x,y}]++;
    if (c == 'U') ++x;
    if (c == 'D') --x;
    if (c == 'L') ++y;
    if (c == 'R') --y;
  } cout << r+M[{x,y}] << endl;
  
  return 0;
}