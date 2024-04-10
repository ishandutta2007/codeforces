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

const int Mod = 1e9 + 7;
int mul(int a, int b){return (int)((ll)a*b%Mod);}

int main(){
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  // sell > unknown > buy
  priority_queue<int, vector<int>, greater<int>> sell; sell.push(1e9);
  priority_queue<int, vector<int>, less<int>> buy; buy.push(-1e9);
  vector<int> unknown;

  int output = 1;

  REP(i,n){
    string com; cin >> com;
    int p; cin >> p;
    if (com == "ADD"){
      if (sell.top() < p) sell.push(p);
      else if (buy.top() > p) buy.push(p);
      else unknown.pb(p);
    } else {
      if (sell.top() < p){output = 0; break;}
      if (buy.top() > p){output = 0; break;}
      if (sell.top() == p){sell.pop(); for (auto t : unknown) buy.push(t); unknown.clear(); continue;}
      if (buy.top() == p){buy.pop(); for (auto t : unknown) sell.push(t); unknown.clear(); continue;}

      for (auto t : unknown){
	if (t < p) buy.push(t);
	if (t > p) sell.push(t);
      }

      unknown.clear();
      output = mul(output, 2);
    }
  }

  output = mul(output, (int)unknown.size() + 1);
  cout << output << endl;

  return 0;
}