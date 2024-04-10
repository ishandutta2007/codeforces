#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n,b,a;
	cin >>  n >> b >> a;
	int ans = 0;
	vector<int> m(n);
	for(int i=0;i<n;i++){
		cin >> m[i];
	}
	int tmp1=b,tmp2=a;
	for(int  i=0;i<n;i++){
		if (m[i] == 1){
			if (tmp1 == 0){
				if (tmp2  > 0){
					tmp2--;
					ans++;
				}
				else{
					cout << ans;
					return 0;
				}
			}
			else{
				if (tmp2 < a){
					tmp1 --;
					tmp2++;
					ans++;
				}
				else{
					tmp2--;
					ans++;
				}
			}
		}
		else{
			if(tmp2 > 0){
				tmp2--;
				ans++;
			}
			else{
				if(tmp1 == 0){
					cout << ans;
					return 0;
				}
				else{
					tmp1--;
					ans++;
				}
			}
		}
	}
	cout << ans;
	return 0;
	
	
}