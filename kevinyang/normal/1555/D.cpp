#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	int psa[3][3][n+5];
	memset(psa,0,sizeof(psa));
	for(int a = 0; a<3; a++){
		for(int b = 0; b<3; b++){
			for(int i = 1; i<=n; i++){
				psa[a][b][i]+=psa[a][b][i-1];
				if(i%3==b&&s[i-1]==(char)('a'+a))psa[a][b][i]++;
			}
		}
	}
	while(m--){
		int l,r;
		cin >> l >> r;
		int len = r-l+1;
		int ans = (int)1e18;
		vector<int>perm = {0,1,2};
		do{
			int sum = 0;
			for(int i = 0; i<3; i++){
				sum+=psa[i][perm[i]][r]-psa[i][perm[i]][l-1];
			}
			ans = min(ans,len-sum);
		}
		while(next_permutation(perm.begin(),perm.end()));
		cout << ans << "\n";
	}
	return 0;
}