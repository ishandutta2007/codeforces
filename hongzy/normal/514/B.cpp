#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

const int N = 2e3 + 10;

struct point {
	int x, y;
} s, a[N];
int n, vis[N];

int main() {
	scanf("%d%d%d", &n, &s.x, &s.y);
	for(int i = 1; i <= n; i ++) {
		scanf("%d%d", &a[i].x, &a[i].y);
	}
	int cnt = 0;
	for(int i = 1; i <= n; i ++) if(!vis[i]) {
		vis[i] = 1; cnt ++;
		if(a[i].x == s.x) {
			for(int j = i + 1; j <= n; j ++) if(!vis[j]) {
				if(a[j].x == a[i].x) {
					vis[j] = 1;
				}
			}
			continue ;
		}
		double k = (a[i].y - s.y) / (double) (a[i].x - s.x);
		double b = b = s.y - k * s.x;
		for(int j = i + 1; j <= n; j ++) if(!vis[j]) {
			if(fabs(k * a[j].x + b - a[j].y) < 1e-7) {
				vis[j] = 1;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}