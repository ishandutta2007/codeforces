#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fs first
#define sc second
#define vc vector
#define pr pair
#define mp make_pair
#define pb push_back
#define len(v) (int)v.size()
#define all(v) v.begin(), v.end()

#pragma GCC optimize("Ofast")

using namespace std;

const int INF = 5e3 + 4;
const int MAXN = 5e5 + 10;
const int MOD = 1e9 + 7;
const int P = 1001;
const int MOD1 = 1e9 + 9;
const int P1 = 102;

int mul(int a, int b){
	return ((ll)a * b) % MOD;
}

int mul1(int a, int b){
	return ((ll)a * b) % MOD1;
}

int sum(int a, int b){
	if (a + b >= MOD){
		return a + b - MOD;
	}
	else{
		return a + b;
	}
}

int sum1(int a, int b){
	if (a + b >= MOD1){
		return a + b - MOD1;
	}
	else{
		return a + b;
	}
}

string s;
int p[MAXN];
int h[MAXN];
int p1[MAXN];
int h1[MAXN];

bool checks(int counts, int pos){
	for (int i = 0; i + counts - 1 <= pos - counts; i++){
		if ((sum(h[pos + 1], MOD - h[pos - counts + 1])) == mul(sum(h[i + counts], MOD - h[i]), p[pos - counts + 1 - i])){
			if ((sum1(h1[pos + 1], MOD1 - h1[pos - counts + 1])) == mul1(sum1(h1[i + counts], MOD1 - h1[i]), p1[pos - counts + 1 - i])){
				return 1;
			}
		}	
	}
	return 0;
}

signed main(){
	#ifdef __linux__
		freopen("input.txt", "r", stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	cin >> s;
	p[0] = 1;
	for (int i = 1; i <= n; i++){
		p[i] = mul(p[i - 1], P);
	}
	p1[0] = 1;
	for (int i = 1; i <= n; i++){
		p1[i] = mul1(p1[i - 1], P1);
	}
	vc<int> dp(n + 1, MOD);
	dp[0] = 0;
	for (int i = 0; i < n; i++){
		h[i + 1] = sum(h[i], mul(s[i], p[i + 1]));
	}
	for (int i = 0; i < n; i++){
		h1[i + 1] = sum1(h1[i], mul1(s[i], p1[i + 1]));
	}
	for (int i = 0; i < n; i++){
		dp[i + 1] = dp[i] + a;
		int l = 0;
		int r = i + 1;
		while (r - l > 1){
			int mid = (l + r) / 2;
			if (checks(mid, i)){
				l = mid;
			}
			else{
				r = mid;
			}
		}
		dp[i + 1] = min(dp[i + 1], dp[i + 1 - l] + b);
	}
	cout << dp[n];
}