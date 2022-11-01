#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, m;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), a[n + 1] = m;
		double l = 0, r = m, mid, ans;
		for(int b = 1;b <= 50;b++){
			mid = (l + r) / 2;
			int v = 1;
			double x = 0, y = 0;
			for(int i = 1;i <= n + 1;i++){
				x += (min(1.0 * a[i], mid) - a[i - 1]) / (v++);
				if(a[i] >= mid) break;
			}
			v = 1;
			for(int i = n;~i;i--){
				y += (a[i + 1] - max(1.0 * a[i], mid)) / (v++);
				if(a[i] <= mid) break;
			}
			//printf("%f %f--\n", x, y);
			if(x > y) r = mid;
			else l = mid;
			ans = x;
		}
		printf("%.10f\n", ans);
	}
}