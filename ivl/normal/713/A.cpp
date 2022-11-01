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
typedef pair < int, int > pii;

int main(){

  map < string, int > M;

  int t;
  cin >> t;
  REP(ttt,t){
    char c;
    string x;
    cin >> c >> x;
    for (auto &a : x){
      a -= '0';
      a %= 2;
      a += '0';
    }
    while (x.size() < 18) x.insert(x.begin(), '0');

    if (c == '+'){
      ++M[x];
    }
    if (c == '-'){
      --M[x];
    }
    if (c == '?'){
      cout << M[x] << endl;
    }
  }

  return 0;
}