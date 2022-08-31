#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int MAXN = 1000005;

int n, a[MAXN], psum[MAXN];
int cnt[2];

lint bino(int x){
	return 1ll * x * (x - 1) / 2;
}

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		lint x;
		scanf("%lld",&x);
		while(x){
			if(x & 1) a[i]++;
			x >>= 1;
		}
	}
	for(int i=1; i<=n; i++){
		psum[i] = psum[i-1] + a[i];
	}
	for(int i=0; i<=n; i++) cnt[psum[i]%2]++;
	lint gibon = bino(cnt[0]) + bino(cnt[1]);
	for(int i=1; i<=n; i++){
		int mx = 0, sum = 0;
		for(int j=i; j<=n && j<=i+200; j++){
			sum += a[j];
			mx = max(mx, a[j]);
			if(sum % 2 == 0 && mx > sum - mx){
				gibon--;
			}
		}
	}
	cout << gibon << endl;
}