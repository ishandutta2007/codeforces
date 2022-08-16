#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

#define intRACE

#ifdef intRACE
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

const int N = 200015;
int mn[N], mx[N];
const int INF = 1e9;

int a[N];
vector<pair<int, int>> rem;
int olda[N];
set<int> ms;
int main(){
	int n, q; sd(n); sd(q);
	for(int i = 1; i <= q; i++){
		mn[i] = N - 1; mx[i] = 0;
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		sd(a[i]), mn[a[i]] = min(mn[a[i]], i), mx[a[i]] = max(mx[a[i]], i);
		olda[i] = a[i];
		if(!a[i]) cnt++;
	}
	for(int i = 1; i <= n; i++){
		if(a[i] && i == mn[a[i]]){
			ms.insert(a[i]);
		}
		int v = ms.empty() ? 0 : *ms.rbegin();
		if(a[i] && a[i] != v){
			printf("NO\n");
			return 0;
		}
		if(a[i] && i == mx[a[i]]){
			ms.erase(a[i]);
		}
		a[i] = v;
	}

	if(mn[q] > mx[q]){
		if(!cnt){
			printf("NO\n");
			return 0;
		}
		for(int i = 1; i <= n; i++) if(!olda[i]){
			mn[q] = mx[q] = i;
			a[i] = q;
			break;
		}
	}

	for(int i = q; i >= 1; i--){
		if(mn[i] <= mx[i]){
			for(int k = mn[i] - 1; k >= 0; k--){
				if(k >= 1 && !a[k]){
					a[k] = i;
				}
				else{
					mn[i] = k + 1;
					break;
				}
			}
			for(int k = mx[i] + 1; k <= n + 1; k++){
				if(k <= n && !a[k]){
					a[k] = i;
				} else{
					mx[i] = k - 1;
					break;
				}
			}
		}
	}

	for(int i = 1; i <= q; i++) if(mn[i] > mx[i]){
		mn[i] = mn[q]; mx[i] = mx[q];
	}
	printf("YES\n");
	for(int i = 1; i <= n; i++) printf("%d ", a[i]); printf("\n");
}