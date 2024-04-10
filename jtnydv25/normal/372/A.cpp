#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))

const int N = 5e5 + 5;
multiset<int> ms;
int a[N];

int main(){
	int n;
	sd(n);
	for(int i = 1;i <= n; i++) sd(a[i]), ms.insert(a[i]);
	sort(a + 1, a + n + 1);
	int lo  = 0, hi = n >> 1;
	while(lo < hi){
		int k = (lo + hi + 1) >> 1;
		int r = k + 1;
		int l = 1;
		for(; l <= k && r <= n; l++){
			while(r <= n && a[r] < 2 * a[l]) r++;
			if(l != k) r++;
		}
		if(l != k + 1 || r > n){
			hi = k - 1;
		}
		else lo = k;
	}
	printf("%d\n", n - lo);
}