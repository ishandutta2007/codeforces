#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
using lint = long long;
using pi = pair<int, int>;
const int mod = 998244353; //1e9 + 7;

struct edg{
	int s, e, x;
	bool operator<(const edg &e)const{
		return x < e.x;
	}
};
vector<edg> ed;
int n, k, a[MAXN];
int L[MAXN][MAXN], R[MAXN][MAXN];
int sum[MAXN];

int main(){
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			if(a[i] < a[j]) ed.push_back({i, j, a[j] - a[i]});
		}
	}
	sort(ed.begin(), ed.end());
	int realPtr = 0;
	lint ret = 0;
	for(int i=1; i<=100000/(k-1); i++){
		for(int j=1; j<=n; j++){
			L[1][j] = R[1][j] = 1;
		}
		for(int j=2; j<=k; j++){
			int ptr = 0;
			int sum = 0;
			for(int l=1; l<=n; l++){
				while(ptr < l && a[l] - a[ptr + 1] > i){
					ptr++;
					sum += L[j-1][ptr];
					if(sum >= mod) sum -= mod;
				}
				L[j][l] = sum;
			}
			ptr = n + 1;
			sum = 0;
			for(int l=n; l; l--){
				while(ptr > l && a[ptr - 1] - a[l] >= i){
					ptr--;
					sum += R[j-1][ptr];
					if(sum >= mod) sum -= mod;
				}
				R[j][l] = sum;
			}
		}
		while(realPtr < ed.size() && ed[realPtr].x == i){
			auto j = ed[realPtr++];
			for(int x = 1; x < k; x++){
				ret += (1ll * L[x][j.s] * R[k-x][j.e] % mod) * j.x;
			}
			ret %= mod;
		}
	}
	cout << ret << endl;
}