#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		int arr[n][n];
		int zeroes = n*n-k;
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				arr[i][j] = 1;
			}
		}
		//cerr << "yeet\n";
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				if(zeroes<=0)break;
				zeroes--;
				arr[j][(j+i)%n] = 0;
			}
		}
		//cerr <<"yeet\n";
		int minr = n; int maxr = 0;
		for(int i = 0; i<n; i++){
			int count = 0;
			for(int j = 0; j<n; j++){
				count+=arr[i][j];
			}
			minr = min(minr,count); maxr = max(maxr,count);
		}
		//cerr <<"yeet\n";
		int minc = n; int maxc = 0;
		for(int j = 0; j<n; j++){
			int count = 0;
			for(int i = 0; i<n; i++){
				count+=arr[i][j];
			}
			minc = min(minc,count); maxc = max(maxc,count);
		}
		//cerr <<"yeet\n";
		cout << (maxr-minr)*(maxr-minr)+(maxc-minc)*(maxc-minc) << "\n";
		//cerr <<"yeet\n";
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				cout << arr[i][j];
			}
			cout << "\n";
		}
		//cerr <<"yeet\n";
	}
	return 0;
}