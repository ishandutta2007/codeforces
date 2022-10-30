#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int t, n, c, q;
char s[maxn];
ll l[maxn], r[maxn], sum[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%s", &n, &c, &q, s + 1);
		sum[0] = n;
		for(int i = 1;i <= c;i++) scanf("%lld%lld", &l[i], &r[i]), sum[i] = sum[i - 1] + r[i] - l[i] + 1;
		while(q--){
			ll x;
			scanf("%lld", &x);
			for(int i = c;i;i--){
				if(sum[i - 1] >= x) continue;
				x = x - sum[i - 1] + l[i] - 1;
			}
			printf("%c\n", s[x]);
		}
	}
}