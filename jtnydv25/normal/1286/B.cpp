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
const int N = 2005;
int a[N], p[N], done[N], depth[N], c[N];
int main(){
	int n; sd(n);
	for(int i = 1; i <= n; i++){
		sd(p[i]);
		sd(a[i]);
	}

	for(int i = 1; i <= n; i++){
		int node = i;
		while(node != 0){
			depth[i]++;
			node = p[node];
		}
	}

	for(int i = 1; i <= n; i++){
		int node = -1;
		for(int j = 1; j <= n; j++) if(!done[j] && a[j] == 0){
			if(node == -1 || depth[node] > depth[j]) node = j;
		}
		if(node == -1){
			printf("NO\n");
			return 0;
		}
		c[node] = i;
		done[node] = 1;
		int curr = p[node];
		while(curr){
			if(!done[curr]) a[curr]--;
			curr = p[curr];
		}
	}
	for(int i = 1; i <= n; i++) if(a[i]){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for(int i = 1; i <= n; i++) printf("%d ", c[i]);
}