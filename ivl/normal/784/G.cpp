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

void display(char c){
  REP(i,c) cout << '+';
  cout << ".>";
}

void rek(int x){
  if (!x) return;
  rek(x/10);
  display('0'+x%10);
}

int main(){
  ios_base::sync_with_stdio(false);

  string s;
  cin >> s;

  stringstream sin(s);
  int curr; sin >> curr;
  while (true){
    char c;
    sin >> c;
    if (!sin) break;
    int tmp;
    sin >> tmp;
    if (c == '+') curr += tmp;
    else curr -= tmp;
  }

  if (curr < 0) display('-'), curr = -curr;
  if (curr == 0) display('0');
  rek(curr);
  
  return 0;
}