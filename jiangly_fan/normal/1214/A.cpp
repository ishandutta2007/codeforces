//Author: HeXun
//Date: 09-04-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 1000000;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	LL n, d, e;
	cin >> n >> d >> e;
	e *= 5;
	LL ans = n;
	for(int i = 0; i < maxn and d * i <= n; i += 1){
		ans = min(ans, (n - d * i) % e);
	}
	cout << ans;
	return 0;
}