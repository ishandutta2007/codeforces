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
		ll p, q;
		cin >> p >> q;
		// x | p
		// q !| x
		ll ans = 1;
		for(int d = 2; d * d <= q; d++) if(q % d == 0){
			int e = 0;
			while(q % d == 0){
				e++;
				q /= d;
			}
			int u = 0;
			ll z = p;
			while(z % d == 0){
				z /= d;
				u++;
			}
			for(int i = 0; i < min(e - 1, u); i++) z *= d;
			ans = max(ans, z);
		}
		if(q != 1){
			ll d = q;
			int e = 0;
			while(q % d == 0){
				e++;
				q /= d;
			}
			int u = 0;
			ll z = p;
			while(z % d == 0){
				z /= d;
				u++;
			}
			for(int i = 0; i < min(e - 1, u); i++) z *= d;
			ans = max(ans, z);
		}
		cout << ans << endl;
	}
}