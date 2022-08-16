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

set<pair<int, int> > pairs;
const int N = 2005;
bool done[2 * N];
int partner[N];
int p[2 * N];

int n, m;
void put(int x){
	if(x <= 0) return;
	done[x] = 1;
	partner[partner[x]] = 0;
	partner[x] = 0;
	printf("%d\n", x);
	fflush(stdout);
}

void choose(){
	if(!pairs.empty()){
		int mx = 0;
		pair<int, int> P;
		for(auto it : pairs) if(p[it.S] - p[it.F] >= mx) mx = p[it.S] - p[it.F], P = it;
		put(P.S);
		pairs.erase(P);
		return;
	}
	int mx = -1, pos = 0;
	for(int i = 1; i <= 2* n; i++) if(!done[i] && p[i] > mx) mx = p[i], pos = i;
	put(pos);
}

void absorb(){
	int a;
	scanf("%d", &a);
	// trace(a, partner[a]);
	done[a] = 1;
	if(partner[a]){
		int b = partner[a];
		int to_print = b;
		if(p[a] > p[b] || (a > b && p[a] == p[b])) swap(a, b);
		pairs.erase({a, b});
		put(to_print);
		partner[partner[a]] = 0;
		partner[a] = 0;
	} else{
		choose();
	}
}


int main(){	
	sd(n); sd(m);
	for(int i = 1; i <= 2 * n; i++){
		sd(p[i]);
	}
	for(int i = 1; i <= m; i++){
		int a, b; sd(a); sd(b);
		if(p[a] > p[b] || (a > b && p[a] == p[b])) swap(a, b);
		partner[a] = b;
		partner[b] = a;
		pairs.insert({a, b});
		// trace(a, b);
	}

	int t; sd(t);
	if(t == 1){
		choose();
		for(int i = 1; i < n; i++) absorb();
		int a; scanf("%d", &a);
	} else{
		for(int i = 1; i <= n; i++) absorb();
	}
}