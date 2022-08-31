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
	map<int, vector<int>> freq;
	int n; sd(n); vector<int> a(n), t(n);
	for(int i = 0; i < n; i++){
		sd(a[i]);
	}
	for(int i = 0; i < n; i++){
		sd(t[i]);
		freq[a[i]].push_back(t[i]);
	}
	int MAX = 2e9;
	auto it = freq.begin();
	multiset<int> curr;
	ll sm = 0;
	ll ans = 0;
	while(it != freq.end()){
		auto nxt = it;
		nxt++;
		int pos = it->F;
		int nxt_pos = nxt == freq.end() ? MAX : nxt->F;
		for(auto z : (it->S)) curr.insert(-z), sm += z;
		sm += *curr.begin();
		curr.erase(curr.begin());
		int curr_pos = pos+1;
		while(!curr.empty()){
			if(curr_pos == nxt_pos){
				ans += sm * (nxt_pos - pos);
				break;
			} else{
				auto it = curr.begin();
				int z = *it;
				ans -= z * (ll) (curr_pos - pos);
				sm += z;
				curr.erase(it);
				curr_pos++;
			}
		}
		it++;
	}
	printf("%lld\n", ans);
}