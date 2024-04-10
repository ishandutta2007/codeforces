#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int p[maxn], cnt;
bool tag[maxn];
int a[maxn];

bool solve(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= cnt;i++){
		int l = 0, r = 100;
		for(int j = 1;j <= n;j++){
			int x = 0, y = a[j];
			while(y % p[i] == 0) y /= p[i], x++;
			if(x > r) return false;
			if(x < l) l = r = x;
			else l = x, r = 100;
		}
	}
	return true;
}

int main(){
	for(int i = 2;i < maxn / 10;i++){
		if(!tag[i]) p[++cnt] = i;
		for(int j = 1;j <= cnt && p[j] * i < maxn / 10;j++){
			tag[p[j] * i] = true;
			if(i % p[j] == 0) break;
		} 
	}
	scanf("%d", &t);
	while(t--) puts(solve() ? "YES" : "NO");
}