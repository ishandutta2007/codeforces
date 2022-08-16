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
const int N = 300005;

int tot[N], minpref[N];
char s[N];
map<int, vector<int>> mp;
map<int, vector<int>> mp_sorted;
int main(){
	int n; sd(n);
	for(int i = 1; i <= n; i++){
		scanf("%s", s);
		int mn = 1e9, total = 0;
		for(int j = 0; s[j]; j++){
			if(s[j] == ')') total -= 1;
			else total ++;
			mn = min(mn, total);
		}
		tot[i] = total;
		minpref[i] = mn;
		mp[tot[i]].push_back(minpref[i]);
	}
	for(auto it : mp){
		vector<int> vec = it.S;
		sort(vec.begin(), vec.end());
		mp_sorted[it.F] = vec;
	}

	long long ans = 0;

	for(int i = 1; i <= n; i++){
		if(minpref[i] >= 0){
			// mn2 -> >= -tot[i]
			ans += mp_sorted[-tot[i]].end() - upper_bound(mp_sorted[-tot[i]].begin(), mp_sorted[-tot[i]].end(), -tot[i]-1);
		}
	}
	printf("%lld\n", ans);
}