#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

void remove(string &s){
  int p = 0;
  while (p < (int)s.size()-1 && s[p] == '0') ++p;
  s.erase(0, p);
}

string out = "";

int main(){
  ios_base::sync_with_stdio(false);

  string s;
  cin >> s;

  vector<int> loc[3];
  int val = 0;
  REP(i,s.size())
    loc[(s[i]-'0')%3].pb(i), val = (val+s[i]-'0')%3;

  if (val == 0){cout << s << endl; return 0;}
  if (val == 2) swap(loc[1], loc[2]);
  if (loc[1].size() >= 1){
    string tmp = s;
    tmp.erase(tmp.begin()+loc[1].back());
    remove(tmp);
    if (tmp.size() > out.size()) out = tmp;
  }
  if (loc[2].size() >= 2){
    string tmp = s;
    tmp.erase(tmp.begin()+loc[2].back());
    tmp.erase(tmp.begin()+loc[2][loc[2].size()-2]);
    remove(tmp);
    if (tmp.size() > out.size()) out = tmp;
  }
  if (out == "") cout << -1 << endl;
  else cout << out << endl;

  return 0;
}