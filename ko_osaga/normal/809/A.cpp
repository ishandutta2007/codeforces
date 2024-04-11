#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const int mod = 1e9 + 7;

int n, a[300005];

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	sort(a, a+n);
	lint p = 1;
	lint ret = 0;
	for(int i=0; i<n; i++){
		ret += a[i] * p % mod;
		p = (p << 1) % mod;
	}
	p = 1;
	for(int i=n-1; i>=0; i--){
		ret += mod - a[i] * p % mod;
		p = (p << 1) % mod;
	}
	ret %= mod;
	cout << ret;
}