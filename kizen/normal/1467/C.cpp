#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long A, B, C, ans = 0;
	cin >> A >> B >> C;
	vector<long long> a(A), b(B), c(C);
	long long all = 0;
	for(long long i = 0; i < A; ++i){
		cin >> a[i]; all += a[i];
	}
	sort(a.begin(), a.end());
	for(long long i = 0; i < B; ++i){
		cin >> b[i]; all += b[i];
	}
	sort(b.begin(), b.end());
	for(long long i = 0; i < C; ++i){
		cin >> c[i]; all += c[i];
	}
	sort(c.begin(), c.end());
	long long low = (long long)1e9, sum = 0;
	for(long long i = 0; i < B; ++i) sum += b[i];
	low = min(low, sum);
	sum = 0;
	for(long long i = 0; i < C; ++i) sum += c[i];
	low = min(low, sum);
	low = min(low, b[0] + c[0]);
	if(A >= 2) low = min(low, a[0] + b[0]), low = min(low, a[0] + c[0]);
	ans = max(ans, all - low * 2);

	swap(A, B), swap(a, b);
	low = (long long)1e9, sum = 0;
	for(long long i = 0; i < B; ++i) sum += b[i];
	low = min(low, sum);
	sum = 0;
	for(long long i = 0; i < C; ++i) sum += c[i];
	low = min(low, sum);
	low = min(low, b[0] + c[0]);
	if(A >= 2) low = min(low, a[0] + b[0]), low = min(low, a[0] + c[0]);
	ans = max(ans, all - low * 2);

	swap(A, C), swap(a, c);
	low = (long long)1e9, sum = 0;
	for(long long i = 0; i < B; ++i) sum += b[i];
	low = min(low, sum);
	sum = 0;
	for(long long i = 0; i < C; ++i) sum += c[i];
	low = min(low, sum);
	low = min(low, b[0] + c[0]);
	if(A >= 2) low = min(low, a[0] + b[0]), low = min(low, a[0] + c[0]);
	ans = max(ans, all - low * 2);

	cout << ans;
	return 0;
}