#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		for(int i = 1;i <= 4;i++) scanf("%d", &a[i]);
		int x = max(a[1], a[2]), y = max(a[3], a[4]); 
		sort(a + 1, a + 4 + 1);
		puts(x == a[3] && y == a[4] || y == a[3] && x == a[4] ? "YES" : "NO");
	} 
}