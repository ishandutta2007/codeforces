#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n, m, q;
lint a[100005];
vector<int> b[100005];
lint sum[100005], lazy[100005];
int cnt[335][100005];
vector<int> heavy;

int main(){
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
	for(int i=1; i<=m; i++){
		int x;
		scanf("%d",&x);
		b[i].resize(x);
		for(auto &j : b[i]){
			scanf("%d",&j);
			sum[i] += a[j];
		}
		if(x > 300) heavy.push_back(i);
	}
	for(int i=0; i<heavy.size(); i++){
		int chk[100005] = {};
		for(auto &j : b[heavy[i]]){
			chk[j] = 1;
		}
		for(int j=1; j<=m; j++){
			for(auto &k : b[j]){
				if(chk[k]) cnt[i][j]++;
			}
		}
	}
	while(q--){
		char buf[4];
		scanf("%s", buf);
		if(*buf == '?'){
			int x;
			scanf("%d",&x);
			lint ans = 0;
			if(b[x].size() <= 300){
				for(auto &j : b[x]) ans += a[j];
			}
			else ans = sum[x];
			for(int j=0; j<heavy.size(); j++){
				ans += 1ll * lazy[heavy[j]] * cnt[j][x];
			}
			printf("%lld\n", ans);
		}
		else{
			int k, x;
			scanf("%d %d",&k,&x);
			if(b[k].size() <= 300){
				for(auto &j : b[k]) a[j] += x;
				for(int j=0; j<heavy.size(); j++){
					sum[heavy[j]] += 1ll * cnt[j][k] * x;
				}
			}
			else{
				lazy[k] += x;
			}
		}
	}
}