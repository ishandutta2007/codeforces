#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &(x))
#define LSOne(S) (S & (-S))
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
ll B1[N + 10], B2[N + 10], pref[N + 10];
ll get(int i, int j){
	return pref[j] - pref[i - 1];
}
ll query(ll* ft, int b) {
    ll sum = 0;
    for (; b; b -= LSOne(b)) sum += ft[b];
    return sum;
}

ll query(int b) {
    return query(B1, b) * b - query(B2, b);
}

ll range_query(int i, int j)    {
    return query(j) - query(i - 1);
}

void update(ll* ft, int k, ll v) {
    for (; k <= N; k += LSOne(k)) ft[k] += v;
}

void range_update(int i, int j, ll v)   {
    update(B1, i, v);
    update(B1, j + 1, -v);
    update(B2, i, v * (i - 1));
    update(B2, j + 1, -v * j);
}
int V[N], T[N];
ll arr[N];
int main(){
	int n;
	sd(n);
	for(int i = 1; i <= n; i++) sd(V[i]);
	for(int i = 1; i <= n; i++) sd(T[i]), pref[i] = pref[i - 1] + T[i];

	for(int i = 1; i <= n; i++){
		int lo = i - 1, hi = n;
		while(lo < hi){
			int mid = (lo + hi + 1) >> 1;
			if(get(i, mid) <= V[i]) lo = mid;
			else hi = mid - 1;
		}
		if(i <= lo) range_update(i, lo, 1);
		if(lo != n){
			arr[lo + 1] += V[i] - get(i, lo);
		}
	}
	for(int i = 1; i <= n; i++) printf("%lld ", T[i] * 1ll * range_query(i, i) + arr[i]);
}