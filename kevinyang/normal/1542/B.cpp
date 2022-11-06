#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,a,b;
		cin >> n >> a >> b;
		int cur = 1;
		bool f = false;
		if(a==1){
			if((n-1)%b==0){
				f = true;
			}
		}	
		else{
			while(cur<=n){
				if((n-cur)%b==0){
					f = true;
				}
				cur*=a;
			}
		}
		
		if(f)cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}