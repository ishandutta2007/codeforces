#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<ll, PII> PLP;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

const ll INF = 1ll << 50;

int n, m;

void prework(){

}

void read(){

}

int MAKI = 500000;
ll sumH, K;

ll cof[111];
int a[111];

int check(ll d){
	ll ret = 0;
	for (int i = 1; i <= n; i++){
		ll day = a[i] / d;
		if (a[i] % d != 0)
			day++;
		ret += day * d - a[i];
	}
	return ret <= K;
}

ll getans(ll dmin, ll dmax, ll T){
	if (T == 0)
		return 1ll;
	ll d = (K + sumH) / T;
	if (dmin <= d && d <= dmax)
		return d;
	if (d >= dmax)
		return dmax;
	if (d < dmin)
		return -1ll;
}

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%d%lld", &n, &K);
	sumH = 0;
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		sumH += a[i];
	}
	ll ans = 0;
	vector<PLP> f;
	for (int i = 1; i <= n; i++){
		ll H = a[i];
		ll dmax = INF;
		for (int j = 1; ; j++){
			ll dmin = H / j;
			if (H % j != 0)
				dmin++;
			dmax = dmin;
			if (dmax <= MAKI)
				dmax = MAKI;
			f.push_back(PLP(dmax, PII(j, i)));
			if (dmax <= MAKI)
				break;
		}
	}
	sort(f.begin(), f.end());
	ll nowT = 0;
	f.push_back(PLP(INF, PII(0, 0)));
	for (int i = 0; i + 1 < f.size(); i++){
		nowT -= cof[f[i].second.second];
		cof[f[i].second.second] = f[i].second.first;
		nowT += cof[f[i].second.second];
		if (f[i].first != f[i + 1].first){
			ans = max(getans(f[i].first, f[i + 1].first - 1, nowT), ans);
		}
	}
	for (int d = MAKI + 1; d > ans; d--){
		if (check(d)){
			ans = d;
			break;
		}
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