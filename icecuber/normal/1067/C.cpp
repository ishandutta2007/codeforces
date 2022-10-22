#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int knights = 0;
map<pair<int,int>,int> m;
void place(int x, int y) {
  knights++;
  m[{x,y}] = 8;
  for (int i = 0; i < 2; i++)
    for (int j = -1; j < 2; j += 2)
      for (int k = -1; k < 2; k += 2) {
	int dx = j;
	int dy = k*2;
	if (i) swap(dx,dy);
	if (++m[{x+dx,y+dy}] == 4) {
	  place(x+dx,y+dy);
	}
      }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int x = 0;
  for (int i = 0; i < n; i++) {
    //place(x,(i+2)%3);
    cout << x << ' ' << (i+2)%3 << endl;
    if (i%3) x++;
  }
  //cout << n*n/10 << ' ' << knights << endl;
}