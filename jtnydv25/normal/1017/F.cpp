#include <bits/stdc++.h>
using namespace std;

// #define int unsigned int

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

const int N = 100005;
bool done_1[4][N], done_2[4][N];
unsigned int arr1[4][N], arr2[4][N];

int n;

unsigned int value(int x, int j){
	if(x * (ll) x > n){
		return arr2[j][n / x];
	} else return arr1[j][x];
}

inline unsigned int f(int i, int j){
	if(j == 0) return i;
	if(j == 1) return ((i * (ll)(i + 1)) >> 1) & ((1LL << 32) - 1);
	if(j == 2){
		unsigned int p = i, q = i + 1, r = 2 * i + 1;
		if(p % 2 == 0) p >>= 1;
		else q >>= 1;
		if(p % 3 == 0) p /= 3;
		else if(q % 3 == 0) q /= 3;
		else r /= 3;
		return p * q * r;
	}
	unsigned int t = f(i, 1);
	return t * t;
}

unsigned int A[4];
bool prime[N];

unsigned int g(unsigned int p){
	unsigned int ret = 0;
	unsigned int v = 1;
	for(int i = 0; i<= 3; i++){
		ret += A[i] * v;
		v *= p;
	}
	return ret;
}

void precompute(int n, int k){
	for(int i = 1; i < N; i++){
		arr1[k][i] = A[k] * (f(i, k) - 1);
		arr2[k][i] = A[k] * (f(n / i, k) - 1);
	}
	int t = sqrt(n+0.5);

	for(int i = 2; i <= t; i++) if(!prime[i]){
        unsigned int p = arr1[k][i - 1];
        int lim_j = min(n / (i * i), t);
        unsigned int val = 1;
        for(int tt = 0; tt < k; tt++) val *= i;
        for(int j = 1; j <= lim_j; j++){
        	int st = i * j;
        	if(st <= t) arr2[k][j] -= val * (arr2[k][st] - p);
        	else arr2[k][j] -= val * (arr1[k][n / st] - p);
        }

        int lim2 = min(t, i * i - 1);
        for(int j = t; j > lim2; j--){
        	arr1[k][j] -= val * (arr1[k][j / i] - p);
        }
	}
}

unsigned int get(int x, int j){
	return value(x, j);
}

map<int, unsigned int> str;

unsigned int get(int x){
	if(str.find(x) != str.end()) return str[x];
	unsigned int ret = 0;
	for(int i = 0; i < 4; i++) ret += get(x, i);
	return str[x] = ret;
}



int main(){
	cin >> n;
	prime[1] = prime[0] = 1;
	for(int i = 2; i * i < N; i++)
		if(!prime[i])
		for(int j = i * i;j < N; j += i) prime[j] = 1;
	for(int j = 0; j <=3; j++){
		cin >> A[3-j];
		precompute(n, 3 - j);
	}

	clock_t st = clock();
	unsigned int ans = 0;
	unsigned int p;
	for(p = 2; p * p <= n; p++){
		if(prime[p]) continue;
		unsigned int gp = g(p);
		unsigned int sm = 0;
		for(unsigned int x = n / p; x > 0; x /= p) sm += x;
		ans += sm * gp;
	}
	int i = 1, lo = n / (i + 1), hi = n / i;
	while(hi >= p){
		lo = max((int)p - 1, lo);
		ans += i * (get(hi) - get(lo));
		i++;
		hi = lo;
		lo = n / (i+1);
	}

	cout << ans<<  endl;

	cerr << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
}