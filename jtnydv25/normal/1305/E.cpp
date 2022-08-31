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

const int N = 5005;
int num[3 * N];
const int MAX = 1000000000;
int a[N];
const int K = 80000;
void complete(int i, int n){
	for(int j = i; j <= n; j++) a[j] = MAX - K * (n - j);
}


int main(){
	int n, m; sd(n); sd(m);
	for(int i = 1; i <= n; i++){
		a[i] = i;
		for(int j = i; j <= 2 * n; j++) if(num[j] == m){
			a[i] = j;
			complete(i + 1, n);
			for(int i = 1; i <= n; i++) printf("%d ", a[i]);
			printf("\n");
			return 0;
		}
		m -= num[a[i]];
		for(int j = 1; j < i; j++) num[a[i] + a[j]]++;
	}
	printf("-1\n");
}