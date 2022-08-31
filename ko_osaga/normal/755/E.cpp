#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<lint, lint> pi;

int main(){
	int n, k;
	cin >> n >> k;
	if(n <= 3 || k >= 4){
		cout << -1;
		return 0;
	}
	if(k == 1){
		cout << -1;
		return 0;
	}
	if(k == 2){
		if(n == 4){
			cout << -1;
			return 0;
		}
		printf("%d\n", n);
		for(int i=1; i<=n; i++){
			printf("%d %d\n", i, (i + 1 > n ? 1 : (i+1)));
		}
		return 0;
	}
	vector<pi> v;
	v.push_back({1, 2});
	v.push_back({2, 3});
	v.push_back({3, 4});
	for(int i=2; i<=3; i++){
		for(int j=5; j<=n; j++){
			v.push_back({i, j});
		}
	}
	cout << v.size();
	puts("");
	for(auto &i : v){
		cout << i.first << " " << i.second << endl;
	}
}