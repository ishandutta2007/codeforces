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
	while(t--){
		int n, m; cin >> n >> m;
		vector<string> s(n);
		for(int i = 0; i < n; i++) cin >> s[i];
		vector<vector<int>>ops;
		function<void(int, int)> flip = [&](int i, int j){
			int u = i, v = j;
			if(u == n - 1) u--;
			if(v == m - 1) v--;
			for(int x = 0; x < 2; x++){
				for(int y = 0; y < 2; y++) if(u + x != i || v + y != j){
					vector<int> vec;
					for(int x1 = 0; x1 < 2; x1++) for(int y1 = 0; y1 < 2; y1++) if(x != x1 || y != y1){
						int a = u + x1 + 1, b = v + y1 + 1;
						vec.push_back(a); vec.push_back(b);
					}
					ops.push_back(vec);
				}
			}
		};

		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(s[i][j] == '1') flip(i, j);
		cout << ops.size() << "\n";
		for(auto it : ops){
			for(auto it2 : it) cout << it2 << " ";
			cout << "\n";
		}
	}
}