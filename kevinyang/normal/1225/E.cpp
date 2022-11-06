#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e9+7;
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	if(n==1&&m==1){
		cout << "1\n";
		return 0;
	}
	vector<vector<int>>arr(n+1,vector<int>(m+1));
	for(int i = 1; i<=n; i++){
		string s;
		cin >> s;
		for(int j = 1; j<=m; j++){
			arr[i][j] = (s[j-1]=='R');
		}
	}
	vector<vector<int>>psa(n+1,vector<int>(m+1));
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			psa[i][j] = psa[i-1][j]+psa[i][j-1]-psa[i-1][j-1]+arr[i][j];
		}
	}
	vector<vector<int>>vmax(n+1,vector<int>(m+1));
	vector<vector<int>>hmax(n+1,vector<int>(m+1));
	vector<vector<int>>vdp(n+1,vector<int>(m+1));
	vector<vector<int>>hdp(n+1,vector<int>(m+1));
	vector<vector<int>>vpsa(n+1,vector<int>(m+1));
	vector<vector<int>>hpsa(n+1,vector<int>(m+1));
	vdp[1][1] = hdp[1][1] = vpsa[1][1] = hpsa[1][1] = 1;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			int sum = psa[i][m]-psa[i][j]-psa[i-1][m]+psa[i-1][j];
			hmax[i][j] = m-sum;
			sum = psa[n][j]-psa[i][j]-psa[n][j-1]+psa[i][j-1];
			vmax[i][j] = n-sum;
		}
	}
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			if(i==1&&j==1)continue;
			int ind = lower_bound(hmax[i].begin(),hmax[i].end(),j)-hmax[i].begin();
			hdp[i][j] = vpsa[i][j-1]-vpsa[i-1][j-1]-vpsa[i][ind-1]+vpsa[i-1][ind-1];
			hdp[i][j]+=mod*5; hdp[i][j]%=mod;
			hpsa[i][j] = hpsa[i-1][j]+hpsa[i][j-1]-hpsa[i-1][j-1]+hdp[i][j];
			hpsa[i][j]+=mod*5; hdp[i][j]%=mod;
			int low = 0; int high = n+1; int mid = (low+high)/2;
			while(low+1<high){
				if(vmax[mid][j]>=i)high = mid;
				else low = mid;
				mid = (low+high)/2;
			}
			ind = high;
			vdp[i][j] = hpsa[i-1][j]-hpsa[i-1][j-1]-hpsa[ind-1][j]+hpsa[ind-1][j-1];
			vdp[i][j]+=mod*5; vdp[i][j]%=mod;
			vpsa[i][j] = vpsa[i-1][j] + vpsa[i][j-1]-vpsa[i-1][j-1]+vdp[i][j];
			vpsa[i][j]+=mod*5; vdp[i][j]%=mod;
		}
	}
	cout << (vdp[n][m]+hdp[n][m])%mod << "\n";
	return 0;
}