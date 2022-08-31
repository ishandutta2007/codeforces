#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n, q;
int par[19][300005], size[300005], mxsz[300005];
int prnt[300005];
vector<int> gph[300005];

void dfs(int x){
	size[x] = 1;
	for(auto &i : gph[x]){
		dfs(i);
		size[x] += size[i];
		mxsz[x] = max(mxsz[x], size[i]);
	}
}

vector<int> ins[300005];
vector<int> cur[300005];

int ret[300005];
int dfs2(int x){
	cur[x] = ins[x];
	int cpos = x;
	for(auto &i : gph[x]){
		int p = dfs2(i);
		if(cur[p].size() > cur[cpos].size()){
			for(auto &i : cur[cpos]){
				cur[p].push_back(i);
			}
			cpos = p;
		}
		else{
			for(auto &i : cur[p]){
				cur[cpos].push_back(i);
			}
		}
	}
	while(cur[cpos].size() && size[cur[cpos].back()] <= (size[x] - 1) / 2){
		cur[cpos].pop_back();
	}
	if(!cur[cpos].empty()) ret[x] = cur[cpos].back();
	return cpos;
}

int main(){
	cin >> n >> q;
	for(int i=2; i<=n; i++){
		scanf("%d",&par[0][i]);
		gph[par[0][i]].push_back(i);
	}
	dfs(1);
	for(int i=1; i<=18; i++){
		for(int j=1; j<=n; j++){
			par[i][j] = par[i-1][par[i-1][j]];
		}
	}
	size[0] = 1e9;
	for(int i=1; i<=n; i++){
		int piv = 2 * mxsz[i] + 1;
		int pos = i;
		for(int j=18; j>=0; j--){
			if(size[par[j][pos]] < piv){
				pos = par[j][pos];
			}
		}
		if(size[pos] < piv) pos = par[0][pos];
		ins[pos].push_back(i);
	}
	dfs2(1);
	for(int i=0; i<q; i++){
		scanf("%d",&prnt[i]);
		printf("%d\n",ret[prnt[i]]);
	}
}