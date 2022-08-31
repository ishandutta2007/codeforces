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
	int t; sd(t);
	while(t--){
		int n; sd(n);
		vector<int> a(n);
		for(int i = 0; i < n; i++) sd(a[i]);
		for(int i = 2; i < n; i += 2){
			bool found = false;
			for(int msk = 0; msk < 4; msk++){
				int x = a[i - 1], y = a[i];
				if(msk & 1) x *= -1;
				if(msk >> 1 & 1) y *= -1;
				int p = (y >= x) + (x >= a[i - 2]);
				int q = (y <= x) + (x <= a[i - 2]);
				if(p && q){
					found = true;
					a[i - 1] = x;
					a[i] = y;
					break;
				}
			}
			assert(found);
		}
		for(int i = 0; i < n; i++) printf("%d ", a[i]);
		printf("\n");
	}
}