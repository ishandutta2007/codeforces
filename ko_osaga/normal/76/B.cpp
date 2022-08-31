#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;

int n, m;
int l[100005], r[100005];
int doc[100005], chk[100005];
bool vis[200005];

vector<int> gph[200005];
vector<int> tim[200005];
void add_edge(int s, int e){
	gph[s].push_back(e);
	gph[e].push_back(s);
}

int dfs(int x){
	if(vis[x]) return 0;
	vis[x] = 1;
	int ret = 0;
	for(auto &i : gph[x]) ret += dfs(i);
	if(x >= n){
		if(tim[x].size() >= 2 && tim[x][0] == tim[x][1]) ret -= 2;
		else ret--;
	}
	else ret++;
	return ret;
}

int main(){
	scanf("%d %d %*d %*d",&n,&m);
	for(int i=0; i<n; i++){
		scanf("%d",&l[i]);
	}
	for(int i=0; i<m; i++){
		scanf("%d",&r[i]);
	}
	if(m == 0){
		printf("%d\n", n);
		return 0;
	}
	memset(doc, 0x3f, sizeof(doc));
	for(int i=0; i<n; i++){
		auto w = lower_bound(r, r+m, l[i]);
		if(w != r && w != r+m && *w - l[i] == l[i] - *(w-1)){
			continue;
		}
		if(w == r+m || (w != r && *w - l[i] > l[i] - *(w-1))){
			int t = l[i] - *(w-1);
			if(doc[w-r-1] > t){
				doc[w-r-1] = t;
				chk[w-r-1] = 1;
			}
			else if(doc[w-r-1] == t){
				chk[w-r-1]++;
			}
		}
		else{
			int t = *w - l[i];
			if(doc[w-r] > t){
				doc[w-r] = t;
				chk[w-r] = 1;
			}
			else if(doc[w-r] == t){
				chk[w-r]++;
			}
		}
	}
	int ret = n;
	for(int i=0; i<m; i++) ret -= chk[i];
	vector<int> v;
	for(int i=0; i<n; i++){
		auto w = lower_bound(r, r+m, l[i]);
		if(w != r && w != r+m && *w - l[i] == l[i] - *(w-1)){
			ret--;
			if(!chk[w-r-1] || doc[w-r-1] == l[i] - *(w-1)){
				tim[w-r-1 + n].push_back(l[i] - *(w-1));
				add_edge(w-r-1 + n, i);
			}
			if(!chk[w-r] || doc[w-r] == *w - l[i]){
				tim[w-r + n].push_back(*w - l[i]);
				add_edge(w-r + n, i);
			}
			v.push_back(i);
		}
	}
	for(int i=0; i<n+m; i++){
		sort(tim[i].begin(), tim[i].end());
	}
	for(auto &i : v){
		if(!vis[i]){
			ret += max(0, dfs(i));
		}
	}
	cout << ret;
}