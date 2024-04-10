#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

int n;
int a[maxn];
int l[maxn], r[maxn];
int f[maxn];
int cnt[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]), r[a[i]] = i;
	for(int i = n;i;i--) l[a[i]] = i;
	for(int i = n;i;i--){
		cnt[a[i]]++;
		f[i] = f[i + 1];
		if(l[a[i]] == i) f[i] = max(f[i], f[r[a[i]] + 1] + cnt[a[i]]);
		else f[i] = max(f[i], cnt[a[i]]);
	}
	printf("%d", n - f[1]);
}