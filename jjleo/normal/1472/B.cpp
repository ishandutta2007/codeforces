#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int f[205], x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		memset(f, 0, sizeof(f));
		f[0] = true;
		int sum = 0;
		while(n--){
			scanf("%d", &x);
			for(int i = x;i < 205;i++) f[i] |= f[i - x];
			sum += x;
		}
		puts(sum % 2 == 0 && f[sum / 2] ? "YES" : "NO");
	}
}