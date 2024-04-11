#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int MAXN = 2000005;

int n, k;
int main(){
	cin >> n >> k;
	int l = (n - 1) / k;
	int m = (n - 1) % k;
	vector<int> ans;
	for(int i=0; i<m; i++) ans.push_back(l + 1);
	for(int i=m; i<k; i++) ans.push_back(l);
	sort(ans.begin(), ans.end());
	printf("%d\n", ans[ans.size() - 2] + ans.back());
	int nd = 1;
	for(auto &i : ans){
		int prv = 1;
		while(i > 0){
			printf("%d %d\n", prv, ++nd);
			prv = nd;
			i--;
		}
	}
}