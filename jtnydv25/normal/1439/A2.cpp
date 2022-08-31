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
		vector<vector<int>> a(n, vector<int>(m));
		for(int i = 0; i < n; i++){
			cin >> s[i];
			for(int j = 0; j < m; j++) a[i][j] = s[i][j] - '0';
		}
		vector<vector<int>>ops;
		function<vector<int>(int, int, int, int, bool)> getOP = [&](int p, int q, int c, int d, bool go){
			vector<int> ret;
			for(int i = 0; i < 2; i++){
				for(int j = 0; j < 2; j++) if(p + i != c || q + j != d){
					ret.push_back(p + i + 1);
					ret.push_back(q + j + 1);
					if(go){
						a[p + i][q + j] ^= 1;
					}
				}
			}
			return ret;
		};
		
		function<void(int, int)> fix = [&](int i, int j){
			int sm = 0;
			for(int x = 0; x < 2; x++) for(int y = 0; y < 2; y++){
				sm ^= a[i + x][j + y];
			}
			for(int p = i; p < i + 2; p++) for(int q = j; q < j + 2; q++){
				if(a[p][q] ^ sm){
					ops.push_back(getOP(i, j, p, q, false));
				}
				a[p][q] = 0;
			}
		};
		for(int j = 0; j + 2 < m; j++){
			for(int i = 0; i + 2 < n; i++){
				if(a[i][j]){
					ops.push_back(getOP(i, j, i, j + 1, true));
				}
			}
			int u = a[n - 2][j], v = a[n - 1][j];
			if(u && v){
				ops.push_back(getOP(n - 2, j, n - 2, j, true));
				ops.push_back(getOP(n - 2, j, n - 1, j, true));
			} else if(u){
				ops.push_back(getOP(n - 2, j, n - 1, j, true));
			} else if(v){
				ops.push_back(getOP(n - 2, j, n - 2, j, true));
			}
		}
		// columns m - 2, m - 1 left
		for(int i = 0; i + 2 < n; i++){
			int u = a[i][m - 2], v = a[i][m - 1];
			if(u && v){
				ops.push_back(getOP(i, m - 2, i, m - 2, true));
				ops.push_back(getOP(i, m - 2, i, m - 1, true));
			} else if(u){
				ops.push_back(getOP(i, m - 2, i, m - 1, true));
			} else if(v){
				ops.push_back(getOP(i, m - 2, i, m - 2, true));
			}
		}

		fix(n - 2, m - 2);
		cout << ops.size() << endl;
		for(auto it : ops){
			for(auto it2 : it) cout << it2 << " ";
			cout << "\n";
		}
	}
}