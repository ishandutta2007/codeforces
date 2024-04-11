#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 200005;

lint G(lint x, lint y){ return y ? G(y, x%y) : x; } 

namespace miller_rabin{
    lint mul(lint x, lint y, lint mod){
    	lint ret = 0;
    	while(y){
    		if(y & 1) ret = (ret + x) % mod;
    		x = (x + x) % mod;
    		y >>= 1;
		}
		return ret;
	}
	lint ipow(lint x, lint y, lint p){
		lint ret = 1, piv = x % p;
		while(y){
			if(y&1) ret = mul(ret, piv, p);
			piv = mul(piv, piv, p);
			y >>= 1;
		}
		return ret;
	}
	bool miller_rabin(lint x, lint a){
		if(x % a == 0) return 0;
		lint d = x - 1;
		while(1){
			lint tmp = ipow(a, d, x);
			if(d&1) return (tmp != 1 && tmp != x-1);
			else if(tmp == x-1) return 0;
			d >>= 1;
		}
	}
	bool isprime(lint x){
		for(auto &i : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
			if(x == i) return 1;
			if(x > 40 && miller_rabin(x, i)) return 0;
		}
		if(x <= 40) return 0;
		return 1;
	}

}

namespace pollard_rho{
	lint f(lint x, lint n, lint c){
		return (c + miller_rabin::mul(x, x, n)) % n;
	}
	void rec(lint n, vector<lint> &v){
		if(n == 1) return;
		if(n % 2 == 0){
			v.push_back(2);
			rec(n/2, v);
			return;
		}
		if(miller_rabin::isprime(n)){
			v.push_back(n);
			return;
		}
		lint a, b, c;
		while(1){
			a = rand() % (n-2) + 2;
			b = a;
			c = rand() % 20 + 1;
			do{
				a = f(a, n, c);
				b = f(f(b, n, c), n, c);
			}while(G(abs(a-b), n) == 1);
			if(a != b) break;
		}
		lint x = G(abs(a-b), n);
		rec(x, v);
		rec(n/x, v);
	}
	vector<lint> factorize(lint n){
		vector<lint> ret;
		rec(n, ret);
		sort(ret.begin(), ret.end());
		vector<lint> realret = {1};
		for(int i=0; i<ret.size(); ){
			int e = i;
			while(e < ret.size() && ret[i] == ret[e]) e++;
			int cnt = e - i;
			int psz = realret.size();
			for(int j=1; j<=cnt; j++){
				for(int k=0; k<psz; k++){
					realret.push_back(ret[i] * realret[realret.size() - psz]);
				}
			}
			i = e;
		}
		return realret;
	}
};

int n;
lint a[MAXN], b[MAXN], c[MAXN];

vector<lint> da, db, divisor;
lint colsum[MAXN], rowsum[MAXN];

int main(){
	srand(time(0));
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%lld %lld %lld",&a[i],&b[i],&c[i]);
	for(int i=1; i<=n; i++){
		da.push_back(a[i]);
		db.push_back(b[i]);
	}
	sort(da.begin(), da.end());
	da.resize(unique(da.begin(), da.end()) - da.begin());
	sort(db.begin(), db.end());
	db.resize(unique(db.begin(), db.end()) - db.begin());
	if(1ll * (int)da.size() * (int)db.size() != n){
		puts("0");
		return 0;
	}
	lint cs = 0;
	for(int i=1; i<=n; i++){
		cs = G(c[i], cs);
	}
	divisor = pollard_rho::factorize(cs);
	for(int i=1; i<=n; i++){
		int lb = lower_bound(da.begin(), da.end(), a[i])-da.begin();
		a[i] = lb;
		lb = lower_bound(db.begin(), db.end(), b[i]) - db.begin();
		b[i] = lb;
		c[i] /= cs;
		colsum[a[i]] = G(colsum[a[i]], c[i]);
		rowsum[b[i]] = G(rowsum[b[i]], c[i]);
	}
	for(int i=1; i<=n; i++){
		if(colsum[a[i]] != c[i] / rowsum[b[i]] || colsum[a[i]] * rowsum[b[i]] != c[i]){
			divisor.clear();
		}
	}
	cout << divisor.size() << endl;
}