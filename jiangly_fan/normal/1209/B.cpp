//Author: HeXun
//Date: 09-14-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 120;
char s[maxn];
int a[maxn], b[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n;
	cin >> n;
	cin >> (s + 1);
	for(int i = 1; i <= n; i += 1) cin >> a[i] >> b[i];
	int ans = 0;
	for(int i = 0; i <= 1000; i += 1){
		int pans = 0;
		for(int j = 1; j <= n; j += 1) if(i >= b[j] and (i - b[j]) % a[j] == 0) s[j] = '0' + '1' - s[j];
		for(int j = 1; j <= n; j += 1) pans += s[j] == '1';
		ans = max(pans, ans);
	}
	cout << ans;
	return 0;
}