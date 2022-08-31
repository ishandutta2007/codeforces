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

vector<int> lift, stairs;
int n, m, q, cl, ce, v;

int lift_len(int x){
	return (x - 1) / v + 1;
}
int main(){
	sd(n); sd(m); sd(cl); sd(ce); sd(v);
	for(int i = 1; i <= cl; i++){
		int x;
		sd(x); stairs.push_back(x);
	}

	for(int i = 1; i <= ce; i++){
		int x;
		sd(x); lift.push_back(x);
	}
	sort(lift.begin(), lift.end());
	sort(stairs.begin(), stairs.end());

	sd(q);
	while(q--){
		int x1, y1, x2, y2;
		sd(y1); sd(x1); sd(y2); sd(x2);
		if(y1 == y2){
			printf("%d\n", abs(x2 - x1));
			continue;
		}

		if(x1 > x2) swap(x1, x2), swap(y1, y2);
		int y_dist = abs(y1 - y2);

		auto it = upper_bound(lift.begin(), lift.end(), x1 - 1) - lift.begin();
		if(it < lift.size() && lift[it] <= x2){
			printf("%d\n", x2 - x1 + lift_len(y_dist));
			continue;
		}

		int ans = 1e9; 
		it--;
		if(it >= 0){
			ans = min(ans, x2 - x1 + 2 * (x1 - lift[it]) + lift_len(y_dist));
		}

		it = upper_bound(lift.begin(), lift.end(), x2) - lift.begin();
		if(it < lift.size()) ans = min(ans, x2 - x1 + 2 * (lift[it] - x2) + lift_len(y_dist));

		it = upper_bound(stairs.begin(), stairs.end(), x1 - 1) - stairs.begin();

		if(it < stairs.size() && stairs[it] <= x2){
			ans = min(ans, x2 - x1 + (y_dist));
		}

		it--;

		if(it >= 0) ans = min(ans, x2 - x1 + 2 * (x1 - stairs[it]) + y_dist);

		it = upper_bound(stairs.begin(), stairs.end(), x2) - stairs.begin();
		if(it < stairs.size()) ans = min(ans, x2 - x1 + 2 * (stairs[it] - x2) + y_dist);

		printf("%d\n", ans);
	}
}