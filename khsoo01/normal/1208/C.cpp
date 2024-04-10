#include<bits/stdc++.h>
using namespace std;

int n, a[1005][1005];

int main()
{
	scanf("%d",&n);
	int c = 0;
	for(int x=0;x<n;x+=4) {
		for(int y=0;y<n;y+=4) {
			for(int i=0;i<4;i++) {
				for(int j=0;j<4;j++) {
					int T = (i % 2 ? 3 - j : j) + i*4;
					a[x+i][y+j] = T + c;
				}
			}
			c += 16;
		}
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			printf("%d ", a[i][j]);
		}
		puts("");
	}
}