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
const int N = 200005;
int b[N];
int perm[N];

int getUniqueVals(multiset<int> & ms){
	auto it = ms.begin();
	int ans = 0;
	while(it != ms.end()){
		ans++;
		int now = *it;
		it = ms.upper_bound(now);
	}
	return ans;
}

int main(){
	int n; sd(n);
	for(int i = 1; i <= n; i++) sd(b[i]), perm[i] = i;
	sort(perm +1, perm + n + 1, [](int i, int j){return b[i] < b[j];});
	multiset<int> ms;
	for(int i = 2; i <= n; i++) ms.insert(b[perm[i]] - b[perm[i - 1]]);
	// for(auto it : ms) trace(it);
	int sz = getUniqueVals(ms);
	// trace(sz);
	if(sz == 1){
		printf("%d\n", perm[1]);
		return 0;
	}
	if(sz > 3){
		printf("-1\n");
		return 0;
	}

	ms.erase(ms.find(b[perm[2]] - b[perm[1]]));
	if(getUniqueVals(ms) == 1){
		printf("%d\n", perm[1]);
		return 0;
	}
	ms.insert(b[perm[2]] - b[perm[1]]);

	ms.erase(ms.find(b[perm[n]] - b[perm[n - 1]]));

	if(getUniqueVals(ms) == 1){
		printf("%d\n", perm[n]);
		return 0;
	}

	ms.insert(b[perm[n]] - b[perm[n - 1]]);
	multiset<int> cp = ms;
	for(int i = 2; i < n; i++){
		ms.erase(ms.find(b[perm[i]] - b[perm[i - 1]]));
		ms.erase(ms.find(b[perm[i + 1]] - b[perm[i]]));
		ms.insert(b[perm[i + 1]] - b[perm[i - 1]]);

		if(getUniqueVals(ms) == 1){
			printf("%d\n", perm[i]);
			return 0;
		}
		ms.erase(ms.find(b[perm[i + 1]] - b[perm[i - 1]]));
		ms.insert(b[perm[i]] - b[perm[i - 1]]);
		ms.insert(b[perm[i + 1]] - b[perm[i]]);
	}
	printf("-1\n");
}