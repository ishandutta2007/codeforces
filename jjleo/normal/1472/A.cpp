#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, w, h, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &w, &h, &n);
		puts((w & -w) * (h & -h) >= n ? "YES" : "NO");
	}
}