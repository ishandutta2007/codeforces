#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, k; 
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%s", &n, &k, s + 1);
		bool tag = false;
		for(int i = 1;i < n - i + 1;i++) if(s[i] ^ s[n - i + 1]) tag = true;
		puts(k == 0 || !tag ? "1" : "2");
	}
}