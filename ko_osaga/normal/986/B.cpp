#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using lint = long long;
const int MAXN = 1000005;

int n, a[1000005];
int tree[MAXN];

void add(int x, int v){
	while(x < MAXN){
		tree[x] += v;
		x += x & -x;
	}
}

int query(int x){
	int ret = 0;
	while(x){
		ret += tree[x];
		x -= x & -x;
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	lint ans = 0;
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
		ans += i - query(a[i] - 1);
		add(a[i], 1);
	}
	if(ans % 2 == (3 * n) % 2) puts("Petr");
	else puts("Um_nik");
}