#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

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

int x[N], p[N];

vector<int> V[N];

int getSqrt(ll x){
	int ret = sqrt(x);
	ret -= 2;
	while(ret * (ll) ret < x) ret++;
	assert(ret * (ll) ret == x);
	return ret;
}

int main(){
	for(int t = 1; 2 * t < N; t++){
		for(int a = 1; a * (ll) (2 * t + a) < N; a++){
			V[a * (ll) (2 * t + a)].push_back(t);
		}
	}
	int n; sd(n);
	for(int i = 2; i <= n; i += 2){
		sd(x[i]);
		if(V[x[i]].empty()){
			printf("No\n");
			return 0;
		}
	}
	p[1] = V[x[2]][0];
	p[2] = getSqrt(p[1] * (ll) p[1] + x[2]);



	for(int i = 3; i <= n; i += 2){
		bool found = 0;
		for(int j : V[x[i + 1]]){
			if(j > p[i - 1]){
				p[i] = j;
				found = 1;
				break;
			}
		}
		if(!found){
			printf("No\n");
			return 0;
		}
		p[i + 1] = getSqrt(p[i] * (ll) p[i] + x[i + 1]);	
	}
	printf("Yes\n");
	for(int i = 1; i <= n; i++){
		printf("%lld ", p[i] * (ll) p[i] - (p[i - 1] * (ll) p[i - 1]));
	}
}