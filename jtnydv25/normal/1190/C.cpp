#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

#ifdef LOCAL
#define cerr cout
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

const int N = 100005;
int a[N];
char s[N];
int prefix[N];

set<int> pos[2];

int diff(set<int> & st){
	if(st.empty()) return 0;
	return *st.rbegin() - *st.begin();
}

bool win(int k){
	// assert(!pos[0].empty() && !pos[1].empty());
	return min(diff(pos[0]), diff(pos[1])) <= k - 1;
}

bool win(int i, int x, int k){
	pos[x].insert(i); pos[x].insert(i + k - 1);
	// assert(!pos[0].empty() && !pos[1].empty());
	bool ret = min(diff(pos[0]), diff(pos[1])) <= k - 1;
	pos[x].erase(i); pos[x].erase(i + k - 1);
	return ret;
}

void solve(){
	int n, k; sd(n); sd(k);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++){
		a[i] = s[i] - '0';
		pos[a[i]].insert(i);
	}

	if(pos[0].empty() || pos[1].empty() || win(k) ){
		printf("tokitsukaze\n");
		return;
	}

	bool can_draw = false;

	for(int i = 1; i <= k; i++){
		pos[a[i]].erase(i);
	}
	if(!win(1, 0, k) || !win(1, 1, k)) can_draw = true;

	for(int i = 2; i + k - 1 <= n; i++){
		pos[a[i - 1]].insert(i - 1);
		pos[a[i + k - 1]].erase(i + k - 1);
		if(!win(i, 0, k) || !win(i, 1, k)) can_draw = true;
	}
	printf(can_draw ? "once again\n" : "quailty\n");
}

int main(){
	int t = 1;
	// sd(t);
	for(int tt = 1; tt <= t; tt++){
		// printf("Case #%d: ", tt);
		solve();
	}
}