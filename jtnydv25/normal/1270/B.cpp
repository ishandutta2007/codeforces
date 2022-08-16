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
const int N = 200005;
int a[N];
int main(){
	int t; sd(t);
	while(t--){
		int n; sd(n);
		for(int i = 1; i <= n; i++) sd(a[i]);
		int mx = INT_MIN;
		int pos = n + 1;
		int L = -1, R = -1;
		for(int i = n; i >= 1; i--){
			if(a[i] - i > mx){
				mx = a[i] - i;
				pos = i;
			}
			if(mx - (a[i] - i) - 1 >= 0){
				L = i, R = pos;
			}
		}
		// trace(L, R);
		pos = 0, mx = INT_MIN;
		
		for(int i = 1; i <= n; i++){
			if(a[i] + i > mx){
				mx = a[i] + i;
				pos = i;
			}
			if(mx - (a[i] + i) - 1 >= 0){
				// trace(mx, i);
				L = pos, R = i;
			}
		}
		if(L == -1){
			printf("NO\n");
		} else{
			printf("YES\n%d %d\n", L, R);
		}
	}
}