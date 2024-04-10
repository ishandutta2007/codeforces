//Author: Heltion
//Date: 2019-06-06
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
int a[maxn], b[maxn];
int ca[maxn], n;
int q[maxn * 4], qh, qt;
int check(){
	int res = 0;
	while(true){
		if(q[qt - 1] == n) break;
		if(not ca[q[qt - 1] + 1]) return -1;
		ca[q[qt - 1] + 1] -= 1;
		q[qt] = q[qt - 1] + 1; qt ++;
		ca[q[qh ++]] += 1;
		res += 1;
	}
	for(int i = qh; ~res and i < qt; i += 1)
		if(q[i] != i - qh + 1) res = -1;
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout<<fixed<<setprecision(12);
	cin >> n;
	int ans, L = 0, R = 2 * n;
	for(int i = 1; i <= n; i += 1) cin >> a[i];
	for(int i = 1; i <= n; i += 1) cin >> b[i];
	for(int i = 1; i <= n; i += 1) ca[a[i]] += 1;
	qh = qt = 0;
	for(int i = 1; i <= n; i += 1) q[qt ++] = b[i];
	ans = check();
	if(ans == -1) ans = 1e9;
	while(L < R){
		int M = (L + R) >> 1;
		for(int i = 0; i <= n; i += 1) ca[i] = 0;
		for(int i = 1; i <= n; i += 1) ca[a[i]] += 1;
		qh = qt = 0;
		for(int i = 1; i <= n; i += 1) q[qt ++] = b[i];
		for(int i = 0; i < M; i += 1)
			if(ca[0]){
				q[qt ++] = 0;
				ca[q[qh ++]] += 1;
			}
		if(~check()) R = M;
		else L = M + 1;
	}
	cout << min(ans, L + n);
	return 0;
}