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

vector<pii> X, Y;

int num_intersections(pii it1, pii it2){
	return (it1.F == it2.F) + (it1.F == it2.S) + (it1.S == it2.F) + (it1.S == it2.S);
}

void print(pii x){cerr << x.F <<" " << x.S << endl;}

map<pii, set<int>> mpX, mpY;
int get_common(auto it1, auto it2){
	return (it1.F == it2.F || it1.F == it2.S) ? it1.F : it1.S;
}
set<int> commons;
int main(){
	int n, m;
	sd(n); sd(m);
	for(int i = 1; i <= n; i++){
		int x, y;
		sd(x); sd(y); assert(x != y);
		if(x > y) swap(x, y);
		X.push_back({x, y});
	}

	for(int i = 1; i <= m; i++){
		int x, y;
		sd(x); sd(y); assert(x != y);
		if(x > y) swap(x, y);
		Y.push_back({x, y});
	}	

	vector<pair<pii, pii>> possible;

	for(auto it1 : X)
		for(auto it2 : Y)
			if((it1 != it2) && ((it1.F == it2.F) || (it1.F == it2.S) || (it1.S == it2.F) || (it1.S == it2.S))){
				possible.push_back({it1, it2});
				commons.insert(get_common(it1, it2));
			}

	assert(!possible.empty());

	if(commons.size() == 1){
		printf("%d\n", *commons.begin());
		return 0;
	}

	for(auto it : possible){
		auto it1 = it.F, it2 = it.S;
		int common = get_common(it1, it2);
		mpX[it1].insert(common);
		mpY[it2].insert(common);
	}

	for(auto it : mpX){
		if((int)it.S.size() > 1){
			printf("-1\n"); return 0;
		}
	}

	for(auto it : mpY){
		if(it.S.size() > 1){
			printf("-1\n"); return 0;
		}
	}
	printf("0\n");
}