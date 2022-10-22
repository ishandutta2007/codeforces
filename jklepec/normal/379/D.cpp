#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

int k, X, n, m;

char c[3] = {'A', 'C', 'Z'};

void napravi(int x, int a, int b, int N) {
  string ret = "";
  ret += c[a];

  while(x) {
    if(ret.back() == 'A') {
      ret += 'C';
      x --;
    }
    else {
      ret += 'A';
    }
  }


  int go = N - (int) ret.size() - 1;
  REP(i, go) {
    ret += 'Z';
  }

  if((int) ret.size() < N)
    ret += c[b];
  cout << ret << endl;
}

void ispis(int x, int y, int xa, int xb, int ya, int yb) {
  napravi(x, xa, xb, n);
  napravi(y, ya, yb, m);
  exit(0);
}

void isprobaj(int x, int y, int xa, int xb, int ya, int yb) {
  int N = n, M = m;

  if(N == 1 && xa != xb) return;
  if(M == 1 && ya != yb) return;

  if(N == 2 && x == 0 && xa == 0 && xb == 1) return;
  if(M == 2 && y == 0 && ya == 0 && yb == 1) return;

  if(xa != 0) N --;
  if(xb != 1) N --;
  if(ya != 0) M --;
  if(yb != 1) M --;

  if(x > N / 2) return;
  if(y > M / 2) return;

  int A[3], B[3];
  A[0] = x;
  A[1] = xa;
  A[2] = xb;

  B[0] = y;
  B[1] = ya;
  B[2] = yb;

  REP(i, k - 2) {
    int nx, na, nb;
    na = A[1];
    nb = B[2];
    nx = A[0] + B[0];
    if(!A[2] && B[1] == 1) nx ++;

    memcpy(A, B, sizeof A);

    B[0] = nx;
    B[1] = na;
    B[2] = nb;
    if(B[0] > 1e9)
      break;
  }

  if(B[0] == X) {
    ispis(x, y, xa, xb, ya, yb);
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> k >> X >> n >> m;

  REP(i, n) REP(j, m) REP(i1, 3) REP(i2, 3) REP(j1, 3) REP(j2, 3) {
    isprobaj(i, j, i1, i2, j1, j2);
  }

  cout << "Happy new year!";
}