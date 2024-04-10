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

void imp(){cout << "impossible" << endl; exit(0);}

string out[2];

int main(){
  ios_base::sync_with_stdio(false);

  out[0] = string(13, '.');
  out[1] = string(13, '.');

  string s;
  cin >> s;
  int n = (int)s.size();

  char c = -1;
  REP(i,n) REP(j,i) if (s[i] == s[j]) c = s[i];
  assert(c != -1);

  int p, q;
  REP(i,n) REP(j,i) if (s[i] == s[j]) p = i, q = j;

  string a(s.begin(), s.begin()+q), b(s.begin()+p+1, s.end()), mid(s.begin()+q+1, s.begin()+p);
  // TRACE(a _ b _ mid);
  int len = (int)mid.size();
  if (len == 0) imp();
  pii loc = {-1, -1};
  if (len == 1){
    out[0][0] = c;
    out[1][0] = mid.front();
    loc = {0, 0};
  } else if (len % 2 == 0){
    REP(i,len/2) out[0][len/2-1-i] = mid[i];
    REP(i,len/2) out[1][i] = mid[i+len/2];
    out[0][len/2] = c;
    loc = {0, len/2};
  } else {
    REP(i,len/2) out[0][len/2-1-i] = mid[i];
    REP(i,len/2+1) out[1][i] = mid[i+len/2];
    out[0][len/2] = c;
    loc = {0, len/2};
  }

  vector < pii > all;
  REP(i,13) if (out[0][i] == '.') all.pb({0, i});
  REP(i,13) if (out[1][12-i] == '.') all.pb({1, 12-i});

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  for (auto t : a) out[all.front().x][all.front().y] = t, all.erase(all.begin());
  for (auto t : b) out[all.front().x][all.front().y] = t, all.erase(all.begin());

  cout << out[0] << endl << out[1] << endl;
  
  return 0;
}