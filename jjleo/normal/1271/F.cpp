#include <bits/stdc++.h>
#define maxn 3086

using namespace std;

int t;
int a[2], b[2], c[2];
int d[8];
bool tag;


int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d%d%d", &a[0], &b[0], &c[0], &a[1], &b[1], &c[1]);
		for(int i = 1;i <= 7;i++) scanf("%d", &d[i]);
		tag = false;
		for(int i = 0;i <= d[2];i++){
			if(tag) break;
			a[0] -= i, b[0] -= i, a[1] -= d[2] - i, b[1] -= d[2] - i;
			if(a[0] < 0 || b[0] < 0 || a[1] < 0 || b[1] < 0){
				a[0] += i, b[0] += i, a[1] += d[2] - i, b[1] += d[2] - i;
				continue;
			}
			for(int j = 0;j <= d[3];j++){
				if(tag) break;
				a[0] -= j, c[0] -= j, a[1] -= d[3] - j, c[1] -= d[3] - j;
				if(a[0] < 0 || c[0] < 0 || a[1] < 0 || c[1] < 0){
					a[0] += j, c[0] += j, a[1] += d[3] - j, c[1] += d[3] - j;
					continue;
				}
				for(int k = 0;k <= d[5];k++){
					if(tag) break;
					b[0] -= k, c[0] -= k, b[1] -= d[5] - k, c[1] -= d[5] - k;
					if(b[0] < 0 || c[0] < 0 || b[1] < 0 || c[1] < 0){
						b[0] += k, c[0] += k, b[1] += d[5] - k, c[1] += d[5] - k;
						continue;
					}
					if(min(a[0], min(b[0], c[0])) + min(a[1], min(b[1], c[1])) >= d[1]){
						int x = min(min(a[0], min(b[0], c[0])), d[1]), y = d[1] - x;
						if(a[0] + a[1] - d[1] >= d[4] && b[0] + b[1] - d[1] >= d[6] && c[0] + c[1] - d[1] >= d[7]){
							tag = true;
							printf("%d %d %d %d %d %d %d\n", x, i, j, min(a[0] - x, d[4]), k, min(b[0] - x, d[6]), min(c[0] - x, d[7]));
						}
					}
					b[0] += k, c[0] += k, b[1] += d[5] - k, c[1] += d[5] - k;
				}
				a[0] += j, c[0] += j, a[1] += d[3] - j, c[1] += d[3] - j;
			}
			a[0] += i, b[0] += i, a[1] += d[2] - i, b[1] += d[2] - i;
		}
		if(!tag) puts("-1");
	} 
}