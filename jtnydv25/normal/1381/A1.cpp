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

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string a, b; cin >> a >> b;
		vector<int> ans;
		for(int i = n - 1; i >= 0; i--){
			// cerr<<a << endl;
			if(a[i] != b[i]){
				if(i == 0){
					a[0] = a[0] == '0' ? '1' : '0';
					ans.push_back(1);
					break;
				}
				if(a[0] == b[i]){
					ans.push_back(1);
					a[0] = a[0] == '0' ? '1' : '0';
				}
				ans.push_back(i + 1);
				string c = a;
				for(int j = 0; j <= i; j++){
					a[j] = c[i - j] == '0' ? '1' : '0';
				}
			}
		}
		cout << ans.size() << " ";
		for(int v : ans) cout << v << " ";
		cout << "\n";
		assert(a==b);
	}
}