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
		puts(n > 14 && n % 14 >= 1 && n % 14 <= 6 ? "YES" : "NO");
	}
}