#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 998244353;
const int N = 5005;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int mul(int a, int b){
	return (a * 1ll * b) % mod;
}
inline int powr(int a, int b){
	int x = 1;
	for(; b; b >>= 1, a = mul(a, a)) if(b & 1) x = mul(x, a);
	return x;
}
inline int inv(int a){
	return powr(a, mod - 2);
}
int fact[N], invfact[N];

void pre(){
	fact[0] = 1;
	for(int i = 1; i < N; i++) fact[i] = mul(i, fact[i - 1]);
	invfact[N - 1] = inv(fact[N - 1]);
	for(int i = N - 2; i >= 0; i--)
		invfact[i] = mul(i + 1, invfact[i + 1]);
	assert(invfact[0] == 1);
}

inline int C(int n, int k){
	if(n < k || k < 0 || n < 0) return 0;
	return mul(fact[n], mul(invfact[k], invfact[n - k])); 
}
inline int getMod(int x){
	vector<int> vec;
	int p = 1, sm = 0;
	while(x){
		sm += (x % 10) * p;
		p *= -1;
		x /= 10;
	}
	sm *= (-p);
	sm = (sm % 11 + 11) % 11;
	return sm;
}
int A[N], n, t;
vector<int> vodd, veven;
int cnt1[11], cnt2[11];
int dp[11][N], dp2[11][N];
int F[N];

inline int sol(int n, int r){
	if(n == 0 && r == 0) return 1;
	return C(n + r - 1, n - 1);
}
int main(){
	pre();
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		vodd.clear();
		veven.clear();
		memset(cnt1, 0, sizeof cnt1);
		memset(cnt2, 0, sizeof cnt2);
		int smOdd = 0, smEven = 0;
		for(int i = 1; i <= n; i++){
			scanf("%d", &A[i]);
			string s = to_string(A[i]);
			int l = s.length();
			int md = getMod(A[i]);
			if(l & 1){
				vodd.push_back(md);
				cnt1[md]++;
				smOdd += md;
			}
			else{
				veven.push_back(md);
				cnt2[md]++;
				smEven += md;
			}
		}

		smOdd %= 11;
		smEven %= 11;
		int len = vodd.size();
		int l = (len + 1) / 2;
		int numEven = veven.size();
		int numOdd = vodd.size();
		memset(dp, 0, sizeof dp);
		dp[0][0] = 1;
		for(int i = 0; i <= 10; i++){
			memcpy(dp2, dp, sizeof dp);
			memset(dp, 0, sizeof dp);
			for(int prev = 0; prev <= 10; prev ++){
				for(int smprev = 0; smprev <= n; smprev ++){
					for(int k = 0; k <= cnt1[i]; k++){
						int md = (prev + k * i) % 11;
						int cnt = smprev + k;
						if(cnt <= n){
							dp[md][cnt] = add(dp[md][cnt], mul(C(cnt1[i], k), dp2[prev][smprev]));
						}
					}
				}
			}
		}

		for(int s = 0; s <= 10; s++) F[s] = dp[s][l];
		memset(dp, 0, sizeof dp);
		dp[0][0] = 1;

		for(int i = 0; i <= 10; i++){
			memcpy(dp2, dp, sizeof dp);
			memset(dp, 0, sizeof dp);
			for(int prev = 0; prev <= 10; prev ++){
				for(int smprev = 0; smprev <= n; smprev ++){
					for(int k = 0; k <= cnt2[i]; k++){
						int md = (prev + k * i) % 11;
						int cnt = smprev + k;
						if(cnt <= n){
							dp[md][cnt] = add(dp[md][cnt], mul(C(cnt2[i], k), dp2[prev][smprev]));
						}
					}
				}
			}
		}

		int ans = 0;
		for(int s = 0; s <= 10; s++){
			int ways = F[s];
			int sum_odd = s - (smOdd - s);
			int req = ((-sum_odd) % 11 + 11) % 11;
			int req_even = ((smEven + req) * 6) % 11;
			for(int r = 0; r <= numEven; r++){
				int _r = numEven - r;
				int ways2 = dp[req_even][r];
				int p = (numOdd / 2) + 1;
				int q = numOdd + 1 - p;
				int ml = mul(fact[l], fact[numOdd - l]);
				ml = mul(ml, fact[r]);
				ml = mul(ml, fact[_r]);
				ml = mul(ml, sol(p, r));
				ml = mul(ml, sol(q, _r));
				ans = add(ans, mul(ml, mul(ways, ways2)));
			}
		}
		printf("%d\n", ans);
	}

}