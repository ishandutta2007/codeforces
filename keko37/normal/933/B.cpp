#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long llint;

llint p, k;
vector <llint> v, sol;

int main () {
	cin >> p >> k;
	if (p<k) {
		cout << 1 << endl << p;
		return 0;
	}
	llint val=p;
	for (int i=0; 1<=1; i++) {
		llint novi=(k-val)/k;
		if (k-val<=0) novi--;
		if (novi>0 && novi*k==k-val) novi--;
		val=novi;
		v.push_back(val);
		if (0<val && val<k) break;
	}
	reverse(v.begin(), v.end());
	sol.push_back(v[0]);
	for (int i=1; i<v.size(); i++) {
		sol.push_back(v[i]+v[i-1]*k);
	}
	sol.push_back(v.back()*k+p);
	cout << sol.size() << endl;
	for (int i=sol.size()-1; i>=0; i--) {
		cout << sol[i] << " ";
	}
	return 0;
}