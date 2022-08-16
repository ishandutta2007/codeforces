#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T> ostream& operator <<(ostream& os, vector<T> V){
	os << "[ "; for(auto v : V) os << v << " "; return os <<"]";
}
template<class L, class R> ostream& operator<<(ostream& os , pair<L, R> P){
	os <<"(" << P.first << " , " << P.second << ")";
}
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cout << name << " : " << arg1 << endl;
}
template<typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma=strchr(names+1 , ',');
	cout.write(names, comma-names) << " : " << arg1 << " | ";
	__f(comma+1 , args...);
}
#else
#define trace(...) 1
#endif 
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vll vector<ll>
#define vi vector<int>
#define I insert
#define F first
#define S second
#define pb push_back
#define endl "\n"
#define all(x) x.begin(), x.end()
#define For(i,n) for(int i = 0;i < n; i++)
#define Rep(i,n) for(int i = 1;i <= n ;i++)
const int R = 1e6 + 200;

ll n , m , a , Q , r;
ll rem[R] , fac[R] , inv[R];

ll power(ll x , ll y){
	ll res = 1;
	while(y){
		if(y&1){
			res = res*x%r;
		}
		x = (x*x)%r;
		y >>= 1;
	}
	return res;
}
void pre(){
	fac[0] = 1;
	for(ll i = 1;i < r ; i++){
		fac[i] = (fac[i-1]*i)%r;
		// trace(fac[i]);
	}
	inv[r-1] = power(fac[r-1] , r-2);
	for(ll i = r-2 ;i >= 0 ; i--){
		inv[i] = ( (i+1)*inv[i+1])%r;
		// trace(i ,  (inv[i]*fac[i])%r);
	}
}
ll nCr(ll n , ll k){
	if(k > n)
		return 0;
	return (((fac[n]*inv[k]) % r) * inv[n-k]) % r;
}

ll anpow[R];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cout << setprecision(25);
	cin >> n >> m >> a >> Q;

	rem[0] = 1;
	for(int i = 1;i < R ; i++){
		rem[i] = (rem[i-1]*a)%Q;
		if(rem[i] == 1){
			r = i;
			break;
		}
	}
	// trace(r);
	// r = 101;
	pre();

	// anpow[0] = 1;
	for(int j = m;j <= m ; j++){
		anpow[0] = 1;
		// cout << 1 << ' ';
		for(int i = 1;i < n; i++){
			// trace(j , i , nCr(j , i));
			anpow[i] = (anpow[i-1] + nCr(j , i))%r;
			// cout << anpow[i] << ' ';
		}
		// cout << endl;
	}

	for(int i = 0;i < n; i++)
		anpow[i] = rem[anpow[i]];

	for(int i = n-1 ;i >= 0 ; i--)
		cout << anpow[i] << ' ';
	cout << endl;


	return 0;
}