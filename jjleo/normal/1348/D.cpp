#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a[maxn], cnt;

int main(){
	scanf("%d", &t);
	a[0] = 1;
	while(t--){
		scanf("%d", &n);
		int x = 4, y = 1;
		while(x - 1 < n) x <<= 1, y++;
		printf("%d\n", y);
		int z = x - 1 - n;
		cnt = 0, n = x - 1 - n;
		for(int i = y, j = 1 << i;i;i--, j >>= 1){
			int b = min(z, j >> 1);
			z -= b, a[i] = j - b;
		}
		for(int i = 1;i <= y;i++) printf("%d ", a[i] - a[i - 1]);puts("");
		
	}
}