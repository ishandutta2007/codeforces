#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int a[maxn], x, y;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	int ans = 0;
	for(int i = 1;i <= n;i++){
		if(a[i] != x && a[i] != y){
			if(a[i + 1] == x) x = a[i], ans++;
			else y = a[i], ans++;
		}else if(a[i] != x) x = a[i], ans++;
		else if(a[i] != y) y = a[i], ans++;
	}
	printf("%d", ans);
}