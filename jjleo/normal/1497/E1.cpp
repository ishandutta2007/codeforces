#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n, k;
int a[maxn];
int p[maxn], cnt;
bool tag[10000086];

int main(){
	scanf("%d", &t);
	for(int i = 2;i * i <= 1e7;i++){
		if(!tag[i]) p[++cnt] = i;
		for(int j = 1;j <= cnt && p[j] * i * p[j] * i <= 1e7;j++){
			tag[p[j] * i] = true;
			if(i % p[j] == 0) break;
		}
	}
	for(int i = 2;i * i <= 1e7;i++) tag[i] = false;
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 1;i <= n;i++){
			scanf("%d", &a[i]);
			for(int j = 1;j <= cnt;j++){
				int x = 0;
				while(a[i] % p[j] == 0){
					a[i] /= p[j], x++;
				}
				if(x & 1) a[i] *= p[j];
			}
		}
		int l = 1, ans = 0;
		tag[a[1]] = true;
		for(int i = 2;i <= n;i++){
			if(tag[a[i]]){
				for(int j = l;j < i;j++) tag[a[j]] = false;
				l = i;
				ans++;
			}
			tag[a[i]] = true;
		}
		for(int i = l;i <= n;i++) tag[a[i]] = false;
		printf("%d\n", ans + 1);
	}
}