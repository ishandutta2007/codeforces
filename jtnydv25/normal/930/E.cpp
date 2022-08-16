#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
const int mod = 1e9 + 7;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
	int x = 1 % mod;
	while(b){
		if(b & 1) x = mul(x, a);
		a = mul(a, a);
		b >>= 1;
	}
	return x;
}

inline int inv(int a){ return powr(a, mod - 2);}

vector<pii> A, B;

bool cmp(const pii & x, const pii & y){
	return x.F < y.F || (x.F == y.F && x.S > y.S);
}

void go(vector<pii> & X){
	vector<pii> ret;
	sort(X.begin(), X.end(), cmp);
	for(int i = 0; i < X.size(); i++){
		int l1 = X[i].F, r1 = X[i].S;
		while(!ret.empty()){
			int l2 = ret.back().F, r2 = ret.back().S;
			if(l1 >= l2 && r1 <= r2) ret.pop_back();
			else break;
		}
		ret.push_back(X[i]);
	}
	X = ret;
}

const int inv2 = (mod + 1) >> 1;
const int MAXN = 200005;

int dp[2][2][MAXN];
int dp1[2][2][MAXN];
int dp2[2][2][MAXN];
void ADD(int & a, int b){a += b; if(a >= mod) a -= mod;}

vector<int> P[2];
int main(){
	int k, n, m;
	sd(k); sd(n); sd(m);
	int mn = 2e9, mx = -1;
	for(int i = 1; i <= n; i++){
		int a, b;
		sd(a); sd(b);
		A.push_back({a, b});
	}
	for(int i = 1; i <= m; i++){
		int a, b;
		sd(a); sd(b);
		B.push_back({a, b});
	}

	go(A); go(B);
	P[0] = P[1] = {-1};
	for(auto it : A) P[0].push_back(it.S);
	for(auto it : B) P[1].push_back(it.S);
	reverse(A.begin(), A.end()); reverse(B.begin(), B.end());

	dp[0][0][0] = dp1[0][0][0] = dp2[0][0][0] = 1;

	int cnt[2] = {0, 0};
	int f[2] = {powr(2, k), 0};

	while(!A.empty() || !B.empty()){
		int L, R, type;
		if(A.empty()){
			L = B.back().F;
			R = B.back().S;
			type = 1;
			B.pop_back();
		} else if(B.empty()){
			L = A.back().F;
			R = A.back().S;
			type = 0;
			A.pop_back();
		} else{
			int l1 = A.back().F, r1 = A.back().S;
			int l2 = B.back().F, r2 = B.back().S;
			if(l1 < l2 || (l1 == l2 && r1 < r2)){
				L = l1; R = r1; type = 0;
				A.pop_back();
			} else{
				L = l2; R = r2; type = 1;
				B.pop_back();
			}
		}

		cnt[type]++;
		for(int prevparity = 0; prevparity < 2; prevparity++){
			int newparity = prevparity ^ 1;

			int ind = lower_bound(P[type].begin(), P[type].end(), L) - P[type].begin();
			int ind2 = lower_bound(P[type ^ 1].begin(), P[type ^ 1].end(), L) - P[type ^ 1].begin();

			ADD(dp[type][newparity][cnt[type]], mul(powr(2, L - 1), 
				add(dp2[type][prevparity][ind - 1], dp2[type ^ 1][prevparity][ind2 - 1])));

			ADD(dp[type][newparity][cnt[type]], sub(dp1[type][prevparity][cnt[type] - 1], 
				dp1[type][prevparity][ind - 1]));
		}

		for(int parity = 0; parity < 2; parity++){
			dp2[type][parity][cnt[type]] = add(dp2[type][parity][cnt[type] - 1], 
				mul(powr(inv2, R), dp[type][parity][cnt[type]]));
			dp1[type][parity][cnt[type]] = add(dp1[type][parity][cnt[type] - 1], dp[type][parity][cnt[type]]);
			f[parity] = add(f[parity], mul(dp[type][parity][cnt[type]], powr(2, k - R)));
		}
	}

	printf("%d\n", sub(f[0], f[1]));
}