#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	int low = 1; int high = n; int mid = (low+high)/2;
	int cur = 0;
	while(low+1<high){
		int v = (mid+cur)%n;
		assert(v!=0);
		int add = n-v;
		cur+=add;
		cout << "+ " << add << endl;
		cin >> v;
		if(v==(cur+mid)/n)low = mid;
		else high = mid;
		mid = (low+high)/2;
	}
	cout << "! " << low+cur << endl;
	return 0;
}