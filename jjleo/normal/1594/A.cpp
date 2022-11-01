#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
ll n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		printf("%lld %lld\n", -(n - 1), n);
	}
}