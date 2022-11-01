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

const int Mod = 1e9+7;
int add(int a, int b){return a+b<Mod ? a+b : a+b-Mod;}
int mul(int a, int b){return (int)((ll)a*b%Mod);}
int pot(int a, int b){
  int r = 1;
  while (b){
    if (b&1) r = mul(r, a);
    a = mul(a, a), b >>= 1;
  } return r;
}

int main(){
  ios_base::sync_with_stdio(false);

  string s;
  cin >> s;

  int a = 0, sol = 0;
  for (auto c : s)
    if (c == 'a') ++a;
    else sol = add(sol, pot(2, a)-1);

  cout << sol << endl;

  return 0;
}