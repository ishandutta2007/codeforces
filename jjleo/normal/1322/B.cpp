#include <bits/stdc++.h>
#define maxn 400086

using namespace std;

int n;
int a[maxn], b[maxn], c;
//int l1, r1, l2;
int ans;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int k = 1 << 25;k;k >>= 1){
		for(int i = 1;i <= n;i++) b[i] = a[i] % (k << 1);
		sort(b + 1, b + 1 + n);
		//for(int i = 1;i <= n;i++) printf("%d ", b[i]);puts("");
		c = 0;//, l1 = l2 = n + 1, r1 = n;
		for(int i = 1;i <= n;i++){
			c += upper_bound(b + i + 1, b + 1 + n, (k << 1) - b[i] - 1) - lower_bound(b + i + 1, b + 1 + n, k - b[i]) + upper_bound(b + i + 1, b + 1 + n, (k << 2) - 2 - b[i]) - lower_bound(b + i + 1, b + 1 + n, k + (k << 1) - b[i]); 
			/*while(l1 && b[l1 - 1] >= k - b[i]) --l1;
			while(r1 && b[r1 - 1] >= (k << 1) - b[i]) --r1;
			while(l2 && b[l2 - 1] >= k + (k << 1) - b[i]) --l2;
			if(k <= 2) printf("%d %d %d %d--\n", i, l1, r1, l2);
			c = (c + max(r1, i + 1) - max(l1, i + 1), n - max(l2, i + 1) + 1) % 2;*/
		}
		ans |= k * (c & 1);
	}
	printf("%d", ans);
}