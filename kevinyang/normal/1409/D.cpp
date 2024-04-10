#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		string n;
		int s;
		cin >> n >> s;
		vector<int>arr(n.length()+1);
		int sum = 0;
		for(int i = 1; i<=n.length(); i++){
			arr[i] = (int)(n[i-1]-'0');
			sum+=arr[i];
		}
		if(sum<=s){
			cout << "0\n";
			continue;
		}
		for(int i = arr.size()-2; i>=0; i--){
			sum = 1;
			for(int j = 0; j<=i; j++){
				sum+=arr[j];
			}
			if(sum<=s){
				int num1 = 0;
				int num2 = 0;
				for(int j = 0; j<arr.size(); j++){
					num1*=10;num2*=10;
					if(j<=i)num1+=arr[j];
					if(j==i)num1++;
					num2+=arr[j];
				}
				cout << num1-num2 << "\n";
				break;
			}
		}
	}
	return 0;
}