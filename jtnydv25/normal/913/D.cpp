#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
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

const int N = 2e5 + 10;
int a[N], t[N];
vector<int> vec;
int n, T;
int perm[N];

bool cmp(int i, int j){
	return t[i] < t[j];
}

bool chk(int k){
	vec.clear();
	ll sm = 0;
	for(int i = 1; i <= n; i++)
		if(a[perm[i]] >= k){
			vec.push_back(t[perm[i]]);
			if(vec.size() <= k) sm += t[perm[i]];
		}
	if(vec.size() >= k && sm <= T)
	{
		return 1;
	}
	return 0;
}

int main(){
	sd(n); sd(T);
	for(int i = 1; i <= n; i++) sd(a[i]), sd(t[i]), perm[i] = i;
	sort(perm + 1, perm + n + 1, cmp);
	int lo = 0, hi = n;
	while(lo < hi){
		int mid = (lo + hi + 1) >> 1;
		if(chk(mid)) lo = mid;
		else hi = mid - 1;
	}
	printf("%d\n", lo);
	printf("%d\n", lo);
	chk(lo);
	int cnt = 0;
	for(int i = 1; i <= n; i++) if(a[perm[i]] >= lo && cnt < lo) {
		printf("%d ", perm[i]);
		cnt++;
	}
}