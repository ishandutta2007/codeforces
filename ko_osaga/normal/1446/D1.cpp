#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 200005;

int n, a[MAXN], cnt[MAXN];
int occ[MAXN * 2], sum[MAXN];

int solve(int x, int y){
	for(int i=1; i<=n; i++){
		sum[i] = sum[i-1];
		if(a[i] == x) sum[i]++;
		if(a[i] == y) sum[i]--;
	}
	memset(occ, 0x3f, sizeof(occ));
	int ret = 0;
	for(int i=1; i<=n; i++){
		occ[sum[i-1] + MAXN] = min(
		occ[sum[i-1] + MAXN], i-1);
		ret = max(ret, i - occ[sum[i] + MAXN]);
	}
	return ret;
}

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	int q = max_element(cnt, cnt + n + 1) - cnt;
	int ret = 0;
	for(int i=1; i<=min(100, n); i++){
		if(i == q) continue;
		ret = max(ret, solve(q, i));
	}
	cout << ret << endl;
}