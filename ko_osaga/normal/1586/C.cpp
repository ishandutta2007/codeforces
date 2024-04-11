#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using llf = long double;
using pi = pair<int, int>;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
const int MAXN = 2100005;

char buf[MAXN];
int main(){
	int n, m;
	scanf("%d %d",&n,&m);
	vector<string> v(n + 1);
	vector<vector<int>> dp(n + 1, vector<int>(m));
	for(int i = 1; i <= n; i++){
		scanf("%s", buf);
		v[i] = string(buf);
	}
	vector<int> chk(m + 1);
	for(int i = 1; i+1 <= n; i++){
		for(int j = 0; j+1 < m; j++){
			if(v[i+1][j+1] == 'X' && v[i+1][j] == 'X' && v[i][j+1] == 'X'){
				chk[j+1]++;
			}
			if(v[i+1][j+1] == '.' && v[i+1][j] == 'X' && v[i][j+1] == 'X'){
				chk[j+1]++;
			}
		}
	}
	for(int i = 1; i <= m; i++) chk[i] += chk[i - 1];
	int q; scanf("%d",&q);
	while(q--){
		int l, r; scanf("%d %d",&l,&r);
		int sum = chk[r - 1] - chk[l - 1];
		if(sum) puts("NO");
		else puts("YES");
	}
}