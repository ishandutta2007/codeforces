#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, a, b, c;

int cal(long long x){
	int sum = 0;
	while(x) x /= 10, sum++;
	return sum;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &a, &b, &c);
		long long x = 1, y = 1, z = 1;
		for(int i = 1;i < c;i++) z *= 10;
		for(int i = 1;i < a - c + 1;i++) x = x * 10 + 1;
		while(cal(y) < b - c + 1) y *= 2;
		printf("%lld %lld\n", x * z, y * z);
	} 
}