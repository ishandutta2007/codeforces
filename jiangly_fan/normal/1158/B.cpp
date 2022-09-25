#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 120000; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, k;
	cin >> n >> k;
	int a = (n - k) / 2 + 1;
	for(int i = 1; i <= n; i += 1){
		if(i % a) cout << 1;
		else cout << 0;
	}
	return 0;
}