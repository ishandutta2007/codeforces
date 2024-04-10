#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

vector<int> v;

struct BIT{
	int a[maxn];
	
	inline void clear(){
		memset(a, 0, sizeof(a));
	}
	
	inline void add(int x, int y){
		for(;x < maxn;x += x & -x) a[x] += y;
	}
	
	inline int query(int x){
		int sum = 0;
		for(;x;x -= x & -x) sum += a[x];
		return sum;
	}
}ll, rr;


int n;
int l[maxn][2], r[maxn][2];
pair<int, int> a[maxn], b[maxn];

void solve(){
	ll.clear(), rr.clear();
	for(int i = 1;i <= n;i++) a[i] = {l[i][0], i}, b[i] = {r[i][0], i};
	sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + n);
	int x = 0;
	for(int i = 1;i <= n;i++){
		while(x < n && b[x + 1].first < a[i].first){
			x++;
			int id = b[x].second;
			ll.add(l[id][1], 1), rr.add(r[id][1], 1);
		}
		int id = a[i].second;
		if(rr.query(l[id][1] - 1) + x - ll.query(r[id][1]) < x) printf("NO"), exit(0);
	}
	
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) for(int j = 0;j <= 1;j++) scanf("%d%d", &l[i][j], &r[i][j]), v.push_back(l[i][j]), v.push_back(r[i][j]);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(int i = 1;i <= n;i++) for(int j = 0;j <= 1;j++) l[i][j] = lower_bound(v.begin(), v.end(), l[i][j]) - v.begin() + 1, r[i][j] = lower_bound(v.begin(), v.end(), r[i][j]) - v.begin() + 1;
	solve();
	for(int i = 1;i <= n;i++) swap(l[i][0], l[i][1]), swap(r[i][0], r[i][1]);
	solve();
	printf("YES");
}