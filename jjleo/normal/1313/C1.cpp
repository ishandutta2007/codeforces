#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

typedef long long ll;

int n;
int a[maxn], b[maxn];
ll l[maxn], r[maxn], ans;
int id;
int sk[maxn], top;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	top = 1;
	for(int i = 1;i <= n;i++){
		while(a[i] <= a[sk[top]]) --top;
		l[i] = l[sk[top]] + 1ll * (i - sk[top]) * a[i];
		sk[++top] = i;
	}
	sk[top = 1] = n + 1;
	for(int i = n;i;i--){
		while(a[i] <= a[sk[top]]) --top;
		r[i] = r[sk[top]] + 1ll * (sk[top] - i) * a[i];
		sk[++top] = i;
	}
	for(int i = 0;i <= n;i++){
		if(l[i] + r[i] - a[i] > ans) ans = l[i] + r[i] - a[i], id = i;
	}
	b[id] = a[id];
	for(int i = id - 1;i;i--) b[i] = min(b[i + 1], a[i]);
	for(int i = id + 1;i <= n;i++) b[i] = min(b[i - 1], a[i]);
	for(int i = 1;i <= n;i++) printf("%d ", b[i]);
}