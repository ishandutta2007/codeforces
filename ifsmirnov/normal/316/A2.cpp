#include <iostream>
#include <algorithm>
#include <set>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
const int maxn = 100500;
typedef long long i64;

int n;
char s[maxn];

int main()
{
  cin >> s;
  n = strlen(s);

  set<char> t;
  int p10 = 0;
  
  forn(i, n) {
    if (isdigit(s[i])) 
      ;
    else if (isalpha(s[i]))
      t.insert(s[i]);
    else if (s[i] == '?') 
      p10 += (i != 0);
  }

  i64 res = 1;
  forn(j, t.size()) {
    if (j == 0) {
      if (isalpha(s[0])) 
        res *= 9ll;
      else
        res *= 10ll;
    }
    else
      res *= 10ll - j;
  }
  if (s[0] == '?')
    res *= 9ll;

  cout << res;
  forn(i, p10) cout << "0";
  cout << endl;

  return 0;
}