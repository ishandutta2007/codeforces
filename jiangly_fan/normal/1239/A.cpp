//Author: HeXun
//Date: 10-20-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T& s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 120000;
constexpr LL mod = 1000000007;
LL f[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	f[1] = 2;
	f[2] = 4;
	for(int i = 3; i < maxn; i += 1) f[i] = (f[i - 1] + f[i - 2]) % mod;
	int n, m;
	cin >> n >> m;
	cout << (f[n] + f[m] + mod - 2) % mod;
	return 0;
}