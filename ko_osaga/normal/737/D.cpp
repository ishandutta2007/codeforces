#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int n, a[4005];
int d1[4005][129][105];
int d2[4005][129][105];
int f1(int l, int d, int x);
int f2(int l, int d, int x);

int f2(int l, int d, int x){
	if(l + l + d > n) return 1e9;
	if(~d1[l][d+64][x]) return d1[l][d+64][x];
	int ret = max(-f1(l, d+x, x) + a[n-l-d] - a[n-x-l-d],
			-f1(l, d+x+1, x+1) + a[n-l-d] - a[n-x-1-l-d]);
	if(ret < -5e8) ret = 0;
	return d1[l][d + 64][x] = ret;
}

int f1(int l, int d, int x){
	if(l + l + d > n) return 1e9;
	if(~d2[l][d+64][x]) return d2[l][d+64][x];
	int ret = max(-f2(l+x, d-x, x) + a[l+x] - a[l],
			-f2(l+x+1, d-x-1, x+1) + a[l+x+1] - a[l]);
	if(ret < -5e8) ret = 0;
	return d2[l][d + 64][x] = ret;
}

int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		a[i] += a[i-1];
	}
	memset(d1, -1, sizeof(d1));
	memset(d2, -1, sizeof(d2));
	cout << f1(0, 0, 1);
}