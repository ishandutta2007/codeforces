#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		long long b[2] = {0};
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), b[i & 1] += a[i];
		if(b[0] > b[1]){
			for(int i = 1;i <= n;i += 2) a[i] = 1;
		}else{
			for(int i = 2;i <= n;i += 2) a[i] = 1;
		}
		for(int i = 1;i <= n;i++) printf("%d ", a[i]);
		puts("");
	}
}