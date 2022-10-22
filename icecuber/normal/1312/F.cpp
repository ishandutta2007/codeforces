#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e4;
int nimsum[6][6][6][nax][3];
int ways[6][6][6][nax][3][4];
int base = 100;
int loop[6][6][6];

int rec(int a, int last, int x, int y, int z) {
  if (a <= 0) return 0;
  int&memo = nimsum[x][y][z][a][last];
  if (!memo) {
    multiset<int> reach;
    reach.insert(rec(a-x, 0, x, y, z));
    if (last != 1)
      reach.insert(rec(a-y, 1, x, y, z));
    if (last != 2)
      reach.insert(rec(a-z, 2, x, y, z));
    int mex = 0;
    while (reach.count(mex)) mex++;

    for (int i : reach)
      ways[x][y][z][a][last][i^mex]++;

    memo = mex+1;
  }
  return memo-1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  for (int x = 1; x < 6; x++)
    for (int y = 1; y < 6; y++)
      for (int z = 1; z < 6; z++) {
	int l = 1;
	while (1) {
	  int ok = 1;
	  for (int i = 0; i < base; i++) {
	    if (rec(base+i,0,x,y,z) != rec(base+i+l,0,x,y,z)) {
	      ok = 0;
	      break;
	    }
	  }
	  if (ok) {
	    loop[x][y][z] = l;
	    break;
	  }
	  l++;
	}
	//cout << x << ' ' << y << ' ' << z << endl;
	/*for (int i = 0; i < nax; i++) {
	  //cout << rec(base+i,0,x,y,z) << ' ';
	  //continue;
	  for (int j = 0; j < 3; j++) {
	    int a = i;
	    if (a >= base) a = (a-base)%loop[x][y][z]+base;
	    if (rec(i, j, x, y, z) != rec(a, j, x, y, z)) {
	      cout << i << ' ' << a << ' ' << x << ' ' << y << ' ' << z << endl;
	      return 0;
	    }
	    }
	    }*/
	//cout << endl;
      }
  //return 0;
  int t;
  cin >> t;
  while (t--) {
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    int xor_sum = 0;
    int tways[4] = {};
    for (int i = 0; i < n; i++) {
      ll a;
      cin >> a;
      if (a >= base) a = (a-base)%loop[x][y][z]+base;
      assert(a < nax);
      xor_sum ^= rec(a, 0, x, y, z);
      for (int j = 0; j < 4; j++)
	tways[j] += ways[x][y][z][a][0][j];
    }
    cout << tways[xor_sum] << endl;
  }
}