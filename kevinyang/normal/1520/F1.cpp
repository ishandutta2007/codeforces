#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,t;
	cin >> n >> t;
	int k;
	cin >> k;
	int low = 0; int high = n; int mid = (low+high)/2;
	while(low+1<high){
		cout << "? 1 " << mid << endl;
		int x;
		cin >> x;
		if(mid-x>=k)high = mid;
		else low = mid;
		mid = (low+high)/2;
	}
	cout << "! " << high << endl;
	return 0;
}