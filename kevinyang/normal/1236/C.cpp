#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>>arr(n,vector<int>(n));
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if(j%2==0){
				arr[i][j] = i+1 + j*n;
			}
			else{
				arr[i][j] = (j+1)*n-i;
			}
		}
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}