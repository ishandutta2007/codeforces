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
		int n; cin >> n;
		vector<int> neg, pos, zeroes;
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			if(x == 0) zeroes.push_back(x);
			else if (x < 0) neg.push_back(x);
			else pos.push_back(x);
		}
		int sn = -accumulate(all(neg), 0);
		int sp = accumulate(all(pos), 0);
		if(sn == sp){
			cout << "NO\n";
			continue;
		}
		if(sn < sp) {
			vector<int> temp = pos;
			pos = neg;
			neg = temp;
		}
		cout << "YES\n";
		for(auto it : neg) cout << it << " ";
		for(auto it : pos) cout << it << " ";
		for(auto it : zeroes) cout << it << " ";
		cout << endl;
	}
}