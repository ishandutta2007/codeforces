#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

long long n;
char s[20] = "codeforces";
int a[20];
long long x = 1;

int main(){
	scanf("%lld", &n);
	for(int i = 0;i < 10;i++) a[i] = 1;
	for(int k = 2;x < n;k++){
		for(int i = 0;i < 10 && x < n;i++){
			x /= a[i], a[i]++, x *= a[i];
		}
	}
	for(int i = 0;i < 10;i++){
		for(int j = 1;j <= a[i];j++) printf("%c", s[i]);
	}
}