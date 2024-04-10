#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e6;
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

int a[N], pw2[N];
int cnt0[7][N];
ll cnt1[7][N], cnt2[7][N];
int pw[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};
ll F[N];
inline int get(int l, vector<int> ){

}
int main(){
	pw2[0] = 1;
	for(int i = 1; i < N; i++) pw2[i] = mul(pw2[i - 1], 2);
	int n, x;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		cnt0[6][x]++;
		cnt1[6][x] += x;
		cnt2[6][x] += x * 1ll *x;
	}
	for(int i = 5; i >= 0; i--){
		for(int j = 0; j < N; j++){
			int y[6];
			int p = j;
			int equal = 0, greater = 0;
			for(int k = 0; k < 6; k++){
				y[k] = p % 10; p /= 10;
				if(k < i)equal += y[k] * pw[k];
				if(k > i) greater += y[k] * pw[k];
			}

			for(int m = y[i]; m <= 9; m++){
				cnt0[i][j] += cnt0[i + 1][equal + greater + m * pw[i]];
				cnt1[i][j] += cnt1[i + 1][equal + greater + m * pw[i]];
				cnt2[i][j] += cnt2[i + 1][equal + greater + m * pw[i]];
			}
			if(i == 0){
				cnt0[0][j] %= mod;
				cnt1[0][j] %= mod;
				cnt2[0][j] %= mod;
				if(cnt0[0][j] == 0) continue;
				if(cnt0[0][j] == 1)
					F[j] = (cnt1[0][j] * 1ll * cnt1[0][j]) % mod;
				else F[j] = mul(pw2[cnt0[0][j] - 2], add(mul(cnt1[0][j], cnt1[0][j]), cnt2[0][j]));
			}
		}
	}
	ll fans = 0;
	for(int i = 0; i < N; i++){
		int ans = 0;
		int y[6];
		int p = i;
		for(int j = 0; j < 6; j++){
			y[j] = p % 10; p /= 10;
		}
		for(int l = 0; l < (1 << 6); l++){
			bool flag = 0;
			int z = i;
			for(int j = 0; j < 6; j++){
				if(l & (1 << j)){
					z += pw[j];
					if(y[j] == 9) flag = 1;
				}
			}
			if(flag) continue;
			if(__builtin_popcount(l) & 1){
				ans = sub(ans, F[z]);
			}
			else ans = add(ans, F[z]);
		}
		fans = (ans * 1ll * i) ^ fans;
	}
	cout << fans << endl;
}