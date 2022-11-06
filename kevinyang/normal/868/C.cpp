#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	vector<int>freq(1<<k);
	for(int i = 0; i<n; i++){
		int v = 0;
		for(int j = 0; j<k; j++){
			int x;
			cin >> x;
			if(x==1)v+=(1<<j);
		}
		freq[v]++;
	}
	bool f = false;
	if(freq[0]>0)f = true;
	for(int i = 1; i<(1<<k); i++){
		for(int j = 1; j<(1<<k); j++){
			if((i&j)==0&&freq[i]>0&&freq[j]>0){
				f = true;
			}
		}
	}
	if(f)cout << "YES\n";
	else cout << "NO\n";
	return 0;
}