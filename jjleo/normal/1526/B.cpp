#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int mx = 11 * 111 - 11 - 111;
int f[maxn];

int main(){
	f[0] = 1;
	for(int i = 11;i <= mx;i++) f[i] |= f[i - 11];
	for(int i = 111;i <= mx;i++) f[i] |= f[i - 111];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		puts(n > mx || f[n] ? "YES" : "NO");
	}
}