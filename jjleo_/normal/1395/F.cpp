#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

int n;
char s[maxn];
int x[maxn], y[maxn];
int xx, yy;

inline bool check(int mid){
	int l = 0, r = 1e6, u = 1e6, d = 0, mxb = 1e6, mnb = -1e6;
	for(int i = 1;i <= n;i++){
		l = max(l, x[i] - mid);
		r = min(r, x[i] + mid);
		if(l > r) return false;
		d = max(d, y[i] - mid);
		u = min(u, y[i] + mid);
		if(d > u) return false;
		mnb = max(mnb, y[i] - x[i] - mid);
		mxb = min(mxb, y[i] - x[i] + mid);
		if(mnb > mxb) return false;
	}
	if(l > r || d > u || mnb > mxb || d - r > mxb || u - l < mnb) return false;
	for(int i = d;i <= u;i++){
		if(mnb <= i - l && i - l <= mxb && (i || l)){
			xx = l, yy = i;
			return true;
		}
		if(mnb <= i - r && i - r <= mxb && (i || r)){
			xx = r, yy = i;
			return true;
		}
	}
	for(int i = l;i <= r;i++){
		if(mnb <= d - i && d - i <= mxb && (i || d)){
			xx = i, yy = d;
			return true;
		}
		if(mnb <= u - i && u - i <= mxb && (i || u)){
			xx = i, yy = u;
			return true;
		}
	}
	return false;
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%s", s + 1);
		int len = strlen(s + 1);
		for(int j = 1;j <= len;j++){
			if(s[j] == 'N') x[i]++;
			else y[i]++;
		}
	}
	int l = 0, r = 1e6, mid;
	while(l < r){
		mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	check(l);
	printf("%d\n", l);
	for(int i = 1;i <= xx;i++) printf("N");
	for(int i = 1;i <= yy;i++) printf("B");
}