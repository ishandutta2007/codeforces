#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int a[maxn];
char s[maxn];
bool tag[maxn];
int f[maxn], g[maxn], sum[maxn];
vector<int> v; 

void solve(int l, int r){
	if(l > r) return;
	while(a[l] == 1 && l <= r){
		tag[l] = true;
		l++;
	}
	if(l > r) return;
	while(a[r] == 1){
		tag[r] = true;
		r--;
	}
	tag[r] = true;
	int val = 1;
	for(int i = l;i <= r;i++){
		val *= a[i];
		if(val >= 2 * (r - l + 1)) break;
	}
	if(val >= 2 * (r - l + 1)) return;
	v.clear(), sum[l - 1] = 1;
	for(int i = l;i <= r;i++){
		sum[i] = sum[i - 1] * a[i];
		if(a[i] ^ 1) v.push_back(i);
	}
	f[l - 1] = 0;
	for(int i = l - 1;i < r;i++){
		if(a[i + 1] == 1){
			if(f[i + 1] < f[i] + 1){
				f[i + 1] = f[i] + 1;
				g[i + 1] = i;
			}
		}
		for(int j = 0;j < v.size();j++){
			int x = v[j];
			if(x > i && f[x] < f[i] + sum[x] / sum[i]){
				f[x] = f[i] + sum[x] / sum[i];
				g[x] = i;
			}
		}
	}
	int x = g[r];
	while(x >= l){
		tag[x] = true;
		x = g[x];
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	if(len == 1){
		for(int i = 1;i <= n;i++){
			printf("%d", a[i]);
			if(i < n) printf("%c", s[1]);
		}
		return 0;
	}
	for(int i = 1;i <= len;i++) tag[s[i]] = true;
	if(len == 2){
		if(tag['+'] && tag['-']){
			for(int i = 1;i <= n;i++){
				printf("%d", a[i]);
				if(i < n) printf("+");
			}
			return 0;
		}else if(tag['*'] && tag['-']){
			printf("%d", a[1]);
			for(int i = 2;i <= n;i++){
				if(!a[i]){
					printf("-%d", a[i]);
					for(int j = i + 1;j <= n;j++) printf("*%d", a[j]);
					return 0;
				}
				printf("*%d", a[i]);
			}
			return 0;
		}
	}
	memset(tag, 0, sizeof(tag));
	int l = 1;
	for(int i = 1;i <= n;i++){
		if(a[i] == 0){
			solve(l, i - 1);
			l = i + 1;
			tag[i] = true;
		}
	}
	solve(l, n);
	for(int i = 1;i <= n;i++){
		printf("%d", a[i]);
		if(i < n) printf(tag[i] ? "+" : "*");
	}
}