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
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		int n; ll w;
		cin >> n >> w;
		vector<int> a(n);
		vector<int> indices;
		ll w2 = (w + 1) / 2;
		bool found = false;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			if(found) continue;
			if(a[i] >= w2 && a[i] <= w){
				cout << 1 << "\n" << (i + 1) << "\n";
				found = true;
			}
			else if(a[i] < w2){
				indices.push_back(i);
			}
		}
		if(found) continue;
		ll s = 0;
		vector<int> ans;
		for(auto it : indices){
			if(s >= w2) break;
			s += a[it];
			ans.push_back(it + 1);
		}
		if(s < w2){
			cout << "-1\n";
			continue;
		}
		cout << ans.size() << endl;
		for(auto it : ans) cout << it << " "; cout << endl;
	}
}