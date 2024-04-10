#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 1e7 + 10;

int n, m;
ll f[MAXN];
int x, y;

void read(){
	scanf("%d%d%d", &n, &x, &y);
}

void solve(){
	ll INF = (1ll << 60);
	for(int i = 1; i <= n + 2; i++){
		f[i] = INF;
	}
	f[0] = 0;
	for(int i = 0; i <= n; i++){
		f[i] = min(f[i], f[i+1] + x);
		f[i+1] = min(f[i+1], f[i] + x);
		if ((i<<1) <= n + 2)
			f[(i<<1)] = min(f[i<<1], f[i] + y);
	}
	printf("%lld\n", f[n]);
}

void printans(){

}
	

int main(){
	int T = 1;
//	cin>>T;
	while(T--){
		read();
		solve();
		printans();
	}
	return 0;
}