#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<long long>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	vector<long long>psa(n+1);
	for(int i = 1; i<=n; i++){
		psa[i] = psa[i-1]+arr[i];
	}
	map<long long, long long>hm;
	hm[0] = 1;
	int pointer = 0;
	long long ans = 0;
	for(int i = 1; i<=n; i++){
		long long sum = psa[i];
		if(hm[sum]<pointer){
			ans+=(i-pointer);
		}
		else{
			pointer = hm[sum];
			ans+=(i-pointer);
		}
		hm[sum] = i+1;
	}
	cout << ans << "\n";
	return 0;
}