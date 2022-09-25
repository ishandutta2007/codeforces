//Author: Hexun
//Date: 2019-04-29
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100;
int c[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1, a; i <= n; i += 1){
		cin >> a;
		c[a] += 1;
	}
	if(c[2]){
		cout << "2 ";
		c[2] -= 1;
		if(c[1]){
			cout << "1 ";
			c[1] -= 1;
		}
		for(int i = 0; i < c[2]; i += 1) cout << "2 ";
		for(int i = 0; i < c[1]; i += 1) cout << "1 ";
	}
	else for(int i = 0; i < n; i += 1) cout << "1 ";
	return 0;
}