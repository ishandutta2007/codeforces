#include<bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 200005;
const int mod = 998244353;

int n;
char str[MAXN];
int low[MAXN];
int cnt[MAXN][26];

int main(){
	int t; scanf("%d",&t);
	while(t--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> v(n);
		for(auto &i : v) scanf("%d",&i);
		if(m - 1 <= k){
			int ret = 0;
			for(int i=0; i<m; i++) ret = max(ret, v[i]);
			for(int i=0; i<m; i++) ret = max(ret, v[n-1-i]);
			printf("%d\n", ret);
			continue;
		}
		k = n - k;
		m = n - m;
		int dap = 0;
		for(int i=0; i+k-1<n; i++){
			int ans = 1e9;
			for(int j=i; j+m<=i+k-1; j++){
				ans = min(ans, max(v[j], v[j+m]));
			}
			dap =max(dap, ans);
		}
		cout << dap << endl;
	}
}