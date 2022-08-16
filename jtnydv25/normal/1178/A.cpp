#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())


template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<",";
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

const int N = 1005;
int a[N], perm[N];
int main(){
	int n; sd(n);
	int sm = 0;
	for(int i = 1; i <= n; i++) sd(a[i]), sm += a[i];
	vector<int> vec;
	for(int i = 2; i <= n; i++) if(2 * a[i] <= a[1]) vec.push_back(i);
	sort(all(vec), [&](int i, int j){return a[i] > a[j];});
	int s = a[1];
	if(2 * s > sm){
		printf("%d\n%d\n", 1, 1);
		return 0;
	}
	for(int i = 0; i < sz(vec); i++){
		s += a[vec[i]];
		if(2 * s > sm){
			printf("%d\n", i + 2);
			printf("%d ", 1);
			for(int j = 0; j <= i; j++) printf("%d ", vec[j]);
			return 0;
		}
	}
	printf("%d\n", 0);
}