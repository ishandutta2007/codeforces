#include <bits/stdc++.h>
#define maxn 600086

using namespace std;

int n, k;
bool vis[maxn];
int x;

struct Node{
	int mn, l, r;
}a[maxn], b[maxn];

void solve(int l, int r){
	if(l == r){
		if(vis[l]) a[l] = (Node){(int)1e9, l, l};
		else a[l] = (Node){(int)1e9, (int)1e9, (int)-1e9};
		return;
	}
	int mid = l + r >> 1, len = mid - l + 1;
	solve(l, mid), solve(mid + 1, r);
	for(int i = l;i <= mid;i++){
		b[i] = (Node){min(a[i].mn, a[i + len].mn), min(a[i].l, a[i + len].l), max(a[i].r, a[i + len].r)};
		if(a[i].r != -1 && a[i + len].r != -1) b[i].mn = min(b[i].mn, a[i + len].l - a[i].r);
		b[i + len] = (Node){min(a[i].mn, a[i + len].mn), min(a[i].l + len, a[i + len].l - len), max(a[i].r + len, a[i + len].r - len)};
		if(a[i].r != -1 && a[i + len].r != -1) b[i + len].mn = min(b[i + len].mn, a[i].l + len - (a[i + len].r - len));
	}
	for(int i = l;i <= r;i++) a[i] = b[i];
}

int main(){
	scanf("%d%d", &n, &k);
	while(n--) scanf("%d", &x), vis[x] = true;
	solve(0, (1 << k) - 1);
	for(int i = 0;i < (1 << k);i++) printf("%d ", a[i].mn);
}