#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int n;
int h[maxn];
int sk[maxn], top;
int a[maxn], b[maxn], c[maxn], d[maxn];
int f[maxn];


int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &h[i]);
	for(int i = 1;i <= n;i++){
		while(top && h[sk[top]] < h[i]) --top;
		if(top) a[i] = sk[top];
		sk[++top] = i;
	}
	top = 0;
	for(int i = 1;i <= n;i++){
		while(top && h[sk[top]] > h[i]) --top;
		if(top) b[i] = sk[top];
		sk[++top] = i;
	}
	top = 0;
	for(int i = n;i;i--){
		while(top && h[sk[top]] > h[i]) --top;
		if(top) c[i] = sk[top];
		sk[++top] = i;
	}
	top = 0;
	for(int i = n;i;i--){
		while(top && h[sk[top]] < h[i]) --top;
		if(top) d[i] = sk[top];
		sk[++top] = i;
	}
	for(int i = 1;i <= n;i++) f[i] = 1e9;
	f[0] = -1;
	for(int i = 1;i <= n;i++){
		//printf("%d %d %d--\n", i, a[i], b[i]);
		f[i] = min(f[i], f[i - 1] + 1);
		if(a[i]) f[i] = min(f[i], f[a[i]] + 1);
		if(b[i]) f[i] = min(f[i], f[b[i]] + 1);
		if(c[i]) f[c[i]] = min(f[c[i]], f[i] + 1);
		if(d[i]) f[d[i]] = min(f[d[i]], f[i] + 1);
	}
	printf("%d", f[n]);
}