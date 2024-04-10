#include <bits/stdc++.h>
#define maxn 1086

using namespace std;

typedef long long ll;

int n, m;
ll a[maxn][maxn];
ll sum[maxn], sum2[maxn];
map<ll, int> mp;

int main(){
	scanf("%d%d", &m, &n);
	for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) scanf("%lld", &a[i][j]);
	for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) sum[i] += a[i][j], sum2[i] += a[i][j] * a[i][j];
	for(int i = 2;i <= n;i++) mp[sum[i] - sum[i - 1]]++;
	int mx = 0;
	ll d, val;
	for(map<ll, int>::iterator it = mp.begin();it != mp.end();++it){
		if(it->second > mx) mx = it->second, d = it->first;
	}
	int x;
	for(int i = 2;i <= n;i++){
		if(sum[i] - sum[i - 1] != d){
			if(i == n) x = n, val = d - (sum[i] - sum[i - 1]);
			else if(sum[i + 1] - sum[i] != d) x = i, val = d - (sum[i] - sum[i - 1]);
			else x = 1, val = sum[i] - sum[i - 1] - d;
			break;
		}
	}
	ll d2;
	if(x > 3) d2 = (sum2[1] + sum2[3] - 2 * sum2[2]) / 2;
	else d2 = (sum2[n - 2] + sum2[n] - 2 * sum2[n - 1]) / 2;
	for(int i = 1;i <= m;i++){
		if(x == 1){
			if(sum2[x] - a[x][i] * a[x][i] + (a[x][i] + val) * (a[x][i] + val) + sum2[x + 2] - 2 * sum2[x + 1] == 2 * d2) return printf("%d %d", x - 1, a[x][i] + val), 0;
		}else if(x == n){
			if(sum2[x - 2]+ sum2[x] - a[x][i] * a[x][i] + (a[x][i] + val) * (a[x][i] + val) - 2 * sum2[x - 1] == 2 * d2) return printf("%d %d", x - 1, a[x][i] + val), 0;
		}else{
			if(sum2[x - 1] + sum2[x + 1] - 2 * (sum2[x] - a[x][i] * a[x][i] + (a[x][i] + val) * (a[x][i] + val)) == 2 * d2) return printf("%d %d", x - 1, a[x][i] + val), 0;
		}
	}
	
}