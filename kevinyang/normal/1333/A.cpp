#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		if(m%2==1&n%2==1){
			for(int i = 0; i<n; i++){
				for(int j = 0; j<m; j++){
					if((i+j)%2==0){
						cout << "B";
					}
					else{
						cout << "W";
					}
				}
				cout << "\n";
			}
		}
		else{
			bool f = true;
			for(int i = 0; i<n; i++){
				for(int j = 0; j<m; j++){
					if((i+j)%2==0){
						cout << "B";
					}
					else{
						if(f){
							cout << "B";
							f = false;
						}
						else cout << "W";
					}
				}
				cout << "\n";
			}
		}
	}
	return 0;
}