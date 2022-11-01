#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
ll p, a, b, c;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lld%lld%lld%lld", &p, &a, &b, &c);
		printf("%lld\n", min(p % a ? a - p % a : 0, min(p % b ? b - p % b : 0, p % c ? c - p % c : 0)));
	}
}