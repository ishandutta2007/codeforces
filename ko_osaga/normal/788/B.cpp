#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

const int MAXN = 1000005;
struct disj{
	int pa[MAXN], sz[MAXN];
	void init(int n){
		for(int i=0; i<=n; i++){
			pa[i] = i;
			sz[i] = 1;
		}
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		pa[q] = p;
		sz[p] += sz[q];
		return 1;
	}
}disj;

int n, m;
int s[1000005], e[1000005];
bool chk[1000005];
int cnt[1000005], wat[1000005];

int main(){
	scanf("%d %d",&n,&m);
	disj.init(n);
	int tmp = 0;
	for(int i=0; i<m; i++){
		scanf("%d %d",&s[i],&e[i]);
		if(s[i] == e[i]){
			wat[s[i]]++;
			continue;
		}
		disj.uni(s[i], e[i]);
		cnt[s[i]]++;
		cnt[e[i]]++;
	}
	for(int i=0; i<m; i++) chk[disj.find(s[i])] = 1;
	if(count(chk, chk + n + 1, 1) != 1){
		puts("0");
		return 0;
	}
	lint ret = 0;
	for(int i=1; i<=n; i++){
		ret += 1ll * cnt[i] * (cnt[i] - 1) / 2;
		tmp += wat[i];
	}
	if(tmp > 0){
		ret += 1ll * tmp * (m - tmp);
		ret += 1ll * tmp * (tmp - 1) / 2;
	}
	cout << ret;
}