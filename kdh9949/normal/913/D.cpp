#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using pll = pair<ll, ll>;

#define X first
#define Y second

const int MN = 200005;

int n, t;
piii a[MN];

int f(int x, int pr){
	if(x == 0) return 1;
	int cs = 0, ts = 0;
	for(int i = 1; i <= n; i++){
		if(a[i].X.Y >= x){
			cs++;
			ts += a[i].X.X;
			if(pr) printf("%d ", a[i].Y);
			if(ts > t) return 0;
			if(cs == x) return 1;
		}
	}
	return 0;
}

int main(){
	scanf("%d%d", &n, &t);
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &a[i].X.Y, &a[i].X.X);
		a[i].Y = i;
	}
	sort(a + 1, a + n + 1);
	int s = 0, e = n;
	while(s <= e){
		int m = (s + e) / 2;
		if(f(m, 0)) s = m + 1;
		else e = m - 1;
	}
	printf("%d\n%d\n", e, e);
	f(e, 1);
	puts("");
}