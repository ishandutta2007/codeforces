#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int palin(int x1, int y1, int x2, int y2) {
  assert(x2 >= x1 && y2 >= y1 && x1+y1+2 <= x2+y2);
  cout << "? " << y1+1 << ' ' << x1+1 << ' ' << y2+1 << ' ' << x2+1 << endl;
  int ans;
  cin >> ans;
  assert(ans != -1);
  return ans;
}

int a[50][50];
int n;
void solve(int ox, int oy) {
  for (int j = ox+2; j < n; j += 2) {
    a[oy][j] = a[oy][j-2] ^ !palin(j-2,oy,j,oy);
  }
  for (int i = oy+2; i < n; i += 2) {
    for (int j = ox; j < n; j += 2) {
      a[i][j] = a[i-2][j] ^ !palin(j,i-2,j,i);
    }
  }
}

void flip(int ox, int oy) {
  for (int i = oy%2; i < n; i += 2)
    for (int j = ox%2; j < n; j += 2)
      a[i][j] ^= 1;
}

void print() {
  return;
  cerr << "Current a:" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cerr << a[i][j];
    cerr << endl;
  }
}

int main() {
  a[0][0] = 1;
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      solve(i,j);

  print();

  assert(a[n-1][n-1] == 0);
  if (!palin(0,0,1,1) != (a[0][0]^a[1][1])) {
    flip(1,1);
  }
  print();
  if (!palin(0,1,1,2) != (a[0][1]^a[2][1])) {
    flip(0,1);
  }

  print();

  for (int i = 0; i < n; i += 2) {
    if (a[i][i] != a[i+2][i+2]) {
      if (a[i+1][i] != a[i][i+1] || a[i][i+2] != a[i+1][i+1]) {
	if (!palin(i,i,i+2,i+1) != (a[i][i]^a[i+1][i+2])) {
	  flip(0,1), flip(1,0);
	}
      } else if (a[i+2][i+1] != a[i+1][i+2] || a[i][i+2] != a[i+1][i+1]) {
	if (!palin(i+1,i,i+2,i+2) != (a[i][i+1]^a[i+2][i+2])) {
	  flip(0,1), flip(1,0);
	}
      } else {
	int A = a[i][i], B = a[i][i+2], C = a[i+2][i+2];
	assert(C == !A);
	int x = a[i][i+1], y = a[i+1][i+2];
	if ((A^B) == (x^y)) {
	  if (!palin(i,i,i+2,i+1) != (a[i][i]^a[i+1][i+2])) {
	    flip(0,1), flip(1,0);
	  }
	} else {
	  if (!palin(i+1,i,i+2,i+2) != (a[i][i+1]^a[i+2][i+2])) {
	    flip(0,1), flip(1,0);
	  }
	}
      }
      break;
    }
  }
  print();
  cout << "!" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << a[i][j];
    cout << endl;
  }
}