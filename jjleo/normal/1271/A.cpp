#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int a, b, c, d, e, f;
int ans;

int main(){
	scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
	if(e > f){
		int x = min(a, d);
		ans += x * e, d -= x;
		x = min(b, min(c, d));
		ans += x * f;
	}else{
		int x = min(b, min(c, d));
		ans += x * f, d -= x;
		x = min(a, d);
		ans += x * e;
	}
	printf("%d", ans);
}