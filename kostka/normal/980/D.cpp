//Bartek Kostka
//  You are not prepared!

#pragma GCC optimize("O3")

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>

const int MAXE = 10001;
bool cx[MAXE];
vi primes;

void sito() {
  for(int i=2; i*i<MAXE; i++) {
    if(!cx[i]) {
      for(int j=i*i; j<MAXE; j+=i) cx[j] = true;
    }
  }
  for(int i=2; i<MAXE; i++) if(!cx[i]) primes.push_back(i);
}

int removeSquares(int n) {
  int ret = 1;
  if(!n) return 0;
  for(auto p : primes) {
    int ile = 0;
    while(n % p == 0) {
      ile++;
      n /= p;
    }
    if(ile % 2 == 1) ret *= p;
  }
  if(n > 1) ret *= n;
  return ret;
}

int main()
{
  int n;
  scanf("%d", &n);
  sito();
  vi a(n), b(n, 1);
  for(int i=0; i<n; i++) scanf("%d", &a[i]);
  for(int i=0; i<n; i++) {
    b[i] = removeSquares(abs(a[i]));
    if(a[i] < 0) b[i] *= -1;
  }
  unordered_set <int> S;
  vi ret(n+7);
  for(int i=0; i<n; i++) {
    for(int j=i; j<n; j++) {
      if(b[j] != 0) S.insert(b[j]);
      ret[max(1, SZ(S))]++;
    }
    S.clear();
  }
  ret[1] += ret[0];
  for(int i=1; i<=n; i++) printf("%d ", ret[i]);
  printf("\n");
  return 0;
}