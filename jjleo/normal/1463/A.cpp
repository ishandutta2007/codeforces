#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, a[4];

int main(){
	scanf("%d", &t);
	while(t--){
		for(int i = 1;i <= 3;i++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + 3);
		puts((a[1] + a[2] + a[3]) % 9 == 0 && a[2] - a[1] + a[3] - a[1] <= 6 * a[1] ? "YES" : "NO");
	}
}