#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int main(){
	int n;
	scanf("%d",&n);
	puts("YES");
	while(n--){
		int x1, y1, x2, y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		int k = abs(x1) % 2, l = abs(y1) % 2;
		printf("%d\n", k * 2 + l + 1);
	}
}