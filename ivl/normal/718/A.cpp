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

int n, t;
string s;

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> t;
  cin >> s;
  int p = 0;
  while (s[p] != '.') ++p;

  string s2(s.begin(), s.begin()+p);
  string s3(s.begin()+p+1, s.end());

  int tmp = 0;
  while (tmp < (int)s3.size() && s3[tmp] < '5') ++tmp;
  if (tmp == (int)s3.size()){cout << s << endl; return 0;}
  int tmp2 = tmp-1;
  while (tmp2 >= 0 && s3[tmp2] == '4') --tmp2;
  s3.erase(s3.begin()+tmp+1, s3.end());

  while (t && tmp > tmp2) s3.pop_back(), --tmp, --t;
  if (!s3.empty()){++s3.back(); cout << s2 << '.' << s3 << endl; return 0;}

  tmp = (int)s2.size()-1;
  while (tmp >= 0 && s2[tmp] == '9') s2[tmp] = '0', --tmp;
  if (tmp == -1) cout << 1; else ++s2[tmp];
  cout << s2 << endl;

  return 0;
}