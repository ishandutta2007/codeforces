#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl '\n' // remove in interactive
#endif

/*
	O(MAX + # of operations)
	supports [], clear, iteration
*/
template<class T>
struct ArrayMap{
	int version;
	bool iterable;
	vector<T> arr;
	vector<int> lastUpdated;
	vector<int> keys; // to iterate
	
	ArrayMap(){}
	ArrayMap(int n, bool b = false) : version(0), iterable(b), arr(n, -1), lastUpdated(n, -1){}

	void clear(){
		++version;
		if(iterable)
			keys.clear();
	}

	T & operator [] (int pos){ // equivalent to map operator []
		if(lastUpdated[pos] == version){
			return arr[pos];
		}
		lastUpdated[pos] = version;
		if(iterable) keys.push_back(pos);
		arr[pos] = -1;
		return arr[pos];
	}

	bool exists(int pos){
		return lastUpdated[pos] == version;
	}

	void erase(int pos){
		lastUpdated[pos] = version - 1;
	}
};

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n), b(n), f(n);
		int mx = 0;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			a[i]--;
			f[a[i]]++;
		}

		for(int i = 0; i < n; i++){
			cin >> b[i];
			b[i]--;
		}
		int r = max_element(all(f)) - f.begin();
		vector<vector<int>> adj(n);
		vector<int> deg(n);
		for(int i = 0; i < n; i++){
			if(a[i] != r){
				deg[b[i]]++;
				adj[a[i]].push_back(b[i]);
			}
		}

		set<pii> st;
		for(int i = 0; i < n; i++) st.insert({deg[i], i});

		bool ok = true;

		while(!st.empty()){
			auto it = st.begin();
			int u = it->second;
			st.erase(it);
			if(deg[u] != 0){
				ok = false;
				break;
			}
			for(int v: adj[u]){
				st.erase({deg[v], v});
				deg[v]--;
				st.insert({deg[v], v});
			}
		}
		cout << (ok ? "AC" : "WA") << endl;
	}
}