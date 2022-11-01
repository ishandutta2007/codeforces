#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

typedef long long ll;

int n;
pair<int, int> a[maxn];
ll cnt[40][2];

int b[maxn];

inline void add(int x, int y){
	for(;x < maxn;x += x & -x) b[x] += y;
}

inline int query(int x){
	int sum = 0;
	for(;x;x -= x & -x) sum += b[x];
	return sum;
}

void dfs(int x, int l, int r){
	if(x < 0) return;
	int mid = r; 
	for(int i = l;i <= r;i++){
		if(a[i].first & (1 << x)){
			mid = i - 1;			
			break;
		}
	}
	//printf("%d %d %d %d--\n", x, l, r, mid);
	if(mid == l - 1 || mid == r){
		dfs(x - 1, l, r);
		return;
	}
	
	for(int i = mid + 1;i <= r;i++) add(a[i].second, 1);
	for(int i = l;i <= mid;i++) cnt[x][0] += query(a[i].second);
	for(int i = mid + 1;i <= r;i++) add(a[i].second, -1);
	for(int i = l;i <= mid;i++) add(a[i].second, 1);
	for(int i = mid + 1;i <= r;i++) cnt[x][1] += query(a[i].second);
	for(int i = l;i <= mid;i++) add(a[i].second, -1);
	dfs(x - 1, l, mid), dfs(x - 1, mid + 1, r);
	
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i].first), a[i].second = i;
	sort(a + 1, a + 1 + n);
	dfs(30, 1, n);
	ll ans1 = 0, ans2 = 0;
	for(int i = 30;~i;i--){
		if(cnt[i][1] < cnt[i][0]) ans1 += 1 << i, ans2 += cnt[i][1];
		else ans2 += cnt[i][0];
	}
	printf("%lld %lld", ans2, ans1);
}