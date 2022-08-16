#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
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

const int N = 200005;
const int K = 10;

int deg[N];
vector<int> adj[N];

int U[N], V[N], W[N];

template<class T>
struct graph{
	vector<ll> adj_other; // masks of neighbors
	vector<ll> adj_same;
	vector<T> weights;
	int n, p, q;
	graph(int n, vector<T> W = {}): n(n), adj_same(n), adj_other(n){
		const int min_p = n - 25;
		p = min(n, max(min_p, (n + 3) / 2));
		// p = 0;
		q = n - p;
		if(W.empty()) weights.assign(n, 1);
		else weights = W;
	}
	void add_edge(int u, int v){
		if(u==v) return;
		if((u < p) == (v < p)){
			adj_same[u] |= 1LL << (v - (v >= p) * p);
			adj_same[v] |= 1LL << (u - (u >= p) * p);
		} else{
			adj_other[u] |= 1LL << (v - (v >= p) * p);
			adj_other[v] |= 1LL << (u - (u >= p) * p);
		}
	}
	pair<T, int> maximum_independent_set(bool find_set = false){
		vector<T> MIS(1 << q, 0);
		vector<int> numMIS(1 << q);
		for(int mask = 0; mask < (1 << q); mask++){
			bool is_mask_independent = true;
			T sum = 0;
			for(int l = 0; l < q; l++) if(mask >> l & 1){
				if(adj_same[l + p] & mask) is_mask_independent = false;
				sum += weights[l + p];
			}
			if(is_mask_independent){
				MIS[mask] = sum;
				numMIS[mask] = 1;
			}
		}

		for(int i = 0; i < q; i++){
			for(int j = (1 << q) - 1; j >= 0; j--) if(j >> i & 1){
				int R = j ^ (1 << i);
				if(MIS[j] == MIS[R]){
					numMIS[j] += numMIS[R];
				} else if(MIS[j] < MIS[R]){
					numMIS[j] = numMIS[R];
					MIS[j] = MIS[R];
				}
			}
		}

		T ans = 0;
		int num = 0;

		vector<bool> isIndependent(1 << p, true);
		vector<T> totalWeight(1 << p);
		vector<int> Possible(1 << p);
		vector<int> some(1 << p);

		Possible[0] = (1 << q) - 1;

		for(int mask = 0; mask < (1 << p); mask++){
			bool is_mask_independent = true;
			if(mask){
				int l = (some[mask] = mask & 1 ? 0 : some[mask >> 1] + 1);
				int R = mask ^ (1 << l);
				isIndependent[mask] = isIndependent[R] && !(adj_same[l] & mask); 
				totalWeight[mask] = totalWeight[R] + weights[l];
				Possible[mask] = Possible[R] & ~adj_other[l];
			}
			if(isIndependent[mask]){
				int possible = Possible[mask];
				T now = totalWeight[mask] + MIS[possible];
				if(now > ans){
					num = numMIS[possible];
					ans = now;
				} else if(now == ans){
					num += numMIS[possible];
				}
			}
		}
		return {ans, num};
	}
};

int ID[K][K];
int there[N][50];
bool E[50][50];

int main(){
	int n, m, k;
	sd(n); sd(m); sd(k);
	for(int i = 0; i < m; i++){
		sd(U[i]); sd(V[i]); sd(W[i]);
		adj[U[i]].push_back(i);
		deg[U[i]]++;
	}

	int id = 0;
	for(int i = 1; i <= k; i++) for(int j = 1; j <= i; j++) ID[i][j] = id++;
	graph<short> G(id);

	for(int i = 1; i <= k; i++) for(int j = 1; j <= i; j++) for(int l = 1; l < j; l++) G.add_edge(ID[i][j], ID[i][l]);

	for(int i = 1; i <= n; i++){
		sort(all(adj[i]), [&](int p, int q){return W[p] < W[q];});
		
		for(int j = 1; j <= deg[i]; j++){
			there[V[adj[i][j - 1]]][ID[deg[i]][j]] += 1;
		}
	}

	for(int i = 1; i <= n; i++) for(int j = 0; j < id; j++) if(there[i][j]){
		if(there[i][j] > 1){
			G.weights[j] = 0;
		}
		for(int l = 0; l < j; l++) if(there[i][l]){
			E[j][l] = 1;
		}
	}

	for(int j = 0; j < id; j++) for(int l = 0; l < id; l++) if(E[j][l]) G.add_edge(j, l);
	pair<short, int> P = G.maximum_independent_set();
	if(P.first != k) P.second = 0;
	printf("%d\n", P.second);
}