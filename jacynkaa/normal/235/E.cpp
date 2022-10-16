#include <bits/stdc++.h>
#include <chrono>
#include <math.h>
using namespace std;
#pragma GCC optimize("-O3")
#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10), cin.tie(0), cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define what(x) cerr << #x << " is " << x << endl;
/*
const int MAXN = 5; // 000;
int dp[MAXN];
int kwadr[MAXN];
int pref[MAXN][MAXN];

int a, b, c;

void pre() {
   for (int i = 2; i < MAXN; i++) {
      if (!kwadr[i]) {
         for (int k = i; k < MAXN; k += i)
            kwadr[k]++;
      }
   }
   for (int i = 2; i < MAXN; i++) {
      int l = i * i;
      for (int k = l; k < MAXN; k += l)
         kwadr[k] = 0;
   }

   rep(i, MAXN) kwadr[i] = kwadr[i] ? (kwadr[i] % 2 ? -1 : 1) : kwadr[i];

   for (int i = 1; i < MAXN; i++) {
      for (int j = 1; j < MAXN; j++)
         pre[i][j] = pref[i][j - 1] + (j % i == 0) ? 1 : 0;
   }
}

map<int, pii> get_entries(int a) {
   map<int, pii> M;
   for (int i = 1; i <= a; i++)
      if (M.find(a / i) == M.end())
         M[a / i] = {i, i};
      else
         M[a / i].nd = i;
   return M;
}

inline int get_val(pair<int, pii> &X, int p) { return X.st * (pref[p][X.nd.nd] - pref[p][X.nd.st - 1]); }
inline int get_len(pair<int, pii> &X) { return (X.nd.nd - X.nd.st + 1) * X.st; }

int get_len(map<int, pii> &M) {
   int res = 0;
   for (auto X : M)
      res += get_len(X);
   return res;
}

int get_val(map<int, pii> &M, int p) {
   int res = 0;
   for (auto X : M)
      res += get_val(X, p);
   return res;
}

void solve() {
   for (int i = MAXN - 1; i > 0; i--) {
      dp[i] = get(a, i) * get(b, i) * get(c, i);
      for (int k = 2; k < (MAXN / i); k++)
         dp[i] += (kwadr[k] * dp[i * k]);
   }
   rep(i, 5) {
      what(i);
      what(dp[i]);
   }
   cout << (dp[1] & ((1 << 30) - 1)) << endl;
}

*/

bool isprime(int n) {
   for (int i = 2; i < n; i++)
      if (!(n % i))
         return false;
   return true;
}
const int MAXN = 2001;
const int SQ = 2 * sqrt(MAXN) + 2;
const int MOD = (1 << 30) - 1;
long long dp[2][SQ][SQ][SQ];
int RA[MAXN], RB[MAXN], RC[MAXN];
int DX[MAXN][MAXN];
vector<int> A, B, C, P, huge;
int a, b, c;

vector<int> get(int x) {
   vector<int> res;
   for (int i = 1; i <= x; i++)
      res.push_back(x / i);
   sort(all(res));
   res.erase(unique(all(res)), res.end());
   return res;
}

void getR(int RD[MAXN], vector<int> &D) { rep(i, D.size()) RD[D[i]] = i; }

void pre() {
   for (int i = 2; i < MAXN; i++)
      if (isprime(i) && i < 45)
         P.push_back(i);
      else if (isprime(i))
         huge.push_back(i);
   reverse(all(P));
   A = get(a);
   B = get(b);
   C = get(c);
   getR(RA, A);
   getR(RC, C);
   getR(RB, B);
   rep(i, MAXN) for (int k = 1; k < MAXN; k++) DX[k][i] = i / k;
}

void debug() {
   for (int a : A) {
      what(a);
      what(RA[a]);
   }
   for (int p : P)
      what(p);
   rep(i, 10) cerr << huge[i] << endl;
}

void solve(int p, int cur, int last) {

   rep(i, A.size()) rep(j, B.size()) rep(k, C.size()) {
      int a = A[i];
      int l1 = 0;
      dp[cur][i][j][k] = 0;
      while (a) {
         int b = B[j], l2 = 0;
         while (b) {
            int c = C[k], l3 = 0;
            while (c) {
               dp[cur][i][j][k] = (dp[cur][i][j][k] + dp[last][RA[a]][RB[b]][RC[c]] * (l1 + l2 + l3 + 1)); //& MOD;
               c = DX[p][c], l3++;
            }
            b = DX[p][b], l2++;
         }
         a = DX[p][a], l1++;
      }
   }
}

int cnt(int a) { return upper_bound(all(huge), a) - huge.begin(); }

void solve_huge() {
   rep(i, A.size()) rep(j, B.size()) rep(k, C.size()) {
      vector<long long> Q = {cnt(A[i]), cnt(B[j]), cnt(C[k])};
      sort(all(Q));
      long long res = 0;

      res += Q[0] * Q[1] * Q[2] * 8; // pqr

      res += -Q[0] * Q[1] * 2; // pqp
      res += -Q[0] * Q[1] * 2; // pqq
      res += -Q[0] * Q[2] * 2; // ppq
      res += Q[0] * 2;         // ppp
                               // cerr << endl;
      // what(res);

      res += Q[0] * Q[1] * 4 + Q[2] * Q[1] * 4 + Q[0] * Q[2] * 4 - 2 * Q[0] - Q[1]; // pq1 q1p 1qp pp1 p1p 1pp

      // what(res);

      res += (Q[0] + Q[1] + Q[2]) * 2; // 1p1 p11 11p

      // what(res);

      res += 1; // 111

      // what(Q[0]);
      // what(Q[1]);
      // what(Q[2]);
      // what(res);

      dp[0][i][j][k] = res;
   }
}

main() {
   _upgrade;
   cin >> a >> b >> c;
   pre();
   solve_huge();

   int last = 0, cur = 1;
   for (int p : P) {
      solve(p, cur, last);
      swap(cur, last);
   }
   //  debug();
   cout << (dp[last][A.size() - 1][B.size() - 1][C.size() - 1] & MOD) << endl;
}