#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int mod = 1e9 + 7;
const int MAXN = 300000;

int n, q, a[MAXN];

int main(){
	scanf("%d %d",&n,&q);
	n = (1<<n);
	lint sum = 0;
	for(int i=0; i<n; i++) scanf("%d",&a[i]), sum += a[i];
		printf("%.10f\n", 1.0 * sum / n);
	while(q--){
		int x, v; scanf("%d %d",&x,&v);
		sum -= a[x];
		a[x] = v;
		sum += a[x];
		printf("%.10f\n", 1.0 * sum / n);
	}
}