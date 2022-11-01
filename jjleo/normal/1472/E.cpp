#include <bits/stdc++.h>
#define maxn 400086

using namespace std;

int t;
int n;
struct Node{
	int x, y, i;
}a[maxn];

int A[maxn];
void add(int x, int y){
	for(;x <= n;x += x & -x) A[x] = max(A[x], y);
}

int query(int x){
	int sum = 0;
	for(;x;x -= x & -x) sum = max(sum, A[x]);
	return sum;
}

inline bool operator < (Node a, Node b){
	return a.x < b.x;
}

int ans[maxn];
vector<int> v;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d%d", &a[i].x, &a[i].y), a[i].i = i, ans[i] = 0;
		for(int i = 1;i <= n;i++) a[i + n] = a[i], swap(a[i + n].x, a[i + n].y);
		n *= 2;
		v.clear();
		for(int i = 1;i <= n;i++){
			A[i] = 0;
			v.push_back(a[i].y);
		}
		sort(a + 1, a + 1 + n);
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		int l = 1;
		for(int i = 1;i <= n;i++){
			a[i].y = lower_bound(v.begin(), v.end(), a[i].y) - v.begin() + 1;
			ans[a[i].i] = max(ans[a[i].i], query(a[i].y - 1));
			if(i < n && a[i].x != a[i + 1].x){
				for(int j = l;j <= i;j++) add(a[j].y, a[j].i);
				l = i + 1;
			}
		}
		for(int i = 1;i <= n / 2;i++) printf("%d ", ans[i] ? ans[i] : -1);
		puts("");
	}
}