#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int r,c;
	cin >> r >> c;
	vector<vector<int>>ans(r,vector<int>(c));
	if(r+c==2){
		cout << "0\n";
		return 0;
	}
	int low = 2;
	ans[0][0] = low;
	if(r<=c){
		for(int i = 1; i<r; i++){
			ans[i][0] = (i+1)*low;
		}
		for(int i = 1; i<c; i++){
			if(i>r){
				ans[0][i] = ans[0][i-1]+1;
				continue;
			}
			ans[0][i] = (i+1)*low-1;

		}
	}
	else{
		for(int i = 1; i<c; i++){
			ans[0][i] = (i+1)*low;
		}
		for(int i = 1; i<r; i++){
			if(i>c){
				ans[i][0] = ans[i-1][0] +1;
				continue;
			}
			ans[i][0] = (i+1)*low-1;
		}
	}
	for(int i = 1; i<r; i++){
		for(int j = 1; j<c; j++){
			ans[i][j] = ans[i][0]*ans[0][j];
		}
	}
	for(int i = 0; i<r; i++){
		for(int j = 0; j<c; j++){
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}