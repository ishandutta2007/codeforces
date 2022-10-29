#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int a[MAXN];

int main(){
	int n;
	long long A;
	cin>>n>>A;
	long long s = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		s += a[i];
	}
	for(int i = 1; i <= n; i++){
		long long now = s - a[i];
		long long minx = max(1LL, A - now), maxx = min(a[i] * 1LL, A - n + 1);
		printf("%lld%c", a[i] - (maxx - minx + 1), " \n"[i == n]);
	}
	return 0;
}