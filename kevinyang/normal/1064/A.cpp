#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	vector<int>arr(3);
	for(int i = 0; i<3; i++){
		cin >> arr[i];
	}
	sort(arr.begin(),arr.end());
	if(arr[0]+arr[1]>arr[2]){
		cout << "0";
		return 0;
	}
	int num = arr[2]-arr[0]-arr[1];
	cout << num+1;
	
	return 0;
}