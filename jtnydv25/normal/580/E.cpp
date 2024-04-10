#include <bits/stdc++.h>
using namespace std;
#define ll long long

int const N = 2e5 + 10;
int const X = 33533;
long long M1;
long long M2;
long long const MASK = (1LL << 32) - 1;

long long POW1[N], POW2[N], CPOW1[N], CPOW2[N];

int s[N];

int bal[N];

struct Hash {
  long long h;
  int len;  
};

bool operator == (Hash const & a, Hash const & b) {
  return a.len == b.len && a.h == b.h;
}

long long add1(long long h1, long long h2, int len2) {
  return (h1 * POW1[len2] + h2) % M1;
}

long long add2(long long h1, long long h2, int len2) {
  return (h1 * POW2[len2] + h2) % M2;
}

Hash operator+ (Hash const & a, Hash const & b) {
  return {(add1(a.h >> 32, b.h >> 32, b.len) << 32) | add2(a.h & MASK, b.h & MASK, b.len), a.len + b.len};
}

inline Hash get_Hash_char(char c){
	return {(((ll)(c - '0' + 1)) << 32) | (c - '0' + 1), 1};
}

inline Hash get_Hash_repeated_char(int n, char c){
	return {((((c - '0' + 1) * 1ll * CPOW1[n - 1]) % M1) << 32) | (((c - '0' + 1) * 1ll * CPOW2[n - 1]) % M2), n};
}

int n;
Hash tree[N << 1];
char lazy[N << 1], a[N]; bool lazyb[N << 1];
void go(int s, int e, int node){
	if(!lazyb[node]) return;
	Hash hs = get_Hash_repeated_char(e - s + 1, lazy[node]);
	tree[node] = hs;
	lazyb[node] = 0;
	if(s == e) return;
	lazyb[2 * node] = 1; lazy[2 * node] = lazy[node];
	lazy[2 * node + 1] = lazy[node]; lazyb[2 * node + 1] = 1;
}
Hash make(int s = 1, int e = n, int ind = 1){
	if(s == e) return tree[ind] = get_Hash_char(a[s - 1]);
	int mid = (s + e) >> 1;
	return tree[ind] = make(s, mid, 2 * ind) + make(mid + 1, e, 2 * ind + 1);
}
void update(int l, int r, char m, int ind = 1, int s = 1, int e = n){
	go(s, e, ind);
	if(l > e || s > r) return;
	if(s >= l && e <= r){
		lazy[ind] = m; lazyb[ind] = 1;
		go(s, e, ind);
		return;
	}
	int mid = (s + e) >> 1;
	update(l, r, m, 2 * ind, s, mid);
	update(l, r, m, 2 * ind + 1, mid + 1, e);
	tree[ind] = tree[2 * ind] + tree[2 * ind + 1];
}
Hash zero = {0LL, 0};
Hash get_Hash(int l, int r, int ind = 1, int s = 1, int e = n){
	if(l > e || s > r) return zero;
	go(s, e, ind);
	if(s >= l && e <= r) return tree[ind];
	int mid = (s + e) >> 1;
	return get_Hash(l, r, 2 * ind, s, mid) + get_Hash(l, r, 2 * ind + 1, mid + 1, e);
}

std::mt19937 rnd(std::chrono::system_clock::now().time_since_epoch().count());
  
int const HALFBILLION = 500000000;

bool prime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}

void gen(long long & M) {
  M = rnd() % HALFBILLION + HALFBILLION;
  while (!prime(M)) {
    ++M;
  }
}
int main() {
  gen(M1);
  gen(M2);
  POW1[0] = POW2[0] = CPOW1[0] = CPOW2[0] = 1;
  for (int i = 1; i < N; i++) {
    POW1[i] = POW1[i - 1] * X % M1;
    POW2[i] = POW2[i - 1] * X % M2;
    CPOW1[i] = (CPOW1[i - 1] + POW1[i]) % M1;
    CPOW2[i] = (CPOW2[i - 1] + POW2[i]) % M2;
  }
  int m, k; scanf("%d %d %d", &n, &m, &k);
  scanf("%s", a);
  make();
  int q = m + k;
  int type, l, r, d;
  while(q--){
  	scanf("%d %d %d %d", &type, &l, &r, &d);
  	if(type == 1){
  		update(l, r, to_string(d)[0]);
  		continue;
  	}
  	Hash h1 = get_Hash(l, r - d), h2 = get_Hash(l + d, r);
  	if(h1 == h2) printf("YES\n");
  	else printf("NO\n");
  }
}