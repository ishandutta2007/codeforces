#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, m;
int a, b, c, d, e;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		printf("SCAN %d %d\n", 1, 1), fflush(stdout);
		scanf("%d", &a);
		printf("SCAN %d %d\n", 1, m), fflush(stdout);
		scanf("%d", &b);
		int xx = (a + b + 6 - 2 * m) / 2;
		int yy = (a - b + 2 + 2 * m) / 2;
		printf("SCAN %d %d\n", xx / 2, 1), fflush(stdout);
		scanf("%d", &c);
		int xx_ = c + 2 - yy;
		int x2 = (xx_ + xx) / 2, x1 = (xx - xx_) / 2;
		printf("SCAN %d %d\n", 1, yy / 2), fflush(stdout);
		scanf("%d", &d);
		int yy_ = d + 2 - xx;
		int y2 = (yy_ + yy) / 2, y1 = (yy - yy_) / 2;
		printf("DIG %d %d\n", x1, y1), fflush(stdout);
		scanf("%d", &e);
		if(e){
			printf("DIG %d %d\n", x2, y2), fflush(stdout);
			scanf("%d", &e);
		}else{
			printf("DIG %d %d\n", x1, y2), fflush(stdout);
			scanf("%d", &e);
			printf("DIG %d %d\n", x2, y1), fflush(stdout);
			scanf("%d", &e);
		}
	}
}