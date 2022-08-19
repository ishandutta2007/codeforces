#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
#define sz(v) ((int)(v).size())
using pi = pair<int, int>;
using lint = long long;

map<int, int> nxt[MAXN];
int cnt[MAXN], piv;
int par[MAXN], pae[MAXN];
int n, arr[MAXN];

int main(){
	int q; cin >> q;
	while(q--){
		scanf("%d",&n);
		for(int i=0; i<n; i++) scanf("%d",&arr[i]);
		int p = 0;
		cnt[0]++;
		for(int i=0; i<n; i++){
			if(p && pae[p] == arr[i]){
				p = par[p];
			}
			else{
				if(!nxt[p][arr[i]]){
					nxt[p][arr[i]] = ++piv;
					par[piv] = p;
					pae[piv] = arr[i];
				}
				p = nxt[p][arr[i]];
			}
			cnt[p]++;
		}
		lint ret= 0;
		for(int i=0; i<=n+3; i++){
			nxt[i].clear();
			ret += 1ll * cnt[i] * (cnt[i] - 1) / 2;
			cnt[i] = par[i] = pae[i] = 0;
		}
		piv = 0;
		printf("%lld\n", ret);
	}
}