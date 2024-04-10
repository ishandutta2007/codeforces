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
		string s;
		cin >> s;
		int even = 0; int odd = 0;
		if(n%2==1){
			for(int i = 0; i<n; i+=2){
				if((int)s[i]%2==1)odd++;
			}
			if(odd)cout << "1\n";
			else cout << "2\n";
		}
		else{
			for(int i = 1; i<n; i+=2){
				if((int)s[i]%2==0)even++;
			}
			if(even)cout << "2\n";
			else cout << "1\n";
		}
	}
	return 0;
}