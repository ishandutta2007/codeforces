#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())
#define ld long double

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<", "<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<", ";
		os<<v[i];
	}
	os<<"}";
	return os;
}

#ifdef LOCAL
#define cerr cout
#else
#endif

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

const int mod = 998244353;
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
inline int inv(int a){ return powr(a, mod - 2);}

void fwht(vector<int> & data, bool invert = false) {
	int dim = data.size();
    for (int len = 1; 2 * len <= dim; len <<= 1) {
        for (int i = 0; i < dim; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                int a = data[i + j];
                int b = data[i + j + len];
                
                data[i + j] = add(a, b);
                data[i + j + len] = sub(a, b);
            }   
        }
    }
    if(invert){
        int invdim = inv(dim);
    	for(int i = 0; i < dim; i++) data[i] = mul(data[i], invdim);
    }
}

const int K = 17, N = 1 << K;
unsigned long long temp[K][1 << K];
int fact[N], invfact[N];

void pre(){
	fact[0] = invfact[0] = 1;
	for(int i = 1;i < N; i++) fact[i] = mul(i, fact[i - 1]);
	invfact[N - 1] = inv(fact[N - 1]);
	for(int i = N - 2; i >= 1; i--) invfact[i] = mul(invfact[i + 1], i + 1);
	assert(invfact[1] == 1);
}

#define poly vector<vector<int>>

void mul(poly & A, poly B){
	int sA = A[0].size(), sB = B[0].size();
	assert(!(sA & (sA - 1)));
	assert(!(sB & (sB - 1)));

	while(sA < sB) sA <<= 1;
	while(sB < sA) sB <<= 1;

	for(int i = 0; i < K; i++){
		A[i].resize(sA);
		B[i].resize(sB);
		fwht(A[i]), fwht(B[i]);
		for(int j = 0; j < sA; j++) temp[i][j] = 0;
	}

	for(int i = 0; i < K; i++)
		for(int j = 0; i + j < K; j++)
			for(int u = 0; u < sA; u++)
				temp[i + j][u] += A[i][u] * (ll) B[j][u];

	for(int i = 0; i < K; i++){
		for(int j = 0; j < sA; j++) A[i][j] = temp[i][j] % mod;
		fwht(A[i], 1);
	}
}

void square(poly & A){
	int sA = A[0].size();
	for(int i = 0; i < K; i++){
		fwht(A[i]);
		for(int j = 0; j < sA; j++) temp[i][j] = 0;
	}
	for(int i = 0; i < K; i++)
		for(int j = 0; i + j < K; j++)
			for(int u = 0; u < sA; u++)
				temp[i + j][u] += A[i][u] * (ll) A[j][u];
	
	for(int i = 0; i < K; i++){
		for(int j = 0; j < sA; j++) A[i][j] = temp[i][j] % mod;
		fwht(A[i], 1);
	}
}

poly power(poly A, int k){
	poly ret(K, vector<int>(A[0].size(), 0));
	ret[0][0] = 1;
	for(; k; k >>= 1, square(A)){
		if(k & 1) mul(ret, A);
	}
	return ret;
}

void mulpower(poly & ret, poly & A, int k){
	for(; k; k >>= 1, square(A)){
		if(k & 1) mul(ret, A);
	}
}

int main(){
	pre();
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
  	int n, k, c;
	cin >> n >> k >> c;
	int _c = c;
	c = max(c, 4);
	vector<int> num(1 << c);
	for(int i = 0; i < n; i++){
		int x = i + k; 
		cin >> x;
		num[x]++;
	}
	vector<vector<int>> cnt(c + 1);
	vector<int> dim(c + 1);
	for(int i = 4; i <= c; i++){
		cnt[i].resize(dim[i] = i == c ? 16 : 1 << (i + 1));
	}
	int fixed_xor = 0;
	for(int i = k; i < (1 << c); i++) if(num[i]){
		int h = c;
		for(int j = 4; j < c; j++) if(i >> j & 1){
			h = j;
			break;
		}
		if(h != c){
			fixed_xor ^= (i & ((1 << c) - (1 << (h + 1))));
		}
		cnt[h][i & ((1 << (h + 1)) - 1)]++;
		int u = i & ((1 << (h + 1)) - 1);
	}
	vector<vector<int>> cur(K, vector<int>(16, 0));
	cur[0][0] = 1;
	for(int i = 4; i <= c; i++){
		for(int j = 0; j < dim[i]; j++) if(cnt[i][j]){
			poly here(K, vector<int>(dim[i], 0));
			for(int l = 0; l <= k; l++){
				here[l][j - l] = invfact[l];
			}
			mulpower(cur, here, cnt[i][j]);
		}
	}
	vector<int> answers(1 << c, 0);
	for(int i = 0; i < cur[k].size(); i++){
		answers[fixed_xor ^ i] = add(answers[fixed_xor ^ i], mul(fact[k], cur[k][i]));
	}
	int inv_tot = inv(powr(n, k));
	for(int i = 0; i < (1 << _c); i++) cout << mul(answers[i], inv_tot) << " ";
	cout << endl;
}