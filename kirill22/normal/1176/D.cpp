#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n = 3000001;
	vector<int> pr;
	vector<int> p(n + 1, 0);
	for(int i = 2;i <= n;i++) {
	    if(p[i] == 0) {
	        p[i] = i;
	        pr.push_back(i);
	    }
	    for(int x = 0;x < pr.size();x++) {
	        if(i * pr[x] > n || pr[x] > p[i]) {
	            break;
	        }
	        p[i * pr[x]] = pr[x];
	    }
	}
	cin >> n;
	map<int,int> a;
	vector<int> ans;
	vector<int> b(2 * n);
	for(int i = 0;i < 2 * n;i++){
		cin >> b[i];
		a[b[i]]++;
	}
	sort(b.begin(), b.end());
	for(int i = n * 2 - 1;i >= 0;i--){
		int ii = b[i];
		if(p[ii] != ii && a[ii] > 0){
			ans.push_back(ii);
			a[ii]--;
			a[ii / p[ii]]--;
		}
	}
	for(int i = 0;i < 2 * n;i++){
		int ii = b[i];
		if(p[ii] == ii && a[ii] > 0){
			ans.push_back(ii);
			a[ii]--;
			a[pr[ii - 1]]--;
		}
	}
	for(int i = 0;i < ans.size();i++){
		cout << ans[i] << " ";
	}
}