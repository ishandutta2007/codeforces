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
		vector<int>arr(n); int sum = 0;
		for(int i = 0; i<n; i++){
			cin >> arr[i]; sum+=arr[i];
		}
		for(int i = 0; i<n; i++){
			int x = 1;
			while(2*x<=(int)1e9){
				if(x*2>=arr[i]){
					if(abs(2*x-arr[i])<abs(x-arr[i])){
						cout << 2*x << " ";
					}
					else{
						cout << x << " ";
					}
					break;
				}
				x*=2;
			}
			if(x>=(int)5e8){
				cout << x << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}