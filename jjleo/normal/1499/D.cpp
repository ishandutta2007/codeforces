#include <bits/stdc++.h>
#define maxn 20000086

using namespace std;

typedef long long ll;

int t;
int n;
bool tag[maxn];
int cnt[maxn];
int c, d, x;

ll cal(int g){
	if((x / g + d) % c) return 0;
	return 1ll << cnt[(x / g + d) / c];
}

int main(){
	for(int i = 2;i < maxn;i++){
		if(!tag[i]){
			for(int j = i;j < maxn;j += i){
				cnt[j]++, tag[j] = true;
			} 
		} 
	}
	scanf("%d", &t);
	while(t--){
		ll ans = 0;
		scanf("%d%d%d", &c, &d, &x);
		for(int i = 1;i * i <= x;i++){
			if(x % i) continue;
			ans += cal(i);
			if(i * i != x) ans += cal(x / i); 
		}
		printf("%lld\n", ans);
	}	
}