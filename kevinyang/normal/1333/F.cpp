#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>high(500001);
bool comp(int a, int b){
	if(high[a]==high[b])return a<b;
	return high[a]<high[b];
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n+1);
	for(int i = 2; i<=n; i++){
		for(int j = 2*i; j<=n; j+=i){
			high[j] = max(high[j],i);
		}
	}
	for(int i = 1; i<=n; i++){
		arr[i] = i;
	}
	sort(arr.begin(),arr.end(),comp);
	for(int i = 2; i<=n; i++){
		int v = high[arr[i]];
		if(v==0)cout << "1 ";
		else cout << v << " ";
	}
	cout << "\n";
	return 0;
}