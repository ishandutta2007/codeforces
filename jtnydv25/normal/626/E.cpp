#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))

const int N = 200005;
int A[N], perm[N];
ll pref[N];
bool cmp(int i, int j){
	return A[i] < A[j];
}

int n;
pair<int, int> vec, v;
inline double get(int i, int k){
	return (pref[n] - pref[n - k] + pref[i - 1] - pref[i - k - 1] - 2ll * A[perm[i]] * 1ll * k) / (double)(1 + 2 * k);
}

int main(){
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(A[i]);
		perm[i] = i;
	}
	if(n <= 2){
		printf("%d\n%d", 1, A[1]);
		return 0;
	}
	sort(perm + 1, perm + n + 1, cmp);
	for(int i = 1; i <= n; i++){
		pref[i] = pref[i - 1] + A[perm[i]];
	}

	double ans = 0;
	vec = {1, 0};
	for(int i = 1; i <= n; i++){
		int lo = 0, hi = min(i - 1, n - i);
		while(lo < hi){
			int k = (lo + hi) >> 1;
			double val = get(i, k);
			double val2 = get(i, k + 1);
			if(val < val2){
				lo = k + 1;
			}
			else{
				hi = k;
			}
		}
		if(get(i, lo) > ans){
			ans = get(i, lo);
			vec = {i, lo};
		}
	}

	printf("%d\n", 1 + 2 * vec.second);
	printf("%d ", A[perm[vec.first]]);
	for(int k = 1; k <= vec.second; k++){
		printf("%d %d ", A[perm[n - k + 1]], A[perm[vec.first - k]]);
	}
}