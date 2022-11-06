#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n);
	int start = 0;
	for(int i = 0; i<n; i++){
		cin >> arr[i];
		if(arr[i]==n)start = i;
	}	
	int l = start-1; int r = start+1;
	for(int i = n-1; i>0; i--){
		bool f = false;
		if(l>=0){
			if(arr[l]==i){
				l--;
				f = true;
			}
		}
		if(r<n){
			if(arr[r]==i){
				r++;
				f = true;
			}
		}
		if(!f){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}