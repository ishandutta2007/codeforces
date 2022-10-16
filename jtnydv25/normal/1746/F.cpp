#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl '\n' // remove in interactive
#endif

const int N = 6e5 + 10;

// 0-indexed
template<class T>
struct BIT{
	int n;
	vector<T> F;
	BIT(){}
	BIT(int n) : n(n), F(n + 1){};
	void init(){
		fill(all(F), 0);
	}
	void add(int i, T w){
		i++;
		for(; i <= n; i += (i & (-i))) F[i] += w;
	}
	T get(int i){
		i++;
		T ret = 0;
		for(; i; i -=(i & (-i))) ret += F[i];
		return ret;
	}
	T get(int i, int j){ return get(j) - get(i - 1);}
};

// mt19937_64 for 64 bit
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int getRand(int x, int y){
	return uniform_int_distribution<int>(x, y)(rng);
}

struct Data{
	int n;
	int * F;
	BIT<ll> B;
	vector<int> A;
	Data(){}
	Data(int n) : n(n){
		F = new int[N];
		for(int i = 1; i < N; i++){
			F[i] =  getRand(1, 1000000000);
		}
		B = BIT<ll>(n + 1);
	}
	void init(vector<int>& a){
		A = a;
		for(int i = 1; i <= n; i++){
			B.add(i, F[a[i]]);
		}
		ll v = B.get(1, 6);
		// trace(F[6], v);
	}
	void update(int i, int j){
		B.add(i, -F[A[i]]);
		A[i] = j;
		B.add(i, F[A[i]]);
	}
};

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int n, q; cin >> n >> q;
	vector<int> type(q), l(q), r(q), k(q);
	map<int, int> mp;
	vector<int> a(n + 1);
	set<int> st;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		st.insert(a[i]);
	}


	const int L = 25;

	vector<Data> D(L);
	for(int j = 0; j < L; j++) D[j] = Data(n);
	for(int i = 0; i < q; i++){
		cin >> type[i] >> l[i] >> r[i];
		if(type[i] == 2) cin >> k[i];
		if(type[i] == 1) st.insert(r[i]);
	}

	int cnt = 0;
	for(auto it: st) mp[it] = ++cnt;
	for(int i = 1; i <= n; i++) a[i] = mp[a[i]];
	for(int i = 0; i < q; i++) if(type[i] == 1) r[i] = mp[r[i]];
	for(int j = 0; j < L; j++) D[j].init(a);
	
	for(int i = 0; i < q; i++){
		if(type[i] == 2){
			bool ok = true;
			for(int j = 0; j < L; j++) if(D[j].B.get(l[i], r[i]) % k[i] != 0){
				ok = false;
				break;
			}
			cout << (ok ? "YES"  : "NO") << endl;
		} else{
			for(int j = 0; j < L; j++) D[j].update(l[i], r[i]);
		}
	}
}