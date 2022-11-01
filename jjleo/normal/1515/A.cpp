#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, x;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &x);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		int sum = 0;
		bool tag = false;
		for(int i = 1;i <= n;i++){
			sum += a[i];
			if(tag) swap(a[i], a[i - 1]), tag = false;
			if(sum == x) tag = true;
		}
		puts(tag ? "NO" : "YES"); 
		if(!tag){
			for(int i = 1;i <= n;i++) printf("%d ", a[i]);
			puts("");
		}
	}
}