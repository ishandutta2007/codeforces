#include <iostream>
#include <cstring>
#include <iomanip>

#define FOR(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define REP(i,a) FOR(i,0,a)

using namespace std;

const int DIM = 130;

struct Matrix {
  long double a[DIM][DIM];
  long double *operator [] (int r) { return a[r]; };

  Matrix(long double x = 0) {
    memset(a, 0, sizeof a);
    if (x) REP(i, DIM) a[i][i] = x;
  }
} const I(1);

Matrix operator * (Matrix A, Matrix B) {
  Matrix C;
  REP(i, DIM) REP(j, DIM) {
    long double w = 0;
    REP(k, DIM) {
      w += (long double)(A[i][k]) * B[k][j];
    }
    C[i][j] = w;
  }
  return C;
}

Matrix operator ^ (Matrix A, long long b) {
  Matrix R = I;
  for (; b > 0; b /= 2) {
    if (b % 2) R = R*A;
    A = A*A;
  }
  return R;
}

long double p[DIM];

int main() {
  ios_base::sync_with_stdio(false);
  int n, x;
  cin >> n >> x;
  for (int i = 0; i <= x; i++) {
    cin >> p[i];
  }

  Matrix baza;
  for (int i = 0; i <= 127; i++) {
    for (int j = 0; j <= x; j++) {
      baza[i][i^j] += p[j];
    }
  }

//  REP(i,x+1) {
//    REP(j,x+1) {
//      cout << baza[i][j] << " ";
//    }
//    cout << endl;
//  }

  baza = baza ^ n;

//  REP(i,x+1) {
//    REP(j,x+1) {
//      cout << baza[i][j] << " ";
//    }
//    cout << endl;
//  }

  cout << setprecision(20) << fixed << (1.0 - baza[0][0]) << endl;

  return 0;
}