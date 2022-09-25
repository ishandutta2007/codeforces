//Author: HeXun
//Date: 09-04-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int b, g, n;
	cin >> b >> g >> n;
	int ans = 0;
	for(int i = 0; i <= b and i <= n; i += 1)
		if(n - i <= g) ans += 1;
	cout << ans;
	return 0;
}