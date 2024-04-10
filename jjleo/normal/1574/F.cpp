#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

const int p = 998244353;

int n, m, k;
int to[maxn], deg[maxn];
bool del[maxn];
int x, y;
int cnt[maxn], f[maxn];
vector<pair<int, int> > v;

int main(){
	scanf("%d%d%d", &n, &m, &k);
	while(n--){
		scanf("%d", &x);
		int last = 0;
		while(x--){
			scanf("%d", &y);
			if(last){
				if(!to[last]){
					to[last] = y, deg[y]++;
					if(deg[y] == 2) del[y] = del[last] = true;
				}else if(to[last] ^ y) del[y] = del[last] = true;
			}
			last = y;
		}
	}
	for(int i = 1;i <= k;i++) if(!deg[i]){
		int x = i, len = 0;
		while(x){
			if(del[x]){
				len = 0;
				break;
			}
			len++, x = to[x];
		}
		if(len) cnt[len]++;
	}
	for(int i = 1;i <= m;i++) if(cnt[i]) v.push_back({i, cnt[i]});
	f[0] = 1;
	for(int i = 1;i <= m;i++){
		for(int j = 0;j < v.size();j++){
			int x = v[j].first, y = v[j].second;
			if(i - x < 0) break;
			f[i] = (f[i] + 1ll * y * f[i - x]) % p;
		}
	}
	printf("%d", f[m]);
}