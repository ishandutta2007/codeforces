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

int f(char c){
  if (c >= 'a' && c <= 'z') return c-'a'+1;
  if (c >= 'A' && c <= 'Z') return c-'A'+1;
  return 0;
}

int main(){

  string s;
  cin >> s;
  ll r = 0;
  
  for (auto c : s){
    bool b1 = ('@'<c)&&('['>c);
    int v1 = b1*f(c);
    bool b2 = ('`'<c)&&('{'>c);
    int v2 = b2*f(c);
    r += v1-v2;
  } cout << r << endl;
  
  return 0;
}