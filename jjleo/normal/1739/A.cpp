#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, m;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		printf("%d %d\n", min(2, n), min(2, m));
	}
}