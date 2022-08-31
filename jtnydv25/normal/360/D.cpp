#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define sd(x) scanf("%d", &(x))
#define pd(n) printf("%d\n", n)
#define vi vector<int>
#define pb push_back
#define ll long long
#define F first
#define S second

int mod = 1e9 + 7;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
	int x = 1 % mod;
	while(b){
		if(b & 1) x = mul(x, a);
		a = mul(a, a);
		b >>= 1;
	}
	return x;
}

vi get_divs(int n){
	vi ret;
	for(int i = 1; i * i <= n; i++){
		if(n % i == 0){
			ret.pb(i);
			if(i * i != n) ret.pb(n / i);
		}
	}
	return ret;
}

int find_order(int x, vector<int> & divs){
	for(int d : divs){
		if(powr(x, d) == 1) return d;
	}
}
vector<pair<int, int> > square_free;
const int N = 1e5 + 10;
int A[N], B[N], K[N], factor[N];
vi primes;
void pre(){
    for(int i = 2;i*i<N;i++) if(!factor[i]) for(int j = i*i;j<N;j+=i) factor[j] = i;
    for(int i = 2;i<N;i++) if(!factor[i]) primes.pb(i), factor[i] = i;  
}

vector<int> P;

void get_P(int n){
	int _n = n;
	for(int i = 0; primes[i] * primes[i] <= _n; i++){
		if(n % primes[i] == 0){
			P.pb(primes[i]);
			while(n % primes[i] == 0) n /= primes[i];
		}
	} 
	if(n != 1) P.pb(n);
}

void get_sqf(int ind, int cnt, int prod){
	if(ind == P.size()){
		square_free.pb({prod, cnt});
 		return;
	}
	get_sqf(ind + 1, cnt ^ 1, prod * P[ind]);
	get_sqf(ind + 1, cnt, prod);
}

int get_count(int x){
	int ret = 0;
	for(auto d : square_free){
		if(x % d.F != 0) continue;
		if(d.S) ret -= x / d.F;
		else ret += x / d.F;
	}
	return ret;
}

int main(){
	pre();
	int n, m, p;
	sd(n); sd(m); sd(p); mod = p;
	for(int i = 1; i <= n; i++) sd(A[i]);
	for(int i = 1; i <= m; i++) sd(B[i]);
	int a = p - 1;
	vi divs = get_divs(a); 
	get_P(a); 
	get_sqf(0, 0, 1);
	sort(divs.begin(), divs.end());
	for(int i = 1; i <= m; i++) a = __gcd(a, B[i]);
	for(int i = 1; i <= n; i++){
		K[i] = __gcd(a * 1ll * (p - 1) / find_order(A[i], divs), (ll)p - 1);
	}
	int ans = 0;
	for(int d : divs){
		for(int i = 1; i <= n; i++){
			if(d % K[i] == 0){
				ans += get_count((p - 1) / d);
				break;
			}
		}
	}
	printf("%d\n", ans);
}