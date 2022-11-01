#include <bits/stdc++.h>
#define maxn 40086

using namespace std;

const int p = 1e9 + 7;

int t, n;
int f[maxn];

bool check(int n){
	int b[10];
	int tot = 0;
	while(n) b[++tot] = n % 10, n /= 10;
	for(int i = 1;i <= tot - i + 1;i++) if(b[i] ^ b[tot - i + 1]) return false;
	return true;
}

int main(){
	f[0] = 1;
	for(int i = 1;i < maxn;i++){
		if(check(i)){
			for(int j = i;j < maxn;j++) f[j] = (f[j] + f[j - i]) % p;
		}
	}
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%d\n", f[n]);
	}
}