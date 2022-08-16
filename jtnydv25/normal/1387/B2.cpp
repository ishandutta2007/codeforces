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

template<class T>
ostream& operator <<(ostream& os,const set<T>& v){
	os<<"{";
	auto it = v.begin();
	while(it != v.end()){
		if(it!=v.begin())os << ", ";
		os << *it;
		it++;
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

struct Tree{
	vector<vector<int>> adj;
	vector<int> A, B, C, D; // weighted edges
    vector<int> pos, tour, depth, pos_end; // for O(1) lca after O(n logn) precomputation
	vector<vector<int>> table;

	int n, m;
	Tree(int n) : n(n), A(n - 1), B(n - 1), C(n - 1), adj(n), m(0){};

	void add_edge(int u, int v, int w = 1){
		adj[u].push_back(m);
		adj[v].push_back(m);
		A[m] = u; B[m] = v; C[m++] = w;
	}

    void go(){
        vector<int> sizes(n);
		set<int> nodes;
		int orig = 1;
		ll ans = 0;
		int root = -1;
        function<int(int, int)> getSizes = [&](int s, int p){
			nodes.insert(s);
            sizes[s] = 1;
			bool ok = 1;
            for(int ind : adj[s]){
                int v = s ^ A[ind] ^ B[ind];
                if(v != p){
					sizes[s] += getSizes(v, s);
					if(2 * sizes[v] > n) ok = 0;
				}
            }
			if(orig){
				ans += 2 * min(sizes[s], n - sizes[s]);
				if(ok && 2 * sizes[s] >= n){
					// assert(root == -1);
					root = s;
				}
			}
            return sizes[s];
        };
		getSizes(0, -1);
		vector<int> perm(n);
		vector<set<int>> P = {{root}};
		
		for(int ind : adj[root]){
			int v = A[ind] ^ B[ind] ^ root;
			orig = 0;
			nodes.clear();
			getSizes(v, root);
			P.push_back(nodes);
		}

		set<pii> st;
		for(int i = 0; i < sz(P); i++) st.insert({-sz(P[i]), i});
		for(int rem = n; rem > 0; rem -= 2){
			vector<int> V;
			if(rem == 3){
				for(auto it : P) copy(all(it), back_inserter(V));
				for(int i = 0; i < 3; i++) perm[V[i]] = V[(i + 1) % 3];
				break;
			}
			auto it = st.begin();
			int a = it->second;
			it++;
			int b = it->second;
			st.erase({-sz(P[a]), a});
			st.erase({-sz(P[b]), b});

			auto it2 = P[a].begin();
			int A = *it2;
			P[a].erase(it2);

			auto it3 = P[b].begin();
			int B = *it3;
			P[b].erase(it3);

			perm[A] = B;
			perm[B] = A;
			if(!P[a].empty()){
				st.insert({-sz(P[a]), a});
			}
			if(!P[b].empty()){
				st.insert({-sz(P[b]), b});
			}
		}
		printf("%lld\n", ans);
		for(int i = 0; i < n; i++) printf("%d ", perm[i] + 1);
    }
};

int main(){
	int n; sd(n);
	Tree T(n);
	for(int i = 1; i < n; i++){
		int u, v; sd(u); sd(v);
		T.add_edge(u - 1, v - 1);
	}
	T.go();	
}