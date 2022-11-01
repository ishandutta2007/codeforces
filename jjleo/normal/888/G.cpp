#include<bits/stdc++.h>
#define maxn 200086
using namespace std;

typedef long long ll;

struct Node{
	int son[2];
}t[maxn << 6];

int cnt;
ll ans;

void insert(int x){
	int now = 0;
	bool y;
	for(int i = 1 << 29;i;i >>= 1){//debug:  
		if(!t[now].son[y = x & i]) t[now].son[y] = ++cnt, t[t[now].son[y]].son[0] = t[t[now].son[y]].son[1] = 0;// 01trie 
		now = t[now].son[y];
	}
}

int query(int x){
	int now = 0, ans = 0;
	bool y;
	for(int i = 1 << 29;i;i >>= 1){
		if(t[now].son[y = x & i]) now = t[now].son[y];
		else now = t[now].son[y ^ 1], ans += i;
	}
	return ans;
}

int n, a[maxn];

void solve(int l, int r, int x){
	
	int mid = r;
	for(int i = l;i <= r;i++){
		if(a[i] & x){//debug:  
			mid = i - 1;
			break;
		}
	}
	if(mid != l - 1 && mid != r){
		cnt = 0, t[0].son[0] = t[0].son[1] = 0;// 01trie 
		for(int i = l;i <= mid;i++) insert(a[i]);
		int sum = 1 << 30;
		for(int i = mid + 1;i <= r;i++) sum = min(sum, query(a[i]));	
		ans += sum;
	}
	if(!(x >>= 1)) return;
	if(l <= mid) solve(l, mid, x);
	if(mid < r) solve(mid + 1, r, x);
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	solve(1, n, 1 << 29);
	printf("%lld", ans);
}