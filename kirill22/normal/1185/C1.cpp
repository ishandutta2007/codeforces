#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	   int n, m;
	   cin >> n >> m;
	   vector<int> a(n);
	   vector<int> pref(n + 1,0);
	   for(int i = 0;i < n;i++){
	   	 cin >> a[i];
	   	 pref[i + 1] = pref[i] + a[i];
	   }
	   int k = 0;
	   for(int i = 0;i < n;i++) {
		   	int x = pref[i + 1];
		   	vector<int> b;
		   	for(int j = 0;j < i;j++){
		   		b.push_back(a[j]);
		   	}
		   	sort(b.begin(),b.end());
		   	int k = 0;
		   	while(x > m){
		   		x -= b[b.size() - 1];
		   		b.pop_back();
		   		k++;
		   	}
		   	cout << k << " ";
		   	
		   	
	   }
}