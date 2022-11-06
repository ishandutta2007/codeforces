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
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		deque<int>dq;
		dq.push_back(arr[1]);
		for(int i = 2; i<=n; i++){
			if(arr[i]<dq[0]){
				dq.push_front(arr[i]);
			}
			else{
				dq.push_back(arr[i]);
			}
		}
		for(int nxt: dq){
			cout << nxt << " ";
		}
		cout << "\n";
	}
	return 0;
}