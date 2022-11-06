#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	vector<int>psa(n+1);
	for(int i = 1; i<=n; i++){
		psa[i] = psa[i-1]+arr[i];
	}
	vector<int>b(m+1);
	for(int i = 1; i<=m; i++){
		cin >> b[i];
		b[i]*=4;
	}
	sort(b.begin(),b.end());
	int ans = 0;
	if(true){
		int v = (b[1]-1)/400;
		v++;
		v = min(v,n);
		if(v<=n&&b[1]>0){
			ans = psa[v];
		}
	}
	//cout << ans << "\n";
	if(true){
		int v = b[m]/400+1;
		v++;
		if(v<=n){
			ans = max(ans,psa[n]-psa[v-1]);
		}
	}
	//cout << ans << "\n";
	for(int i = 1; i<m; i++){
		for(int j = b[i]+1; j<b[i+1]; j++){
			int l = (b[i]+j)/2+1;
			int r = (j+b[i+1])/2;
			if(j%2==b[i+1]%2)r--;
			r/=400;
			l--;
			l/=400;
			l++; r++;
			if(r>n){
				r = n;
				if(l<n)ans = max(ans,psa[r]-psa[l]);
				break;
			}
			ans = max(ans,psa[r]-psa[l]);
		}
	}
	cout << ans << "\n";
	return 0;
}