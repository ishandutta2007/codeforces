#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		int l = n + 1, r = 0;
		for(int i = 1;i <= n;i++) if(s[i] == '0') l = min(l, i), r = max(r, i);
		if(r == 0) puts("0");
		else{
			bool tag = false;
			for(int i = l;i <= r;i++){
				if(s[i] == '1'){
					puts("2");
					tag = true;
					break;
				}
			}
			if(!tag) puts("1");
		}
	}
}