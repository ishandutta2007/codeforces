#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 5005;
const int mod =1e9 + 7;

int n, m;
vector<int> pos[MAXN];
vector<int> occ[MAXN];
pi dp[MAXN][MAXN];
bitset<MAXN> rev[MAXN];
int val[2][MAXN];

pi operator+(pi a, pi b){
	if(a > b) swap(a, b);
	if(a.first == b.first) b.second += a.second;
	if(b.second >= mod) b.second -= mod;
	return b;
}

bool Lpos[MAXN];
int a[MAXN];

int main(){
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		occ[a[i]].push_back(i);
	}
	pi ret(0, 1);
	for(int i=1; i<=m; i++){
		int x, y; cin >> x >> y;
		if(y <= sz(occ[x])){
			pos[x].push_back(y);
			Lpos[occ[x][y - 1]] = 1;
		}
	}
	for(int i=1; i<=n; i++){
		int good = sz(pos[i]);
		if(good){
			ret.first += 1;
			ret.second = 1ll * ret.second * good % mod;
		}
	}
	for(int i=1; i<=n; i++){
		if(Lpos[i]){
			int v = a[i];
			int w = lower_bound(all(occ[v]), i) - occ[v].begin();
			pi tmp(1, 1);
			int possibleRightEnd = 0;
			for(auto &j : pos[v]){
				if(sz(occ[v]) - j > w){
					if(j - 1 != w) possibleRightEnd++;
				}
			}
			if(possibleRightEnd){
				tmp.first++;
				tmp.second = possibleRightEnd;
			}
			for(int j=1; j<=n; j++){
				if(v == j) continue;
				int countLeft = 0;
				int countRight = 0;
				int countDuplicate = 0;
				for(auto &k : pos[j]){
					if(occ[j][k-1] <= i) countLeft++;
					if(occ[j][sz(occ[j])-k] > i) countRight++;
					if(occ[j][k-1] <= i && occ[j][sz(occ[j])-k] > i) countDuplicate++;
				}
				int two_count = countLeft * countRight - countDuplicate;
				int one_count = countLeft + countRight;
				if(two_count){
					tmp.first += 2;
					tmp.second = 1ll * tmp.second * two_count % mod;
				}
				else if(one_count){
					tmp.first += 1;
					tmp.second = 1ll * tmp.second * one_count % mod;
				}
			}
			ret = ret + tmp;
		}
	}
	printf("%d %d\n", ret.first, ret.second);
}