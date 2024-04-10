#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n;
int a[maxn];
int f[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	while(1){
		bool tag = false;
		for(int i = 1;i <= n;i++) if(a[i] & 1) tag = true;
		if(tag) break;
		for(int i = 1;i <= n;i++) a[i] /= 2;
	}
	int sum = 0;
	for(int i = 1;i <= n;i++) sum += a[i];
	if(sum & 1) return printf("0"), 0;
	f[0] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = sum;j - a[i] >= 0;j--) f[j] |= f[j - a[i]]; 
	}
	if(!f[sum / 2]) return printf("0"), 0;
	puts("1");
	for(int i = 1;i <= n;i++) if(a[i] & 1) return printf("%d", i), 0; 
}