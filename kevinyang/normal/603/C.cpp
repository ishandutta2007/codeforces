#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	if(k%2==1){
		int sum = 0;
		for(int i = 1; i<=n; i++){
			if(arr[i]==2)continue;
			if(arr[i]==1||arr[i]==3){
				sum^=1;
				continue;
			}
			if(arr[i]%2==1)continue;
			int cnt = 0;
			while(arr[i]%2==0){
				arr[i]/=2;
				cnt++;
			}
			int v = 1;
			if(cnt%2==0)v++;
			if(arr[i]==3)v^=3;
			sum^=v;
		}
		if(sum==0)cout << "Nicky\n";
		else cout << "Kevin\n";
	}
	else{
		int total = 0;
		for(int i = 1; i<=n; i++){
			if(arr[i]==1||(arr[i]%2==0&&arr[i]>2))total^=1;
			if(arr[i]==2)total^=2;
		}
		if(total==0){
			cout << "Nicky\n";
		}
		else{
			cout << "Kevin\n";
		}
	}
	return 0;
}