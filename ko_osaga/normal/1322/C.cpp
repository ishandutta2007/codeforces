#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int MAXN = 1000005;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
lint randint(lint lb, lint ub){ return uniform_int_distribution<lint>(lb, ub)(rng); }
lint val[MAXN];

int n, m;
int p[MAXN];
vector<int> gph[MAXN];
lint hsh[MAXN];
lint a[MAXN];

int main(){
	int tc; scanf("%d",&tc);
	for(int i=0; i<tc; i++){
		scanf("%d %d",&n,&m);
		for(int i=0; i<n; i++) scanf("%lld",&a[i]);
		for(int i=0; i<n; i++){
			val[i] = randint(0, (1ll << 62) - 1);
		}
		for(int i=0; i<m; i++){
			int s, e; scanf("%d %d",&s,&e);
			gph[e-1].push_back(s-1);
		}
		for(int i=0; i<n; i++){
			sort(all(gph[i]));
			hsh[i] = 0;
			for(auto &j : gph[i]) hsh[i] ^= val[j];
		}
		iota(p, p + n, 0);
		sort(p, p + n, [&](const int &a, const int &b){
			return hsh[a] < hsh[b];
		});
		lint g = 0;
		for(int i=0; i<n; ){
			if(hsh[p[i]] == 0){
				i++;
				continue;
			}
			int e = i;
			lint cur = 0;
			while(e < n && hsh[p[e]] == hsh[p[i]]){
				cur += a[p[e]];
				e++;
			}
			i = e;
			g = gcd(g, cur);
		}
		printf("%lld\n", g);
		for(int i=0; i<n; i++) gph[i].clear();
	}
}