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

int query(vector<int> & s){
	printf("? %d ", sz(s));
	for(auto it : s) printf("%d ", it);
	printf("\n");
	fflush(stdout);
	int x; sd(x);
	return x;
}

char correct[1000];

int main(){
	int t; sd(t);
	while(t--){
		int n, k; sd(n); sd(k);
		vector<vector<int>> s(k + 1);
		for(int i = 1; i <= k; i++){
			int l; sd(l);
			s[i].resize(l);
			for(int & v : s[i]) sd(v);
		}
		vector<int> v(n); iota(all(v), 1);
		int mx = query(v);
		int lo = 1, hi = n;
		while(lo < hi){
			int mid = (lo + hi) >> 1;
			vector<int> V(mid); 
			iota(all(V), 1);
			if(query(V) == mx) hi = mid;
			else lo = mid + 1;
		}
		vector<int> answers(k + 1);
		for(int i = 1; i <= k; i++){
			if(find(all(s[i]), lo) == s[i].end()){
				answers[i] = mx;
				// printf("%d ", mx);
			} else{
				vector<int> V;
				vector<int> isThere(n + 1);
				for(int x : s[i]) isThere[x] = 1;
				for(int i = 1; i <= n; i++) if(!isThere[i]) V.push_back(i);
				answers[i] = query(V);
				// printf("%d ", query(V));
			}
		}
		printf("! ");
		for(int i = 1; i <= k; i++) printf("%d ", answers[i]);
		printf("\n");
		fflush(stdout);
		scanf("%s", correct);
	}
}