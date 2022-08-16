#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;

inline int add(int x, int y){
	x += y;
	if(x >= mod) x -= mod;
	return x;
}

inline int sub(int x, int y){
	x -= y;
	if(x < 0) x += mod;
	return x;
}

inline int mul(int x, int y){
	return (x * 1ll * y) % mod;
}

inline int powr(int x, int y){
	int ret = 1;
	for(; y; y >>= 1, x = mul(x, x))
		if(y & 1)
			ret = mul(ret, x);
	return ret;
}

const int N = 100005;
int fact[N], invfact[N];
int pw25[N], pw26[N], invpw26[N];
void pre(){
	fact[0] = pw25[0] = pw26[0] = invpw26[0] = 1;
	int inv26 = powr(26, mod - 2);
	for(int i = 1; i < N; i++){
		pw25[i] = mul(25, pw25[i - 1]);
		pw26[i] = mul(26, pw26[i - 1]);
		invpw26[i] = mul(inv26, invpw26[i - 1]);
		fact[i] = mul(fact[i - 1], i);
	}
	invfact[N - 1] = powr(fact[N - 1], mod - 2);
	for(int i = N - 2; i >= 0; i--) invfact[i] = mul(invfact[i+1], i+1);
	assert(invfact[0] == 1);
}

inline int C(int n, int k){
	if(k < 0 || n < 0 || n < k) return 0;
	return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

char s[N];
vector<pair<int, int> > queries;
set<int> st;
map<int, int> compress;
int store[450][N];
void pre2(int m){
	int ind = compress[m];
	for(int l = m; l < N; l++){
		store[ind][l] = add(store[ind][l - 1], mul(pw25[l - m], mul(C(l - 1, m - 1), invpw26[l])));
	}
}

int get(int m, int n){
	return mul(pw26[n], store[compress[m]][n]);
}
int main(){
	pre();
	int t; 
	scanf("%d", &t);
	scanf("%s", s);
	int m = strlen(s), n = 0;
	st.insert(m);
	for(int i = 1; i <= t; i++){
		int type;
		scanf("%d", &type);
		if(type == 1){
			scanf("%s", s);
			m = strlen(s);
			st.insert(m);
		}
		else{
			scanf("%d", &n);
			queries.push_back({m, n});
		}
	}
	int cnt = 0;
	for(int x : st){
		compress[x] = ++cnt;
		pre2(x);
	}
	for(auto it : queries) printf("%d\n", get(it.first, it.second));
}