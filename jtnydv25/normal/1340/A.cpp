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
const int N = 100005;
int p[N], ip[N];

int main(){
	int t; sd(t);
	while(t--){
		int n; sd(n); set<int> st;
		multiset<int> vals;
		for(int i = 1; i <= n; i++) sd(p[i]), ip[p[i]] = i, st.insert(i), vals.insert(1);
		bool error = false;
		for(int i = 1; i <= n; i++){
			int pos = ip[i];
			auto it = st.lower_bound(pos);
			int curr = pos;
			if(it != st.begin()){
				auto it2 = it;
				it2--;
				curr = pos - (*it2);
			}
			// trace(curr, *vals.rbegin(), pos);
			if(curr != *vals.rbegin()){
				error = true;
				break;
			}
			it++;
			if(it != st.end()){
				vals.insert(*it - pos + curr);
			}
			vals.erase(vals.find(curr));
			st.erase(pos);
		}
		printf(error ? "No\n" : "Yes\n");
	}
}