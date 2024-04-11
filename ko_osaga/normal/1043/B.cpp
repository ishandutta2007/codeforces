#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 100005;

int n, a[MAXN];

int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	for(int i=n; i; i--) a[i] -= a[i-1];
	vector<int> ans;
	for(int i=1; i<=n; i++){
		bool ok = true;
		for(int j=i+1; j<=n; j++){
			if(a[j] != a[j - i]) ok = false;
		}
		if(ok) ans.push_back(i);
	}
	cout << ans.size() << endl;
	for(auto &i : ans) cout << i << " ";
}