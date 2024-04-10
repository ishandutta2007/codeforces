#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int l, r;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &l, &r);
		puts(l * 2 >= r + 1 ? "YES" : "NO");
	}
}