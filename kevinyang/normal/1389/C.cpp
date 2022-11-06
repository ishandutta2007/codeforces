#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int mn = s.length()-2;
		int n = s.length();
		vector<int>arr(n);
		for(int i = 0; i<n; i++){
			arr[i] = (int)s[i]-'0';
		}
		for(int i = 0; i<10; i++){
			int count = 0;
			for(int j = 0; j<n; j++){
				if(arr[j]!=i){
					count++;
				}
			}
			mn = min(mn,count);
		}
		//cout << mn << "\n";
		for(int i = 0; i<10; i++){
			for(int j = 0; j<10; j++){
				if(i==j)continue;
				int count = 0;
				for(int l = 0; l<n; l++){
					if(count%2==0&&arr[l]==i){
						count++;
					}
					else if(count%2==1&&arr[l]==j){
						count++;
					}
				}
				count/=2;
				count*=2;
				mn = min(mn,n-count);
			}
		}
		cout << mn << "\n";
	}
	return 0;
}