#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>arr(n+1);
		vector<int>arr2(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		for(int i = 1; i<=n; i++){
			cin >> arr2[i];
		}
		int sum = 0;
		for(int i = 1; i<=n; i++){
			sum+=arr[i];
			sum-=arr2[i];
		}
		if(sum!=0){
			cout << "-1\n";
			continue;
		}
		queue<int>q;
		queue<int>q2;
		for(int i = 1; i<=n; i++){
			while(arr[i]>arr2[i]){
				q.push(i);
				arr[i]--;
			}
			while(arr2[i]>arr[i]){
				q2.push(i);
				arr2[i]--;
			}
		}
		cout << q.size() << "\n";
		while(q.size()){
			cout << q.front() << " " << q2.front() << "\n";
			q.pop(); q2.pop();
		}
	}
	return 0;
}