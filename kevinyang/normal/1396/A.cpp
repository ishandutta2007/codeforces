#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n);
	for(int i = 0; i<n; i++){
		cin >> arr[i];
	}
	//make everything divisible by n+1
	if(n==1){
		cout << "1 1\n";
		cout << "0\n";
	}
	else{
		cout << "1 " << n-1 << "\n";
		for(int i = 0; i<n-1; i++){
			int a = arr[i]%(n);
			cout << a*(n-1) << " ";
			arr[i]+=a*(n-1);
		}
		cout << "\n";
	}
	cout << n << " " << n << "\n";
	cout << n-arr[n-1] << "\n";
	arr[n-1] += n-arr[n-1];
	cout << "1 " << n << "\n";
	for(int i = 0; i<n; i++){
		cout << arr[i]*-1 << " ";
	}
	cout << "\n";
	return 0;
}