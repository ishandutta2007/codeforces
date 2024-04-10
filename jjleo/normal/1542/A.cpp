#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[2], x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		a[0] = a[1] = 0;
		for(int i = 1;i <= 2 * n;i++){
			scanf("%d", &x);
			a[x & 1]++;
		}
		puts(a[0] == a[1] ? "Yes" : "No");
	}
}