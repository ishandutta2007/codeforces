#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

const int p = 998244353, inv2 = p + 1 >> 1;

int n, m;
string s[maxn];
int f[maxn];

int main(){
	for(int i = 1, j = inv2;i < maxn;i++, j = 1ll * j * inv2 % p){
		if(i == 1) continue;
		if(i & 1) f[i] = (f[i - 2] + j) % p;
		else f[i] = (f[i - 1] + j) % p;
	}
	scanf("%d%d", &n, &m);
	for(int i = 0;i < n;i++) cin >> s[i];
	int w = 0, ans = 0;
	for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) w += s[i][j] == 'o';
	for(int i = 0;i < n;i++){
		int sum = 0;
		for(int j = 0;j < m;j++){
			if(s[i][j] == 'o') sum++;
			else sum = 0;
			ans = (ans + f[sum]) % p;
		}
	}
	for(int j = 0;j < m;j++){
		int sum = 0;
		for(int i = 0;i < n;i++){
			if(s[i][j] == 'o') sum++;
			else sum = 0;
			ans = (ans + f[sum]) % p;
		}
	}
	for(int i = 1;i <= w;i++) ans = (ans + ans) % p;
	printf("%d", ans);
}