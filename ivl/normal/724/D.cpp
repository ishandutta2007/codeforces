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

int m;
string s;
int n;
vector < int > id[30];

int clr[100005];

int main(){
  ios_base::sync_with_stdio(false);

  cin >> m >> s;
  n = (int)s.size();
  REP(i,n) id[s[i]-'a'].pb(i);

  int upp = -1;
  REP(i,30){
    for (auto t : id[i]) clr[t] = 1;
    int tmp = 0;
    REP(j,m) tmp += clr[j];
    bool check = tmp;
    FOR(j,1,n-m+1){
      tmp -= clr[j-1];
      tmp += clr[j+m-1];
      if (!tmp) check = false;
    }
    if (check){upp = i; break;}
  }

  memset(clr, 0, sizeof clr);
  REP(i,upp) for (auto t : id[i]) clr[t] = 1;
  for (auto t : id[upp]) clr[t] = -1;
  string out;
  REP(i,upp) REP(j,id[i].size()) out.pb((char)('a'+i));

  for (int i = 0, j = 0; i < n; i = j){
    if (clr[i] == 1){++j; continue;}
    while (j < n && clr[j] != 1) ++j;
    vector < int > curr(clr+i, clr+j);
    if ((int)curr.size() < m) continue;
    set < int > all;
    int lo = 0;
    int hi = -1;
    int len = (int)curr.size();
    while (true){
      if (hi-lo+1 == m){
	assert(!all.empty());
	out.pb((char)('a'+upp));
	int pos = *--all.end();
	all.clear();
	lo = pos+1;
      }
      if (hi == len-1) break;
      ++hi;
      if (curr[hi] == -1) all.insert(hi);
    }
  } cout << out << endl;
  
  return 0;
}