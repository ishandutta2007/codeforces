//Author: HeXun
//Date: 08-25-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 2400;
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n, ans = maxn;
	cin >> n;
	for(int i = 1; i <= n; i += 1) cin >> a[i];
	for(int i = 0; i <= n; i += 1){
		set<int> s;
		for(int j = 1; j <= i; j += 1) s.insert(a[j]);
		if((int)s.size() < i) break;
		else{
			ans = min(ans, n - i);
		}
		for(int k = n; k >= i + 1; k -= 1){
			s.insert(a[k]);
			if((int)s.size() < i + n - k + 1) break;
			ans = min(ans, n - i - (n - k + 1));
		}
	}
	cout << ans;
	return 0;
}