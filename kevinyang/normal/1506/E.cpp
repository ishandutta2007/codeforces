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
		if(true){
			set<int>s;
			for(int i = 1; i<=n; i++){
				s.insert(i);
			}
			for(int i = 1; i<=n; i++){
				if(s.find(arr[i])!=s.end()){
					s.erase(arr[i]);
					cout << arr[i] << " ";
				}
				else{
					cout << *s.begin() << " ";
					s.erase(s.begin());
				}
			}
			cout << "\n";
		}
		if(true){
			set<int>s;
			for(int i = 1; i<=n; i++){
				s.insert(i);
			}
			for(int i = 1; i<=n; i++){
				cout << *--s.upper_bound(arr[i]) << " ";
				s.erase(--s.upper_bound(arr[i]));
			}
			cout << "\n";
		}
	}
	return 0;
}