#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	cout << "? 1 " << n << endl;
	int i;
	cin >> i;
	if(n==2){
		if(i==2)cout << "! 1\n";
		else cout << "! 2\n";
		return 0;
	}
	if(i!=1)cout << "? 1 " << i << endl;
	int j = 0;
	if(i!=1)cin >> j;
	if(i==j){
		int low = 0; int high = i; int mid = (low+high)/2;
		while(low+1<high){
			cout <<"? " << mid << " " << i << endl;
			int x;
			cin >> x;
			if(x==i){
				low = mid;
			}
			else{
				high = mid;
			}
			mid = (low+high)/2;
		}
		cout << "! " << low << endl;
	}
	else{
		int low = i; int high = n+1; int mid = (low+high)/2;
		while(low+1<high){
			cout << "? " << i << " " << mid << endl;
			int x;
			cin >> x;
			if(i==x){
				high = mid;
			}
			else{
				low = mid;
			}
			mid = (low+high)/2;
		}
		cout << "! " << high << endl;
	}
	return 0;
}