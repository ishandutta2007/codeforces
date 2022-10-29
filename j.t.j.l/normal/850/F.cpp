#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){

}

ll inv(ll p){
	p %= MM;
	ll ret = 1;
	for (int q = MM - 2; q; q >>= 1){
		if (q & 1)
			ret = ret * p % MM;
		p = (p * p) % MM;
	}
	return ret;
}

int a[MAXN];
ll f[MAXN];

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%d", &n);
	ll S = 0;
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		S += a[i];
	}
	f[0] = 0;
	f[1] = (S - 1) % MM * (S - 1) % MM * inv(S) % MM;
	for (int i = 1; i <= 100010; i++){
		f[i + 1] = ((2 * f[i] - f[i - 1] - (S - 1) % MM * inv(S - i) % MM) % MM + MM) % MM;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans = (ans + f[a[i]]) % MM;
	printf("%lld\n", ans);
}

void printans(){

}


int main(){
//	std::ios::sync_with_stdio(false);
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}