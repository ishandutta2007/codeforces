#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	int rec = 0;
	int sq = 0;
	vector<int>arr(100001);
	for(int i = 0; i<n; i++){
		int x;
		cin >> x;
		arr[x]++;
		if(arr[x]%4==2){
			rec++;
		}
		else if(arr[x]%4==0){
			sq++;
			rec--;
		}
	}
	int q;
	cin >> q;
	while(q--){
		char ch;
		cin >> ch;
		int val;
		cin >> val;
		if(ch=='+'){
			arr[val]++;
			if(arr[val]%4==2){
				rec++;
			}
			else if(arr[val]%4==0){
				sq++;
				rec--;
			}
		}
		else{
			arr[val]--;
			if(arr[val]%4==3){
				rec++;
				sq--;
			}
			else if(arr[val]%4==1){
				rec--;
			}
		}
		if(sq>=1&&rec>=2){
			cout << "Yes\n";
		}
		else if(sq>=2){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
	return 0;
}