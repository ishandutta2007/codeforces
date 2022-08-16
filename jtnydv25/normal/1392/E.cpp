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
ll a[50][50];
int main(){
	int n; sd(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ll V = 1LL << (2 * n - (i + j));
			printf("%lld ", a[i][j] = (i & 1 ? V : 0));
		}
		printf("\n");
		fflush(stdout);
	}
	fflush(stdout);
	int q; scanf("%d", &q);
	while(q--){
		ll sm; scanf("%lld", &sm);
		int i = 0, j = 0;
		printf("%d %d\n", i + 1, j + 1);
		sm -= a[i][j];
		for(int r = 0; r < 2 * (n - 1); r++){
			if(i == n - 1){
				j++;
			} else if(j == n - 1){
				i++;
			} else{
				ll rgt = a[i][j + 1], dwn = a[i + 1][j];
				if(rgt != 0){
					if(sm >= rgt){
						j++;
						sm -= rgt;
					} else{
						i++;
					}
				} else{
					if(sm >= dwn){
						i++;
						sm -= dwn;
					} else{
						j++;
					}
				}
			}
			printf("%d %d\n", i + 1, j + 1);
			fflush(stdout);
		}
	}
}