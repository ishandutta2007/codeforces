#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int sum[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	sum[x] = min(sum[ls(x)], sum[rs(x)]);
}

int query(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return sum[x];
	int mid = l + r >> 1, ans = 1e9;
	if(mid >= ll) ans = min(ans, query(ls(x), l, mid, ll, rr));
	if(mid < rr) ans = min(ans, query(rs(x), mid + 1, r, ll, rr));
	return ans;
}

int a[maxn];

void build(int x, int l, int r){
	if(l == r){
		sum[x] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	up(x);
}

int t;
int n;
vector<int> v;
int sk[maxn], top;
int r[maxn], l[maxn];
vector<int> w[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		v.clear();
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), v.push_back(a[i]);
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for(int i = 1;i <= n;i++) w[i].clear();
		for(int i = 1;i <= n;i++){
			a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
			w[a[i]].push_back(i);
		}
		bool tag = false;
		build(1, 1, n);
		if(w[v.size()].size() >= 3){
			tag = true;
			puts("YES");
			printf("%d %d %d\n", w[v.size()][1] - 1, 1, n - w[v.size()][1]);
			continue;
		}
		int l = w[v.size()][0], r = w[v.size()].back();
		for(int i = v.size() - 1;i;i--){
			if(query(1, 1, n, l, r) < i){
				l = min(l, w[i][0]), r = max(r, w[i].back());
				continue;
			}
			if(w[i].size() >= 3 && w[i][0] < l && w[i].back() > r){
				for(int j = 1;j + 1 < w[i].size();j++){
					if(w[i][j] < l){
						if(query(1, 1, n, w[i][j], r) == i){
							tag = true;
							puts("YES");
							printf("%d %d %d\n", w[i][j] - 1, r - w[i][j] + 1, n - r);
							break;
						}
					}else if(w[i][j] > r){
						if(query(1, 1, n, l, w[i][j]) == i){
							tag = true;
							puts("YES");
							printf("%d %d %d\n", l - 1, w[i][j] - l + 1, n - w[i][j]);
							break;
						}
					}else{
						tag = true;
						puts("YES");
						printf("%d %d %d\n", l - 1, r - l + 1, n - r);
						break;
					}
				}
				if(tag) break;
			}
			l = min(l, w[i][0]), r = max(r, w[i].back());
		}
		/*build(1, 1, n);
		top = 0;
		for(int i = n;i;i--){
			while(top && a[sk[top]] <= a[i]) top--;
			if(!top) r[i] = n + 1;
			else r[i] = sk[top];
			sk[++top] = i; 
		}
		top = 0;
		for(int i = 1;i <= n;i++){
			while(top && a[sk[top]] <= a[i]) top--;
			if(!top) l[i] = 0;
			else l[i] = sk[top];
			sk[++top] = i;
		}
		int mx = 0;
		bool tag = false;
		for(int i = 1;i <= n;i++){
			mx = max(mx, a[i]);
			if(a[i] < mx) continue;
			if(r[i] == n + 1) break;
			if(w[a[i]].size() < 3) continue;
			int x = w[a[i]].back();
			if(x == i) continue;
			//printf("%d %d %d--\n", i, r[i], l[x]);
			if(query(1, 1, n, r[i], l[x]) == a[i]){
				tag = true;
				puts("YES");
				printf("%d %d %d\n", r[i] - 1, l[x] - r[i] + 1, n - l[x]);
				break;
			}
		}
		if(w[v.size()].size() >= 3){
			tag = true;
			puts("YES");
			printf("%d %d %d\n", w[v.size()][1] - 1, 1, n - w[v.size()][1]);
		}*/
		if(!tag) puts("NO");
	}
}