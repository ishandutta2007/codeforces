//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>

const int MAXN = 57;
string tab[MAXN];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m;

bool onboard(int a, int b) {
  return 0 <= a and a < n and 0 <= b and b < m;
}

bool check(const string& x, const string& w) {
  int sx = -1, sy = -1;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(tab[i][j] == 'S') {
        sx = i;
        sy = j;
      }
    }
  }
  for(auto xx : x) {
    int k = w[xx-'0']-'0';
    sx += dx[k];
    sy += dy[k];
    if(!onboard(sx, sy)) return false;
    if(tab[sx][sy] == '#') return false;
    if(tab[sx][sy] == 'E') return true;
  }
  return false;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for(int i=0; i<n; i++) cin >> tab[i];
  string w;
  cin >> w;
  string x = "0123";
  int res = 0;
  do {
    if(check(w, x)) res++;
  } while(next_permutation(x.begin(), x.end()));
  cout << res << "\n";
  return 0;
}