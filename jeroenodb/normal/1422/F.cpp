#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9, S=87;
const long long MOD = 1e9+7;
vi primes;
class mint {
public:
	int d;
	mint () {d=0;}
	mint (long long _d) : d(_d%MOD){};
	mint operator*(const mint& o) const {
		return ((ll)d*o.d)%MOD;
	}
	mint operator+(const mint& o) const {
		long long tmp = d+o.d;
		if(tmp>=MOD) tmp-=MOD;
		return tmp;
	}
	mint operator-(const mint& o) const {
		long long tmp = d-o.d;
		if(tmp<0) tmp+=MOD;
		return tmp;
	}
	mint operator^(long long b) const {
		mint tmp = 1;
		mint power = *this;
		while(b) {
			if(b&1) {
				tmp = tmp*power;
			}
			power = power*power;
			b/=2;
		}
		return tmp;
	}
	mint operator/(const mint& o) {
		return *this * (o^(MOD-2));
	}
	bool operator==(const mint& o) {
		return d==o.d;
	}
	friend mint& operator+=(mint& a, const mint& o) {
		a.d+=o.d;
		if(a.d>=MOD) a.d-=MOD;
		return a;
	}
};

const int store=3e5 + 1;
bitset<store> sieve={};
int factor[store] = {};
void makesieve() {
	for(int i = 2; i < store;++i) {
		if(!sieve[i]) {
			primes.push_back(i);
			for(int j = i;j<store;j+=i) {
				if(!sieve[j]) {
					factor[j] = i;
					sieve[j] = i!=j;
				}
			}
		}
	}
}

struct info {
	array<int,S> small={};
	vector<pair<int,int>> prev;
	int total() {
		mint ans=prev[0].second;
		for(int i=0;i<S;++i) {
			ans = ans* (mint(primes[i])^small[i]);
		}
		return ans.d;
	}
	void comb(const info& r, int l=-1) {
		for(int i=0;i<S;++i) {
			small[i] = max(small[i],r.small[i]);
		}
		if(l!=-1) {
			auto it = lower_bound(all(r.prev),pi{l,0});
			if(it!=r.prev.begin()) {
				--it;
				prev[0].second=((ll)prev[0].second* it->second)%MOD;
			}
		} else {
			vector<pi> v;
			merge(all(prev), all(r.prev),back_inserter(v));
			prev=v;
		}
	}
	void build() {
		for(int i=1;i<(int)prev.size();++i) {
			prev[i].second = ((ll)prev[i-1].second*prev[i].second)%MOD;
		}
	}
};
struct segtree {
	int ptwo;
	vector<info> seg;
	segtree(){}
	info& operator[](int i) {
		return seg[i+ptwo];
	}
	segtree(int nn) {
		ptwo=1;
		while(ptwo<nn) 
			ptwo*=2;
		seg.resize(ptwo*2);
	}
	auto query(int l, int r) {
		int reall=l;
		assert(l>=0 and l<ptwo and r >=0 and r<ptwo);
		l+=ptwo; r+=ptwo;
		info res;
		res.prev = {{1,1}};
		while(l and l<=r) {
			if(l%2==1) res.comb(seg[l++],reall);
			if(r%2==0) res.comb(seg[r--],reall);
			l/=2; r/=2;
		}
		return res;
	}
	void build() {
		for(int i=ptwo-1;i>0;--i) {
			seg[i] = seg[2*i];
			seg[i].comb(seg[2*i+1]);
		}
		for(int i=ptwo-1;i>0;--i) {
			seg[i].build();
		}
		
	}
};
int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	makesieve();
    int n; cin >> n;
	segtree seg(n);
	vi bigp(n);
	for(int i=0;i<n;++i) {
		auto& p = seg[i].small;
		int a; cin >> a;

		while(a>1 and factor[a]<=primes[S-1]) {
			int f = factor[a];
			int id = lower_bound(primes.begin(), primes.begin()+S,f)-primes.begin();
			// assert(id<S);
			do {
				p[id]++;
				a/=f;
			} while(f==factor[a]);
		}
		while(factor[a]>primes[S-1]) {
			bigp[i] = factor[a];
			a/=factor[a];
		}
	}
	map<int,int> prev;
	for(int i=0;i<n;++i) {
		if(bigp[i]==0) continue;
		if(prev.count(bigp[i])) {
			seg[i].prev.push_back({prev[bigp[i]],bigp[i]});
		} else {
			seg[i].prev.push_back({-1,bigp[i]});
		}
		prev[bigp[i]] = i;
	}
	seg.build();
	int q; cin >> q;
	int last=0;
	for (int i = 0; i < q; ++i) {
		int x,y; cin >> x >> y;
		x+=last; y+=last;
		x%=n;
		y%=n;
		if(x>y) swap(x,y);
		last = seg.query(x,y).total();
		cout << last << '\n';
	}
}