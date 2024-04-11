#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

vector<int> gph[100005];
int n;

lint dp[100005], dpb[100005], pdp[100005];
int h1, h2, h3, par[100005], in[100005], out[100005], piv;
bool vis[100005];

vector<int> dfn;
lint dfs(int x, int p){
	if(!vis[x]){
		dfn.push_back(x);
		vis[x] = 1;
		par[x] = p;
	}
	vector<lint> v;
	for(auto &i : gph[x]){
		if(i == p) continue;
		v.push_back((h1 * dfs(i, x)) ^ h2);
	}
	if(v.size() == 0) return dp[x] = 1;
	sort(v.begin(), v.end());
	lint ret = 0, coeff = 1;
	for(auto &i : v){
		ret += coeff * i;
		coeff *= h3;
	}
	dp[x] = ret;
	return ret;
}

vector<lint> lis[100005];
vector<lint> pref[100005], suff[100005], suff2[100005];
lint pw[100005];

void solve(){
	pw[0] = 1;
	for(int i=1; i<=n+3; i++) pw[i] = pw[i-1] * h3;
	for(int i=1; i<=n; i++){
		for(auto &j : gph[i]){
			if(j != par[i]) lis[i].push_back((h1 * dpb[j]) ^ h2);
		}
		sort(lis[i].begin(), lis[i].end());
		pref[i].resize(lis[i].size());
		suff[i].resize(lis[i].size());
		suff2[i].resize(lis[i].size());
		lint coeff = 1;
		for(int j=0; j<lis[i].size(); j++){
			pref[i][j] = lis[i][j] * coeff;
			suff[i][j] = lis[i][j] * coeff;
			coeff *= h3;
			if(j - 1 >= 0) pref[i][j] += pref[i][j-1];
		}
		for(int j=(int)lis[i].size()-2; j>=0; j--){
			suff[i][j] += suff[i][j+1];
		}
		coeff = 1;
		for(int j=1; j<lis[i].size(); j++){
			suff2[i][j] = lis[i][j] * coeff;
			coeff *= h3;
		}	
		for(int j=(int)lis[i].size()-2; j>=0; j--){
			suff2[i][j] += suff2[i][j+1];
		}
	}
	for(int ii=1; ii<dfn.size(); ii++){
		int i = dfn[ii];
		int p = par[i];
		lint hsh = 0;
		if(par[i] != 1){
			lint k = (h1 * pdp[p]) ^ h2;
			lint rem = (h1 * dpb[i]) ^ h2;
			if(k <= rem){
				int l1 = lower_bound(lis[p].begin(), lis[p].end(), k) - lis[p].begin();
				int l2 = lower_bound(lis[p].begin(), lis[p].end(), rem) - lis[p].begin();
				if(l1 > 0) hsh += pref[p][l1-1];
				hsh += pw[l1] * k;
				if(l1 < l2){
					if(l2 > 0) hsh += h3 * pref[p][l2-1];
					if(l1 > 0) hsh -= h3 * pref[p][l1-1];
				}
				if(l2 + 1 < lis[p].size()) hsh += suff[p][l2+1];
			}
			else{
				int l2 = lower_bound(lis[p].begin(), lis[p].end(), k) - lis[p].begin();
				int l1 = lower_bound(lis[p].begin(), lis[p].end(), rem) - lis[p].begin();
				if(l1 > 0) hsh += pref[p][l1-1];
				if(l1 + 1< l2){
					if(l1 + 1 < lis[p].size()) hsh += suff2[p][l1+1];
					if(l2 < lis[p].size()) hsh -= suff2[p][l2];
				}
				if(l2 < lis[p].size()) hsh += suff[p][l2];
				hsh += pw[l2-1] * k;
			}
		}
		else{
			lint rem = (h1 * dpb[i]) ^ h2;
			int l = lower_bound(lis[p].begin(), lis[p].end(), rem) - lis[p].begin();
			if(l > 0) hsh += pref[p][l-1];
			if(l +1< lis[p].size()) hsh += suff2[p][l+1];
			if(lis[p].size() == 1) hsh = 1;
		}
		pdp[i]= hsh;
	}
}


map<lint, int> mp;
int ans[100005];
void dfs2(int x, int p){
	if(x != 1){
		mp[dpb[x]]--;
		mp[pdp[x]]++;
		if(mp[dpb[x]] == 0) mp.erase(dpb[x]);
	}
	ans[x] = mp.size();
	for(auto &i : gph[x]){
		if(i != p) dfs2(i, x);
	}
	if(x != 1){
		mp[dpb[x]]++;
		mp[pdp[x]]--;
		if(mp[pdp[x]] == 0) mp.erase(pdp[x]);
	}
}

int main(){
	int x;
	vector<int> plist = {6131,    6197,    6269,    6299,    6359,    6449,    6551,    6569,    6659};
	srand((unsigned long long)&x);
	random_shuffle(plist.begin(), plist.end());
	h1 = plist[0];
	h2 = plist[1];
	h3 = plist[2];
	scanf("%d",&n);
	for(int i=1; i<n; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	if(n == 1){
		cout << 1;
		return 0;
	}
	dfs(1, 0);
	memcpy(dpb, dp, sizeof(dp));
	solve();
	for(int i=2; i<=n; i++){
		mp[dpb[i]]++;
	}
	dfs2(1, 0);
	printf("%d\n", max_element(ans + 1, ans + n + 1) - ans);
}