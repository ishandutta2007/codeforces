#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		for(int i = 1; i<=8; i++){
			if(i%2==0){
				for(int j = 8; j>=1; j--){
					cout << i << " " << j << endl;
					string s;
					cin >> s;
					if(s=="Done")goto L;
				}
			}
			else{
				for(int j = 1; j<=8; j++){
					cout << i << " " << j << endl;
					string s;
					cin >> s;
					if(s=="Done")goto L;
				}
			}
		}
		for(int i = 1; i<=8; i++){
			if(i%2==0){
				for(int j = 8; j>=1; j--){
					cout << i << " " << j << endl;
					string s;
					cin >> s;
					if(s=="Done")goto L;
				}
			}
			else{
				for(int j = 1; j<=8; j++){
					cout << i << " " << j << endl;
					string s;
					cin >> s;
					if(s=="Done")goto L;
				}
			}
		}
		L:{

		}
	}
	return 0;
}