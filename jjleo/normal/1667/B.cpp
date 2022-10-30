#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

typedef long long ll;

int t, n;
int A[maxn];
ll a[maxn];
vector<ll> v;

int b[maxn];
int mx[maxn];

inline void add(int x, int y){
	for(;x <= v.size();x += x & -x) b[x] = max(b[x], y);
}

inline int query(int x){
	int sum = -1e9;
	for(;x;x -= x & -x) sum = max(sum, b[x]);
	return sum;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		a[0] = 0;
		for(int i = 1;i <= n;i++) scanf("%lld", &a[i]), A[i] = a[i], a[i] += a[i - 1];
		v.clear();
		for(int i = 0;i <= n;i++) v.push_back(a[i]);
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for(int i = 1;i <= v.size();i++) b[i] = -1e9;
		for(int i = 0;i <= n;i++) a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
		for(int i = 1;i <= v.size();i++) mx[i] = -1e9;
		add(a[0], 0);
		mx[a[0]] = 0;
		int last = 0;
		for(int i = 1;i <= n;i++){
			last += A[i] > 0 ? 1 : A[i] < 0 ? -1 : 0;
			last = max(last, query(a[i] - 1) + i);
			last = max(last, mx[a[i]]);
			mx[a[i]] = last;
			add(a[i], last - i);
		}
		printf("%d\n", last);
	}
}