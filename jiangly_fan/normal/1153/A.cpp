#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
	LL n, t, ans = 1e18, ansi = 0;
	cin >> n >> t;
	for(int i = 1; i <= n; i += 1){
		LL s, d;
		cin >> s >> d;
		while(s < t) s += d;
		if(s < ans) ans = s, ansi = i;
	}
	cout << ansi;
}