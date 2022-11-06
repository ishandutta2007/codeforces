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
		vector<vector<char>>arr(n,vector<char>(n));
		int a = 0; int b = 0; int c = 0;
		for(int i = 0; i<n; i++){
			string s;
			cin >> s;
			for(int j = 0; j<n; j++){
				arr[i][j] = s[j];
				if(s[j]=='X'){
					int val = (i+j)%3;
					if(val==0)a++;
					if(val==1)b++;
					if(val==2)c++;
				}
			}
		}
		int choice = 0;
		if(b<=c&&b<=a){
			choice = 1;
		}
		if(c<=a&&c<=b){
			choice = 2;
		}
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				if(arr[i][j]=='X'&&(i+j)%3==choice){
					cout << 'O';
				}
				else{
					cout << arr[i][j];
				}
			}
			cout << "\n";
		}
	}
	return 0;
}