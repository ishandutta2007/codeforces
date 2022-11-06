#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int a,b,c;
		cin >> a >> b >> c;
		if((a+b+c)%9==0&&(a+b+c)/9<=min({a,b,c})){
			cout << "YEs\n";
		}
		else{
			cout << "No\n";
		}

	}
	return 0;
}