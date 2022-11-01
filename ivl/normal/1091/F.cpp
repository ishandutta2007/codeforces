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

int n;
ll l[100005];
string str;

ll delta[100005];
ll output;

void minimize(char letter, int cost){
  ll stamina = 0;
  REP(i,n) stamina += delta[i];
  ll mini = stamina;
  for (int i = n-1; i >= 0; --i){
    if (str[i] != letter){
      stamina -= delta[i];
      mini = min(mini, stamina);
    } else {
      ll converting = 2*delta[i];
      converting = min(converting, mini);
      mini -= converting;
      stamina -= delta[i];
      delta[i] -= converting;
      output -= converting * cost / 2;
      mini = min(mini, stamina);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> l[i];
  cin >> str;

  ll stamina = 0;
  int lastpos = 0;
  REP(i,n){
    if (str[i] == 'L'){
      delta[i] = -l[i];
      output += 1 * l[i];
    } else if (str[i] == 'G'){
      delta[i] = +l[i];
      output += 5 * l[i];
    } else if (str[i] == 'W'){
      lastpos = i;
      delta[i] = +l[i];
      output += 3 * l[i];
    }

    stamina += delta[i];
    if (stamina < 0){
      // TRACE(stamina);
      delta[lastpos] -= stamina;
      if (str[lastpos] == 'G'){
	output -= stamina * 5;
      } else {
	output -= stamina * 3;
      } stamina = 0;
    }
  }

  // TRACE(output);

  minimize('G', 5-1);
  minimize('W', 3-1);
  cout << output << endl;
  
  return 0;
}