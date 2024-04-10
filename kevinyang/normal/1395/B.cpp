#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m,x,y;
	cin >> n >> m >> x >> y;
	if(y!=1){
		cout << x << " " << y << "\n";
	}
	cout << x << " 1\n";
	for(int i = 2; i<=m; i++){
		if(i!=y){
			cout << x << " " << i << "\n";
		}
	}
	for(int i = x-1; i>=1; i--){
		if((x-i)%2==1){
			for(int j = m; j>=1; j--){
				cout << i << " " << j << "\n";
			}
		}
		else{
			for(int j = 1; j<=m; j++){
				cout << i << " " << j << "\n";
			}
		}
	}
	int add = x-1;
	for(int i = x+1; i<=n; i++){
		if((i-x+add)%2==1){
			for(int j = m; j>=1; j--){
				cout << i << " " << j << "\n";
			}
		}
		else{
			for(int j = 1; j<=m; j++){
				cout << i << " " << j << "\n";
			}
		}
	}
	return 0;
}