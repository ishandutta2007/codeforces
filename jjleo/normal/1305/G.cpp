#include <bits/stdc++.h>
#define maxn 400086

using namespace std;

typedef long long ll;

int fa[maxn], siz[maxn];

int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int n;
int cnt[maxn];
int x, y;
ll ans;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		++cnt[x];
		ans -= x;
	}
	for(int i = 0;i <= 2e5;i++) fa[i] = i, siz[i] = 1;//debug:  cnt[j] + cnt[k] - 1 
	++cnt[0];
	for(int i = 1 << 18;i;i--){
		for(int j = i;;j = (j - 1) & i){
			int k = i ^ j;
			if(cnt[j] && cnt[k]){
				x = find(j), y = find(k);
				if(x != y){
					if(siz[x] > siz[y]) swap(x, y);
					siz[y] += siz[x];
					fa[x] = y;
					ans += 1ll * (cnt[j] + cnt[k] - 1) * i;
					cnt[j] = cnt[k] = 1;//debug:  
				}
			}
			if(!j) break;
		}
	}//
	printf("%lld", ans);
}