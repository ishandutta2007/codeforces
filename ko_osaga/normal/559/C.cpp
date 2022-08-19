#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int,int> pi;
typedef long long lint;
const int mod = 1e9 + 7;

vector<int> vx, vy;
lint fac[200005], invf[200005];

lint pw(int x, int y){
	lint piv = x, ret = 1;
	while(y){
		if(y&1) ret *= piv;																
		piv *= piv;
		ret %= mod;
		piv %= mod;
		y >>= 1;
	}
	return ret;
}

int h, w, n;
pi a[2005];

lint dp[2005];

lint bino_dist(int i, int j){
	int dx = a[j].first - a[i].first;
	int dy = a[j].second - a[i].second;
	if(dx < 0 || dy < 0) return 0;
	lint t = fac[dx + dy] * invf[dx] % mod;
	t *= invf[dy];
	return t % mod;
}

lint f(int x){
	if(~dp[x]) return dp[x];
	int ret = bino_dist(0, x);
	for(int i=1; i<x; i++){
		ret -= f(i) * bino_dist(i, x) % mod;
		ret += mod;
		ret %= mod;
	}
	return dp[x] = ret;
}

int main(){
	memset(dp,-1,sizeof(dp));
	fac[0] = 1;
	invf[0] = 1;
	for(int i=1; i<=200000; i++){
		fac[i] = fac[i-1] * i % mod;
		invf[i] = pw(fac[i], mod - 2);
	}
	scanf("%d %d",&h,&w);
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d %d",&a[i].first,&a[i].second);
	}
	sort(a+1,a+n+1);
	a[0] = pi(1,1);
	a[n+1] = pi(h,w);
	printf("%lld",f(n+1));
}