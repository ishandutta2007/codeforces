#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
using pi = pair<int, int>;
#define all(v) (v).begin(), (v).end()
const int MAXN = 1000005;

int n;
pi a[MAXN];
vector<int> gph[MAXN];
int vis[MAXN], chk[MAXN];
vector<int> dfn;

int dfs(int x){
	if(vis[x]) return 0;
	vis[x] = 1;
	dfn.push_back(x);
	int ret=1;
	for(auto &i : gph[x]){
		ret+=dfs(i);
	}
	return ret;
}

int main(){
	int n; cin >> n;
	if(n % 2 == 0){
		cout << "First" << endl;
		for(int i = 0; i < 2 * n; i++){
			printf("%d ", i % n + 1);
		}
		cout << endl;
		return 0;
	}
	cout << "Second" << endl;
	for(int i=1; i<=2*n; i++){
		int w; scanf("%d",&w);
		if(!a[w].first) a[w].first = i;
		else a[w].second = i;
	}
	for(int i=1; i<=n; i++){
		gph[i].push_back(i + n);
		gph[i + n].push_back(i);
		gph[a[i].first].push_back(a[i].second);
		gph[a[i].second].push_back(a[i].first);
	}
	lint found = 0;
	lint ret = 0;
	vector<int> revoker;
	for(int i=1; i<=n; i++){
		if(vis[i]) continue;
		dfn.clear();
		int sz = dfs(i) / 2;
		if(sz % 2 == 1 && found == 0){
			found = 1;
			revoker = dfn;
		}
		for(int i=0; i<dfn.size(); i+=2){
			chk[dfn[i]] = 1;
			ret += dfn[i];
		}
	}
	assert(ret % n == 0);
	if(ret % (2 * n) != 0){
		for(auto &i : revoker) chk[i] ^= 1;
	}
	for(int i=1; i<=2*n; i++){
		if(chk[i]) printf("%d ", i);
	}
	cout << endl;
	return 0;
	
}