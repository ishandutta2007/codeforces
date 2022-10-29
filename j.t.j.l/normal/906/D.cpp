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

ll a[MAXN];
ll p[1000];
int M;

ll INF = 2e9 + 15;

ll pw(ll p, ll q, ll MOD){
	p %= MOD;
	ll ret = 1;
	for (; q; q >>= 1){
		if (q & 1) ret = ret * p % MOD;
		p = p * p % MOD;
	}
	return ret;
}

ll pwI(ll p, ll q){
	if (p >= INF) return INF;
	ll ret = 1;
	for (; q; q >>= 1){
		if (q & 1){
			if (p >= INF) return INF;
			ret = ret * p;
			if (ret >= INF) return INF;
		}
		p = p * p;
		if (p >= INF) p = INF;
	}
	return ret;
}

ll phi(ll x){
	//printf("%lld ", x);
	ll ret = 1;
	for (ll i = 2; i * i <= x; i++){
		if (x % i == 0){
			x /= i;
			ret *= (i - 1);
			while(x % i == 0){
				x /= i;
				ret *= i;
			}
		}
	}
	if (x != 1)
		ret *= x - 1;
	//printf("%lld\n", ret);
	return ret;
}

int nxt[MAXN];

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	nxt[n] = n + 1;
	for (int i = n - 1; i >= 1; i--){
		if (a[i + 1] == 1)
			nxt[i] = i + 1;
		else
			nxt[i] = nxt[i + 1];
	}
	p[0] = m;
	M = 0;
	while(p[M] != 1){
		p[M+1] = phi(p[M]);
		M++;
	}
	p[M+1] = 1;
	
	//for (int i = 0; i <= M; i++) cout << p[i] << ' '; cout << endl;
	
	int Q;
	scanf("%d", &Q);
	for (int _ = 1; _ <= Q; _++){
		int l, r;
		scanf("%d%d", &l, &r);
		/*
		if (Q >= 100 && _ == 814){
			cout << l << ' ' << r << endl;
			for (int i = l; i <= r; i++)
				cout << a[i] << ' ';
			cout << endl;
		}*/
		ll now = 1;
		if (r > l + M){
			for (int i = min(r, nxt[l + M]); i > l + M && now != INF; i--){
				now = pwI(a[i], now);
			}
		}
		r = min(l + M, r);
		ll ans = 1;
		for (int i = r; i >= l; i--){
			now = pwI(a[i], now);
			if (now < p[i - l])
				ans = pw(a[i], ans, p[i - l]);
			else
				ans = pw(a[i], ans, p[i - l]) + p[i - l];
			//cout << now << ' ' << ans << endl;
			now = pwI(a[i], now);
		}
		//if (Q <= 100) 
		printf("%lld\n", ans % m);
	}
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