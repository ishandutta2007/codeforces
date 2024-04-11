#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
using lint = long long;
using pi = pair<lint, lint>;

int n, c, a[MAXN], sum[MAXN];
vector<int> pos[MAXN];

int solve(vector<int> &v){
	if(v.empty()) return 0;
	vector<int> ans;
	ans.push_back(-sum[v[0] - 1]);
	for(int i=0; i<v.size(); i++){
		ans.push_back(+1);
		if(i + 1 < v.size()) ans.push_back(sum[v[i]] - sum[v[i+1] - 1]);
		else ans.push_back(sum[v[i]] - sum[n]);
	}
	int ret = 0, cur = 0;
	for(auto &i : ans){
		cur = max(cur + i, 0);
		ret = max(ret, cur);
	}
	return ret;
}

int main(){
	scanf("%d %d",&n,&c);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		sum[i] = sum[i-1] + (a[i] == c);
		pos[a[i]].push_back(i);
	}
	int ret = 0;
	for(int i=1; i<MAXN; i++){
		if(i != c) ret = max(ret, solve(pos[i]));
	}
	cout << ret + sum[n] << endl;
}