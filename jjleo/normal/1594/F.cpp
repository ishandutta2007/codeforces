#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
ll s, n, k;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lld%lld%lld", &s, &n, &k);
		if(k > s){
			puts("NO");
			continue;
		}
		if(k == s){
			puts("YES");
			continue;
		}
		puts((__int128)s / (k * 2) * k + min(s % (k * 2), k) - ((s - k) % (k * 2) < k) >= n ? "NO" : "YES");
	}
}