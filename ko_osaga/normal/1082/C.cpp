#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
using lint = long long;
using pi = pair<lint, lint>;

int n, m;
vector<int> sbj[MAXN];
int ret[MAXN];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++){
		int x, y; scanf("%d %d",&x,&y);
		sbj[x].push_back(y);
	}
	for(int i=1; i<=m; i++) sort(sbj[i].rbegin(), sbj[i].rend());
	for(int i=1; i<=m; i++){
		int sum = 0;
		for(int j=1; j<=sbj[i].size(); j++){
			sum += sbj[i][j-1];
			ret[j] += max(sum, 0);
		}
	}
	cout << *max_element(ret, ret + MAXN) << endl;
}