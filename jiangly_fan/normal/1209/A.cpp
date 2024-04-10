//Author: HeXun
//Date: 09-14-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 120;
int cnt[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		int a;
		cin >> a;
		cnt[a] += 1;
	}
	int ans = 0;
	for(int i = 1; i <= 100; i += 1){
		if(cnt[i]){
			ans += 1;
			for(int j = i; j <= 100; j += i) cnt[j] = 0;
		}
	}
	cout << ans;
	return 0;
}