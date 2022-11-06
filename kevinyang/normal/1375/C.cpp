#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>arr(n);
		vector<int>left(n);//num that is to the left or right
		vector<int>right(n);
		vector<int>index(n+1);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
			index[arr[i]] = i;
			if(i>0){
				left[i] = arr[i-1];
				right[i-1] = arr[i];
			}
		}
		int end = arr[0];
		bool f = true;
		for(int i = 1; i<end; i++){
			int idx = index[i];
			//cout << right[idx] << "\n";
			if(right[idx]>i){
				left[index[right[idx]]] = left[idx];
				right[index[left[idx]]] = right[idx];
			}
			else{
				f = false;
			}
		}
		if(!f){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}
	return 0;
}