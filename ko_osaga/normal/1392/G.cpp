#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 1000005;
const int mod = 1e9 + 7;

int n, m, k, s, e;
pi a[MAXN];
int FM[MAXN], BM[MAXN];
int dp[21][1 << 20];

void solve(){
	memset(dp, 0x3f, sizeof(dp));
	for(int i=1; i<=n; i++){
		for(int j=0; j<=k; j++){
			dp[j][FM[i]] = min(dp[j][FM[i]], i);
		}
	}
	for(int i=0; i<k; i++){
		for(int j=k; j; j--){
			for(int msk = 0; msk < (1<<k); msk++){
				dp[j][msk] = min(dp[j][msk], dp[j-1][msk^(1<<i)]);
			}
		}
	}
	auto ret = make_tuple(69, 0, 0);
	for(int j=1; j<=n; j++){
		for(int x=0; x<=k; x++){
			int w = dp[x][BM[j]];
			if(j - w + 1 >= m){
				ret = min(ret, make_tuple(x, w, j));
			}
		}
	}
	int x, y, z;
	tie(x, y, z) = ret;
	cout << k- x << endl << y << " " << z << endl;
}

void make_masks(){
	vector<int> p(k); 
	iota(all(p), 0);
	for(int i=1; i<=n; i++){
		for(int j=0; j<k; j++){
			if((s >> j) & 1){
				FM[i] |= (1<<p[j]);
			}
		}
		swap(p[a[i].first], p[a[i].second]);
	}
	iota(all(p), 0);
	for(int i=1; i<=n; i++){
		swap(p[a[i].first], p[a[i].second]);
		for(int j=0; j<k; j++){
			if((e >> j) & 1){
				BM[i] |= (1<<p[j]);
			}
		}
	}
}

int read_mask(){
	string s; cin >> s;
	int ret = 0;
	for(int i=0; i<sz(s); i++){
		if(s[i] == '1') ret += (1<<i);
	}
	return ret;
}

int main(){
	scanf("%d %d %d",&n,&m,&k);
	s = read_mask();
	e = read_mask();
	for(int i=1; i<=n; i++){
		scanf("%d %d",&a[i].first,&a[i].second);
		a[i].first--;
		a[i].second--;
	}
	make_masks();
	solve();
}