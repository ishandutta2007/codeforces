#include <bits/stdc++.h>
using namespace std;
#define int long long
int f(int x, int y, int k){
	vector<int>a(20);
	vector<int>b(20);
	for(int i = 0; i<20; i++){
		a[i] = x%k;
		x/=k;
		b[i] = y%k;
		y/=k;
	}
	int ans = 0;
	for(int i = 19; i>=0; i--){
		int v = a[i]+b[i]; v%=k;
		ans*=k; ans+=v;
	}
	return ans;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	//cout << f(1,2,2) << " " << f(6,8,2) << " " << f(1,3,2) << "\n";
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		int cur = 0;
		for(int i = 0; i<n; i++){
			cout << f(i,cur,k) << endl;
			int r;
			cin >> r;
			if(r==1)break;
			else cur = f(cur,f(i,cur,k),k);
		}

	}
	return 0;
}