#include<bits/stdc++.h>
using namespace std;

int n, a[105], b[105], c[105], x, y, z;

char ans[105];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		++c[a[i]];
		if(c[a[i]] == 1) x++;
		if(c[a[i]] == 2) x--;
		if(c[a[i]] == 3) {
			y++;
			z = a[i];
		}
	}
	if(x % 2 == 0 || y > 0) {
		if(x%2==0) z = 0;
		int T = 0, Q = 0;
		for(int i=1;i<=n;i++) {
			if(c[a[i]] == 1) {
				ans[i] = ('A' + (++T % 2));
			}
			else if(a[i] == z) {
				if(Q) ans[i] = 'B';
				else ans[i] = 'A';
				Q = true;
			}
			else ans[i] = 'B';
		}
		puts("YES");
		printf("%s\n",ans+1);
	}
	else puts("NO");
}