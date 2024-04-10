#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, x, m;
int a, b;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &x, &m);
		int l = x, r = x;
		for(int i = 1;i <= m;i++){
			scanf("%d%d", &a, &b);
			if((a <= l && l <= b) || (a <= r && r <= b)){
				l = min(l, a), r = max(r, b);
			}
		}
		printf("%d\n", r - l + 1);
	}
}