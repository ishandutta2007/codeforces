#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int a, b, c, d;
long long ans;

int main(){
	scanf("%d%d%d%d", &a, &b, &c, &d);
	for(int i = a;i <= b;i++){
		if(i + b > d) ans += 1ll * (c - b + 1) * (d - c + 1);
		else if(i + c > d) ans += 1ll * (i + c - d) * (d - c + 1) + 1ll * (d - max(i + b, c) + 1) * (max(i + b, c) - c + (d - c)) / 2;
		else ans += 1ll * (i + c - max(i + b, c) + 1) * (max(i + b, c) - c + (i + c - c)) / 2;
	}
	printf("%lld", ans);
}