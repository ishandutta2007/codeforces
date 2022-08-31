#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n, m, a[111], chk[111];

int main(){
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=m; i++){
		int x; cin >> x;
		chk[x] =1;
	}
	lint ret = 0;
	vector<int> chked;
	for(int i=1; i<=n; i++){
		if(!chk[i]) ret += a[i];
		else chked.push_back(a[i]);
	}
	sort(chked.begin(), chked.end());
	lint dap = 0;
	for(int i=0; i<=chked.size(); i++){
		lint cur = ret;
		for(int j=i; j<chked.size(); j++){
			cur += chked[j];
		}
		for(int j=0; j<i; j++){
			if(chked[j] <= cur) cur *= 2;
		}
		dap = max(dap, cur);
	}
	cout << dap;
}