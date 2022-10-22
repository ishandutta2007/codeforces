#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep1(i, n) for(int i = 1; i <= n; ++i)
#define _ << " " <<

typedef pair<int, int> point;
typedef long long ll;
typedef double lf;

const int MAXN = 1e6 + 5, MOD = 1e9 + 7, p1 = 105023, p2 = 15486277, p3 = 179425033;

int a[MAXN];
int q[MAXN];
vector<int> M[MAXN];

bool noneed[MAXN];

int mx, mk = 1;

int n, m, T;

void ispis() {
   printf("%d %d\n", mk, mx);
   rep(i, n)
      if(a[i] <= m && mk % a[i] == 0)
         printf("%d ", i + 1);
   puts("");
}

void solve(int k) {

   if((lf)(clock() - T) / CLOCKS_PER_SEC > 1.3) {
      ispis();
      exit(0);
   }

   if(noneed[k])
      return;

   vector<int> div;

   int x = 2, A = k;

   for(int x = 1; x * x <= A; ++x) {
      if(A % x == 0 && x * x != A) {
         div.push_back(x);
         div.push_back(A / x);
      }
      else if(A % x == 0) {
         div.push_back(x);
      }
   }

   int tmp = 0;

   int tk = 1;

   for(auto x : div) {
      noneed[x] = true;
      tmp += q[x];
      if(q[x]) {
         int GCD = __gcd(x, tk);
         tk = (ll)tk * x / GCD;
      }
   }

   if(tmp > mx) {
      mx = tmp;
      mk = tk;
   }

}

int main() {

   scanf("%d %d", &n, &m);

   rep(i, n) {
      scanf("%d", &a[i]);
      if(a[i] > m)
         continue;
      q[a[i]] ++;
   }

   T = clock();

   for(int i = m; i; --i) {
      solve(i);
   }

   ispis();
}