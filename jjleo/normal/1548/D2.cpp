#include <bits/stdc++.h>
#define maxn 6086
using namespace std;

int n;
int f[4][4][4];
int x[maxn], y[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d%d", &x[i], &y[i]);
	long long eee = 0, eoo = 0;
	for(int i = 1;i <= n;i++){
		memset(f, 0, sizeof(f));
		for(int j = 1;j <= n;j++) if(i ^ j) f[x[j] % 4][y[j] % 4][__gcd(abs(x[i] - x[j]), abs(y[i] - y[j])) % 4]++;
		for(int x1 = 0;x1 < 4;x1++) for(int y1 = 0;y1 < 4;y1++) for(int b1 = 0;b1 < 4;b1++){
			int val = f[x1][y1][b1]--;
			for(int x2 = x1 & 1;x2 < 4;x2 += 2) for(int y2 = y1 & 1;y2 < 4;y2 += 2) for(int b2 = b1 & 1;b2 < 4;b2 += 2){
				int S = ((x[i] * (y1 - y2) + x1 * (y2 - y[i]) + x2 * (y[i] - y1)) % 4 + 4) % 4 / 2;
				int b3 = __gcd(abs(x1 - x2), abs(y1 - y2));
				if((S - (b1 + b2 + b3) / 2 + 1) & 1){
					if(b1 & 1) eoo += val * f[x2][y2][b2];
					else eee += val * f[x2][y2][b2];
				}
			}
			f[x1][y1][b1]++;
		} 
	}
	printf("%lld", eee / 6 + eoo / 2);
}