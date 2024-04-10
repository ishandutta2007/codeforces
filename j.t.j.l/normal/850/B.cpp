#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 100;

int n, m;

void prework(){

}

void read(){

}

int vis[MAXN];
int a[MAXN];
ll X, Y;

ll cnt[MAXN];
ll sum[MAXN], sum2[MAXN];

ll gao(int d){
	int L = 1, R = d - 1;
	int M = d - X / Y - 1;
	if (M >= R) M = R;
	if (M <= L - 1) M = L - 1;
	ll ret = 0, flag = 0;
	for (ll i = 0; i * d <= 1000010; i++){
		ret += X * (sum[i * d + M] - sum[i * d]);
		ret += Y * ((i + 1) * d * (sum[i * d + R] - sum[i * d + M]) - (sum2[i * d + R] - sum2[i * d + M]));
		flag += sum[i * d + R] - sum[i * d + M];
		flag += cnt[i * d];
	}
	if (true)
		return ret;
	int l = L, r = M + 1, m;
	while(l + 1 < r){
		m = (l + r) / 2;
		int fg = 0;
		for (int i = m, j = d - 1; i <= 1000010; i += d, j += d){
			if (sum[j] - sum[i - 1]){
				fg = 1;
				break;
			}
		}
		if (fg)
			l = m;
		else
			r = m;
	}
	ret = ret - X + Y * (d - m);
	return ret;
}

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%d%lld%lld", &n, &X, &Y);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	ll ans = 1ll << 60;
	int N = 1000010;
	for (int i = 1; i <= 2 * N + 1; i++){
		sum[i] = sum[i-1] + cnt[i];
		sum2[i] = sum2[i-1] + 1ll * i * cnt[i];
	}

	for (int i = 2; i <= N; ){
		ans = min(ans, gao(i));
		for (int j = i; j <= N; j += i){
			vis[j] = 1;
		}
		while(i <= N && vis[i] == 1)
			i++;
	}
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