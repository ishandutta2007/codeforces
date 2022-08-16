#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";


const int N = 3e5 + 10;
int a[N], dp[N], dp2[N], n, k;
int bit[N];

void update(int k, int v){
	k++;
	for(; k < N; k += (k & (-k))) bit[k] += v;
}

int get(int k){
	k++;
	int ret = 0;
	for(; k; k -= (k & (-k))) ret += bit[k];
	return ret;
}
bool chk(int diff){
	memset(dp, 0, sizeof dp);
	memset(bit, 0, sizeof bit);
	dp[n] = 1;
	update(n, 1);
	int curr1 = 0;
	for(int i = n - k; i >= 0; i--){
		int pos = upper_bound(a, a + n, a[i] + diff) - a;
		int mn = i + k, mx = pos;
		if(mx >= mn && (get(mx) - get(mn - 1))){
			dp[i] = 1;
			update(i, 1);
		}
	}
	return dp[0];
}
int main(){
	sd(n); sd(k);
	for(int i = 0; i < n; i++) sd(a[i]);
	sort(a, a + n);
	int lo = 0, hi = 1e9;
	// chk(20);
	while(lo < hi){
		int mid = (lo + hi) >> 1;
		if(chk(mid)){
			hi = mid;
		}
		else lo = mid + 1;
	}
	printf("%d\n", lo);
}