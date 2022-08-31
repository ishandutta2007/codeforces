#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";
#define sd(x) scanf("%d", &(x))
const int mod = 1e9 + 7;
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

#define vi vector<int>
#define pb push_back
vi primes;
const int N = 2e6 + 10;
int factor[N], st[N], en[N], a[N], inverse[N], prod[N], val[N], inv2[N];
void pre(){
    for(int i = 2;i*i<N;i++) if(!factor[i]) for(int j = i*i;j<N;j+=i) factor[j] = i;
    for(int i = 2;i<N;i++) if(!factor[i]) factor[i] = i;
    for(int i = 1; i < N; i++)	inverse[i] = inv(i), val[i] = mul(i - 1, inverse[i]), inv2[i] = mul(i, inverse[i - 1]);
    val[1] = inv2[1] = 1;
}

map<pair<int, int>, int > ans;
vector<pair<int, int> > que;
vector<int> qu[N];
#define mp make_pair
map<int, int> lst;
int tree[3 * N], nxt[N], hi;
void update(int i, int v, int s = 1, int e = hi, int ind = 1){
	if(s > i || e < i) return;
	tree[ind] = mul(tree[ind], v);
	if(s == e) return;
	int mid = (s + e) >> 1;
	update(i, v, s, mid, ind << 1);
	update(i, v, mid + 1, e, (ind << 1) + 1);
}
int get(int l, int r, int s = 1, int e = hi, int ind = 1){
	if(s > r || l > e) return 1;
	if(s >= l && e <= r) return tree[ind];
	int mid = (s + e) >> 1;
	return mul(get(l, r, s, mid, ind << 1), get(l, r, mid + 1, e, (ind << 1) + 1));
}

int main(){
	for(int i = 0; i < 3 * N; i++) tree[i] = 1;
	pre();
	int n, q, l, r;
	sd(n);
	prod[0] = 1;
	primes.pb(0);
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		prod[i] = mul(prod[i - 1], a[i]);
		int x = a[i];
		primes.pb(1);
		while(x > 1){
			int p = factor[x];
			while(x % p == 0) x /= p;
			primes.push_back(p);
		}
		en[i] = primes.size() - 1;
	}
	sd(q);
	// required range -> en[l - 1] + 1 -> en[r]
	while(q--){
		sd(l), sd(r);
		que.pb(mp(l, r));
		qu[en[l - 1] + 1].pb(en[r]);
	}
	n = primes.size() - 1; hi = n + 1;
	// print(primes);
	for(int i = n; i >= 1; i--){
		int p = primes[i];
		update(lst[p], inv2[p]);
		lst[p] = i;
		update(lst[p], val[p]);
		for(int r : qu[i]){
			ans[{i, r}] = get(i, r);
		}
	}
	for(auto it: que){
		int l = it.first, r = it.second;
		int answer = mul(mul(prod[r], inv(prod[l - 1])), ans[{en[l - 1] + 1, en[r]}]);
		printf("%d\n", answer);
	}
}