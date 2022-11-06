#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n+1);
	vector<int>cnt(n+1);
	vector<int>freq(100);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
		int k = arr[i];
		while(k%2==0){
			cnt[i]++;
			k/=2;
		}
		freq[cnt[i]]++;
	}
	int mx = 0;
	int val = 0;
	for(int i = 0; i<100; i++){
		if(freq[i]>mx){
			mx = freq[i]; val = i;
		}
	}
	cout << n-mx << "\n";
	for(int i = 1; i<=n; i++){
		if(cnt[i]!=val){
			cout << arr[i] << " ";
		}
	}
	cout << "\n";
	return 0;
}