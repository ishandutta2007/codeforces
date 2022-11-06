#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>>arr(n,vector<int>(n));
	vector<int>powers(53); powers[0] = 1;
	for(int i = 1; i<=52; i++){
		powers[i] = powers[i-1]*2;
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if(i%2==1){
				arr[i][j] = powers[i+j];
			}
		}
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	int q;
	cin >> q;
	while(q--){
		int sum;
		cin >> sum;
		vector<int>ans;
		for(int i = 1; i<2*n-1; i++){
			if(sum&powers[i]){
				ans.push_back(1);
			}
			else{
				ans.push_back(0);
			}
		}
		cout << "1 1" << endl;
		int curx = 1; int cury = 1;
		for(int nxt:ans){
			if((curx+1)%2==nxt)cury++;
			else curx++;
			cout << curx << " " << cury << endl;
		}
	}
	return 0;
}