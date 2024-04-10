#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, m;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		puts(n % m ? "NO" : "YES");
	} 
}