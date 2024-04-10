#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[][2] = {{7,0},{7,7}};
int b[][2] = {{7,0},{7,1},{0,1},{0,7},{7,7}};
int c[][2] = {{7,0},{7,1},{0,1},{0,2},{7,2},{7,3},{0,3},{0,4},{7,4},{7,5},{0,5},{0,6},{5,6},{5,7},{0,7},{6,7},{6,6},{7,6},{7,7}};
int na = 2, nb = 5, nc = 19;

void pos(int x, int y) {
  //cout << x << y << endl;
  cout << char(x+'a') << y+1 << ' ';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int (*p)[2], m;
  if (n >= nc) p = c, m = nc;
  else if (n >= nb) p = b, m = nb;
  else p = a, m = na;

  pos(0,0);
  int i = 0, x = 0, y = 0;
  while (n) {
    if ((x-p[i][0])&&(y-p[i][1]))
      assert(0);
    int d = abs(x-p[i][0])+abs(y-p[i][1]);
    if (d == 1 || n == m-i) {
      x = p[i][0];
      y = p[i][1];
      i++;
    } else {
      x += (p[i][0]-x)/d;
      y += (p[i][1]-y)/d;
    }
    n--;
    pos(x,y);
  }
  cout << endl;
}