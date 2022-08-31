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

template<class T,class U>
ostream& operator<<(ostream& os,const map<T, U> & mp){
	os << "{";
	int i = 0;
	for(auto it : mp){
		if(i) os<<", ";
		os << it;
		i++;
	}
	os << "}";	
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

const int N = 300005;
int mn[N], mx[N], a[N];
int main(){
	int q; sd(q);
	while(q--){
		int n; sd(n);
		for(int i = 1; i <= n; i++){
			mx[i] = 0;
			mn[i] = 1e9;
		}
		for(int i = 1; i <= n; i++){
			sd(a[i]);
			mx[a[i]] = i;
		}
		for(int i = n; i>=1; i--) mn[a[i]] = i;
		int lst = -1;
		vector<int> vec;
		for(int i = 1; i <= n; i++) if(mx[i]){
			if(lst == -1) lst = i;
			else{
				if(mn[i] > mx[lst]) vec.push_back(1);
				else vec.push_back(0);
				lst = i;
			}
		}
		int i = 0;
		int mx = 0;
		while(i < sz(vec)){
			while(i < sz(vec) && vec[i] == 0) i++;
			int j = i;
			while(j < sz(vec) && vec[j] == 1) j++;
			mx = max(mx, j - i);
			i = j;
		}
		printf("%d\n", sz(vec) - mx);
	}
}