#include <bits/stdc++.h>
const int MAXN = 300005;
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const lint mod1 = 1e12 + 409;
const lint mod2 = 1e12 + 433;

int n, cnt[MAXN], moe[MAXN];
lint ret1[111], ret2[2111];
int gcd(int x, int y){
	return y ? gcd(y, x%y) : x;
}

int main(){
	scanf("%d",&n);
	int g = 0;
	for(int i=0; i<n; i++){ 
		int x;
		scanf("%d",&x);
		cnt[x]=1;
		g = gcd(x, g);
	}
	if(cnt[1]){
		puts("1");
		return 0;
	}
	if(g != 1){
		puts("-1");
		return 0;
	}
	moe[1] = 1;
	for(int i=1; i<=300000; i++){
		for(int j=2*i; j<=300000; j+=i) moe[j] -= moe[i];
	}
	lint ret = 0;
	for(int i=1; i<=300000; i++){
		int ans = 0;
		for(int j=i; j<=300000; j+=i) ans += cnt[j];
		lint cnt1 = ans, cnt2 = ans;
		for(int j=2; j<=8; j++){
			cnt1 *= ans;
			cnt1 %= mod1;
			cnt2 *= ans;
			cnt2 *= mod2;
			ret1[j] += cnt1 * moe[i];
			ret2[j] += cnt2 * moe[i];
		}
	}
	for(int i=2; i<=8; i++){
		if(ret1[i] % mod1 || ret2[i] % mod2){
			cout << i << endl;
			return 0;
		}
	}
	assert(0);
}