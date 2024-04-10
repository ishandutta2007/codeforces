// Hydro submission #6145ee744aae4446252aa24a@1631972981119
#include <stdio.h>
int T, n, s[200050], i, a;
int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(i = 0; i <= n; ++i) s[i] = 0;
		for(i = 1; i <= n; ++i) {
			scanf("%d", &a);
			s[i+1] -= 1; s[i-a+1 > 0 ? i-a+1 : 0] += 1;
		}
		for(i = 1; i <= n; ++i) s[i] += s[i-1];
		for(i = 1; i < n; ++i)
			printf("%d ",s[i]>0?1:0);
			printf("%d",s[n]>0?1:0);
	if(T>0)	putchar('\n');
	}
}