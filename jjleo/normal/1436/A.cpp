#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, m;
int x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		while(n--){
			scanf("%d", &x);
			m -= x;
		}
		puts(m ? "NO" : "YES");
	}
}