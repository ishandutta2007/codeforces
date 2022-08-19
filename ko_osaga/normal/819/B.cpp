#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int n, a[1000005];
lint ans[1000005], dx[1000005], dx2[1000005];

void add_intv(int s, int e, int x){
	if(s <= x && x <= e){
		dx[s] += x;
		dx[x] -= x;
		dx[x+1] -= x;
		dx[e+1] += x;
		dx2[s] -= 1;
		dx2[x] += 1;
		dx2[x+1] += 1;
		dx2[e+1] -= 1;
	}
	else if(e <= x){
		dx[s] += x;
		dx[e+1] -= x;
		dx2[s] -= 1;
		dx2[e+1] += 1;
	}
	else{
		dx[s] -= x;
		dx[e+1] += x;
		dx2[s] += 1;
		dx2[e+1] -= 1;
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
		a[i] -= i + 1;
		add_intv(0, n-i-1, a[i]);
		add_intv(n-i, n-1, a[i] + n);
	}
	for(int i=0; i<n; i++){
		if(i) dx[i] += dx[i-1], dx2[i] += dx2[i-1];
		ans[i] = dx[i] + dx2[i] * i;
	}
	lint* p = min_element(ans, ans + n);
	printf("%lld %d\n", *p, (int)(p - ans));
}