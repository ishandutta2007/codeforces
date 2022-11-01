#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int t;
int n;
int a[maxn], b[maxn];
bool suc;

inline int check(int x){
	int y = x;
	for(int i = 1;i < n;i++){
		if(b[i] < max(a[i] - x, 0)) return -1;
		x = b[i] - max(a[i] - x, 0);
	}
	if(b[n] - y + x < a[n]) return 1;
	return 0;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = 1;i <= n;i++) scanf("%d", &b[i]);
		int l = 0, r = b[n], mid;
		suc = false;
		while(l <= r){
			mid = l + r >> 1;
			int x = check(mid);
			if(!x){
				suc = true;
				break;
			}
			if(x == 1) r = mid - 1;
			else l = mid + 1;
		}
		puts(suc ? "YES" : "NO");
	}
}