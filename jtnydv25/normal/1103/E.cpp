#include <bits/stdc++.h>
using namespace std;

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

#define ull unsigned long long

struct data{
	vector<ull> D;
	data(){ D.resize(10, 0); }
	data(int i){
		D.resize(10, 0);
		D[i] = 1;
	}
	data operator + (const data & D1) const{
		data ret;
		for(int i = 0; i < 10; i++) ret.D[i] = D[i] + D1.D[i];
		return ret;
	}
	data shift(int i){
		data ret;
		int j = 0;
		for(;j + i < 10; j++) ret.D[i + j] = D[j];
		for(; j < 10; j++) ret.D[i + j - 10] = D[j];
		return ret;
	}
	data operator * (const data & D1) const{
		data ret;
		for(int i = 0; i < 10; i++){
			if(!D[i]) continue;
			for(int j = 0; i + j < 10; j++){
				ret.D[i + j] += D[i] * D1.D[j]; 
			}
			for(int j = 10 - i; j < 10; j++){
				ret.D[i + j - 10] += D[i] * D1.D[j];
			}
		}
		return ret;
	}

	data power(int n){
		data x = data(0);
		data y = *this;
		for(; n; n >>= 1, y = y * y){
			if(n & 1) x = x * y;

		}
		return x;
	}
	void print(){
		cout << "[ ";
		for(auto it : D) cout << it << " "; cout << "]" << endl;
	}
};


ull get_inv(ull x, int p){
	ull pwr = (1LL << (p - 1)) - 1;
	ull y = 1;
	for(; pwr > 0; pwr >>= 1, x *= x){
		if(pwr & 1) y *= x;
	}
	return y;
}

void get(vector<data> & v, int m, int n, int p, int p2, ull mod){
	if(p == 0){
		v[0] = v[0].power(m);
		return;
	}

	vector<data> A[10], F[10];

	int sz_sub = n / 10;

	for(int i = 0; i < 10; i++){
		for(int j = 0; j < sz_sub; j++)
			A[i].push_back(v[i * sz_sub + j]);
	}
	for(int j = 0; j < 10; j++){
		F[j].resize(sz_sub, data());
		for(int i = 0; i < 10; i++){
			data D = data(i * j % 10);
			for(int k = 0; k < sz_sub; k++){
				F[j][k] = F[j][k] + D * A[i][k];
			}
		}
	}

	for(int i = 0; i < 10; i++) get(F[i], m, sz_sub, p - 1, p2 + 1, mod * 2);

	for(int i = 0; i < 10; i++)
		for(int j = 0; j < sz_sub; j++) A[i][j] = data();

	ull I = get_inv(5, p2);

	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			int t = (i * j) % 10;
			t = 10 - t;
			if(t == 10) t = 0;
			data D = data(t);
			for(int k = 0; k < sz_sub; k++){
				A[i][k] = A[i][k] + D * F[j][k];
			}
		}
		for(int k = 0; k < sz_sub; k++){
			v[i * sz_sub + k] = A[i][k];
		}
	}
}

vector<data> V(100000, data());

int main(){
	int n; sd(n);
	for(int i = 1; i <= n; i++){
		int t;
		sd(t);
		V[t] = V[t] + data(0);
	}
	get(V, n, 100000, 5, 58, 1LL << 58);	
	const ull mod = 1LL << 58;
	ull I = get_inv(5 * 5 * 5 * 5 * 5, 58);
	for(int i = 0; i < n; i++){
		ull x = V[i].D[0] + V[i].D[1] - V[i].D[2] - V[i].D[5];
		x >>= 5	;
		x *= I;
		printf("%lld\n", (ll)(x % mod));
	}
}