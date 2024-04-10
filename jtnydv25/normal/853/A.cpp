#include <bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d", &(x))
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, iknt>
#define F first
#define S second

const int N = 1e6 + 10;

int A[N], perm[N];
bool cmp(int i, int j){
	return A[i] > A[j];
}
set<int> ms;
int ans[N];
int main(){
	ll cost = 0;
	int t, n, k;
	sd(n); sd(k);
	for(int i = 1; i <= n; i++)
		sd(A[i]);
	for(int i = 1; i <= n; i++){
		ms.insert(k + i);
		perm[i] = i;
	}
	sort(perm + 1, perm + n + 1, cmp);
	for(int i = 1; i <= n; i++){
		int ind = perm[i];
		auto it = ms.lower_bound(ind);
		ans[ind] = *it;
		cost += ((*it) - ind) * 1ll * A[ind];
		ms.erase(it);
	}
	printf("%lld\n", cost);
	for(int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
}