#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, a[20];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	for(int i=0;i<(1<<n);i++) {
		int T = 0;
		for(int j=0;j<n;j++) {
			if(i & (1<<j)) T = (T + a[j]) % 360;
			else T = (T + 360 - a[j]) % 360;
		}
		if(T == 0) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}