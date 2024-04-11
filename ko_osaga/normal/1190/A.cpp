#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using lint = long long;
const int MAXN = 1000005;

lint n, m, k, a[MAXN];

int main(){
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1; i<=m; i++){
		scanf("%lld",&a[i]);
		a[i]--;
	}
	int ret = 0;
	for(int i=1; i<=m; ){
		lint curLast = a[i] - (i - 1);
		curLast -= curLast % k;
		int j = i;
		while(j <= m && a[j] - (i - 1) <= curLast + k - 1) j++;
		i = j;
		ret++;
	}
	cout << ret << endl;
}