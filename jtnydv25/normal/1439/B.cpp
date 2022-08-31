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

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	srand(time(NULL));
	while(t--){
		int n, m, k;
		cin >> n >> m >> k;
		set<pair<int, int>> nodes;
		vector<vector<int>> adj(n);
		vector<int> deg(n);
		vector<int> removed(n);
		
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v; u--; v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
			deg[u]++;
			deg[v]++;
		}
		for(int i = 0; i < n; i++) sort(all(adj[i]));

		for(int i = 0; i < n; i++){
			nodes.insert({deg[i], i});
		}

		bool done = false;
		while(!nodes.empty()){
			auto it = nodes.begin();
			int u = it->second;
			int d = it->first;
			
			nodes.erase(it);
			removed[u] = 1;
			vector<int> vec;
			for(int v : adj[u]) if(!removed[v]) vec.push_back(v);
			random_shuffle(all(vec));
			if(d + 1 < k){
				for(int v : vec){
					nodes.erase({deg[v], v});
					deg[v]--;
					nodes.insert({deg[v], v});
				}
			} else if(d + 1 == k){
				bool clique = true;
				for(int i = 0; i < sz(vec) && clique; i++){
					for(int j = 0; j < i; j++){
						int p = vec[i], q = vec[j];
						auto it2 = upper_bound(all(adj[p]), q - 1);
						if(it2 == adj[p].end() || *it2 != q){
							clique = false;
							break;
						}
					}
				}
				if(clique){
					cout << 2 << "\n";
					cout << u + 1 << " ";
					for(int v : vec) cout << v + 1 << " ";
					cout << "\n";
					done = true;
					break;
				} else{
					for(int v : vec){
						nodes.erase({deg[v], v});
						deg[v]--;
						nodes.insert({deg[v], v});
					}
				}
			} else{
				cout << "1 " << n + 1 - accumulate(all(removed), 0) << "\n";
				cout << u + 1 << " ";
				for(int i = 0; i < n; i++) if(!removed[i]) cout << i + 1 << " ";
				cout << "\n";
				done = true;
				break;
			}
		}
		if(!done) cout << "-1\n";
	}
}