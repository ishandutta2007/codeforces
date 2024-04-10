#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
int a[maxn];

bool check(int x){
	for(int i = 1;i <= n;i++){
		if(abs(a[i] - (x + i - 1)) > 1) return false;
	}
	return true;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		puts(check(a[1] - 1) || check(a[1]) || check(a[1] + 1) ? "YES" : "NO");
	}
}