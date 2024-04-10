#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n,h;
	cin >> n >> h;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int ans=0;
	for(int i=0;i<n;i++){
		vector<int> b;
		for(int u=0;u<=i;u++){
			b.push_back(a[u]);
		}
		sort(b.rbegin(),b.rend());
		int x=h;
		int s=b.size();
		if (b.size()%2 == 1){
			x-=b[s-1];
		}
		for(int ii=0;ii<s/2;ii++){
			x -= max(b[ii*2],b[ii*2+1]);
		}
		if (x<0){
			break;
		}
		else{
			ans = i+1;
		}
	}
	cout << ans;
	
}