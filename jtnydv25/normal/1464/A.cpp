#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

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
	for(auto it = v.begin(); it != v.end(); it++){
		if(it != v.begin())os<<", ";
		os<<*it;
	}
	os<<"}";
	return os;
}

template<class T, class V>
ostream& operator <<(ostream& os,const map<T, V>& v){
	os<<"{";
	for(auto it = v.begin(); it != v.end(); it++){
		if(it != v.begin())os<<", ";
		os<<*it;
	}
	os<<"}";
	return os;
}

#ifdef LOCAL
#define cerr cout
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
		vector<int> mp1(n + 1), mp2(n + 1);
		int ans = 0;
		for(int i = 0; i < m; i++){
			int x, y; cin >> x >> y;
			if(x != y){
				ans++;
				mp1[x] = y;
				mp2[y] = x;
			}
		}
		// trace(ans);
		vector<int> vis(n + 1);
		for(int i = 1; i <= n; i++) if(mp1[i] && !vis[i]){
			int curr = i;
			while(true){
				vis[curr] = 1;
				curr = mp1[curr];
				if(curr == i){
					ans++; break;
				}
				if(vis[curr]) break;
			}
		}
		cout << ans << endl;
	}
}