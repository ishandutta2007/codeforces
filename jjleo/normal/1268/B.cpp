#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

typedef long long ll;

int n;
int x;
ll a, b;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		if(i & 1) a += (x + 1) >> 1, b += x >> 1;
		else a += x >> 1, b += (x + 1) >> 1; 
	}
	printf("%lld", min(a, b));
}