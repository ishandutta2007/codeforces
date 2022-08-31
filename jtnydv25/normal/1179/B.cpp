#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())


#ifdef LOCAL
#define cerr cout
#else
#endif

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

vector<pii> ans;

void go(int i, int j, int m){
	if(i > j) return;
	if(i == j){
		int curr = m - 1;
		for(int i = 1; i < 	m; i++){
			ans.push_back({0, curr});
			if(i & 1){
				curr--;
				curr *= -1;
			} else{
				curr *= -1;
				curr--;
			}
		}
		return;
	}
	int delta = j - i;
	for(int i = 1; i <= m; i++){
		ans.push_back({delta, m - 2 * i + 1});
		if(i != m){
			ans.push_back({-delta, -m + 2 * i});
		}
	}
	if(delta > 1) ans.push_back({-delta + 1, 0});
	go(i + 1, j - 1, m);
}

int main(){
	int n, m;
	sd(n); sd(m);
	bool swapped = false;
	if(n > m){
		swap(n, m);
		swapped = true;
	}
	go(1, n, m);
	int x = 1, y = 1;
	printf("%d %d\n", 1, 1);

	for(auto it : ans){
		int dx = it.F, dy = it.S;
		if(swapped) swap(dx, dy);
		x += dx; y += dy;
		printf("%d %d\n", x, y);
	}
}