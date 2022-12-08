#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
int n,k,q;
const int N=2e5+5;
const int blk = 840;
vector<int> group[N];
struct block{
	int cnt[1<<14];
	vector<int> member;
	int prefix;
}s;

int id[N],g[N],tmp[N];
int a[N],c[N],b[N];
vector<block> G[N];
int totcnt=0,ans;
int endval[N];
void modify(int x){
	int pst=c[x];
	c[x]=a[x]^b[x]^a[x-1]^b[x-1];
	ans-=G[g[x]][id[x]].cnt[G[g[x]][id[x]].prefix];
	for(int t=x;t<=n&&id[t]==id[x];t+=k){
//		cout<<t<<" "<<tmp[t]<<" towards ";
		G[g[x]][id[x]].cnt[tmp[t]]--;
//		if(G[g[x]][id[x]].cnt[tmp[t]]==0)G[g[x]][id[x]].cnt.erase(tmp[t]);
		tmp[t]^=c[x]^pst;
		G[g[x]][id[x]].cnt[tmp[t]]++;
//		cout<<t<<" "<<tmp[t]<<endl;
	}
	ans+=G[g[x]][id[x]].cnt[G[g[x]][id[x]].prefix];
	for(size_t jj=id[x]+1;jj < G[g[x]].size();jj++){
		ans-=G[g[x]][jj].cnt[G[g[x]][jj].prefix];
		G[g[x]][jj].prefix^=c[x]^pst;
		ans+=G[g[x]][jj].cnt[G[g[x]][jj].prefix];
	}
	totcnt -= (endval[g[x]] > 0);
	endval[g[x]]^=c[x]^pst;
//	cout<<x<<"::"<<(c[x]^pst)<<endl;
	totcnt += (endval[g[x]] > 0);
}
namespace big {
#define ri register int
int d[N], ans, cnt;
void modify(int x) {
	c[x] = a[x] ^ a[x-1] ^ b[x] ^ b[x-1];
	for(ri i = x; i <= n; i += k) {
		if(i + k > n) cnt -= d[i] != 0;
		ans -= d[i] == 0, d[i] = c[i] ^ d[max(0, i-k)], ans += d[i] == 0;
		if(i + k > n) cnt += d[i] != 0;
	}
}
#define rep(i, x, y) for(ri i = x; i <= y; ++i)
void solve() {
	int x, v;
	ans = n;
	rep(i, 1, n) modify(i);
	char s[10];
	printf("%d\n", cnt ? -1 : n-ans);
	while(q--) {
		scanf("%s", s), scanf("%d%d",&x,&v);
		if(s[0] == 'a') a[x] = v;
		else b[x] = v;
		modify(x), modify(x+1);
		printf("%d\n", cnt ? -1 : n-ans);
	}
}
}
int main()
{
	cin >> n >> k >> q;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	++n;
	if(k>=sqrt(n)){big::solve();return 0;}
	for(int i=0;i<k;i++)for(int j=i?i:k;j<=n;j+=k){
		group[i].push_back(j);g[j]=i;
	}
	for(int i=0;i<k;i++){
		int tt=-1;
		for(size_t j=0;j<group[i].size();j++){
			int t=group[i][j];
			if(j%blk == 0) {G[i].push_back(s); ++tt;}
			G[i][tt].member.push_back(t);
			G[i][tt].cnt[0]++;
			ans ++;
			id[t]=tt;
		}
	}
	for(int i=1;i<=n;i++)modify(i);
	printf("%d\n",totcnt?-1:n-ans);
	while(q--){
		char s[4];int x,y;scanf("%s%d%d",s+1,&x,&y);
		if(s[1]=='a')a[x] = y;
		else b[x] = y;
		modify(x);
		modify(x+1);
		printf("%d\n",totcnt?-1:n-ans);
	}
}