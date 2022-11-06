#include <bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a, int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n);
	vector<int>freq(200001);
	for(int i = 0; i<n; i++){
		cin >> arr[i];
		for(int j = 1; j*j<=arr[i]; j++){
			if(arr[i]%j==0){
				if(j==arr[i]/j){
					freq[j]++;
					continue;
				}
				freq[j]++; freq[arr[i]/j]++;
			}
		}
	}
	int lcm = 1;
	for(int i = 1; i<=200000; i++){
		if(freq[i]>=n-1){
			lcm = lcm*i/gcd(lcm,i);
			//cout << i << "\n";
		}
	}
	cout << lcm << "\n";
	return 0;
}