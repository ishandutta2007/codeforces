#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<int>arr(n);
	vector<int>arr2(m);
	for(int i = 0; i<n; i++)
		cin >> arr[i];
	for(int i = 0; i<m; i++)
		cin >> arr2[i];
	for(int i = 0; i<512; i++){
		bool f = true;
		for(int j = 0; j<n; j++){
			bool ff = false;
			for(int k = 0; k<m; k++){
				if((i|(arr[j]&arr2[k]))==i)ff = true;
			}
			if(!ff)f = false;
		}
		if(f){
			cout << i << "\n";
			return 0;
		}
	}
	return 0;
}