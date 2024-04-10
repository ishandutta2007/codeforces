#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
char s[maxn];
int n, x;

int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s%d", s + 1, &x);
		n = strlen(s + 1);
		for(int i = 1;i <= n;i++) a[i] = -1;
		bool tag = false;
		for(int i = 1;i <= n;i++){
			if(i - x <= 0 && i + x > n){
				if(s[i] == '1'){
					tag = true;
					break;
				}
			}
			if(i - x <= 0){
				a[i + x] = s[i] - '0';
			}else if(i + x > n){
				if(a[i - x] == -1) a[i - x] = s[i] - '0';
				else if(a[i - x] != s[i] - '0'){
					tag = true;
					break;
				}
			}else{
				if(s[i] == '0'){
					a[i + x] = 0;
					if(a[i - x] == -1) a[i - x] = 0;
					else if(a[i - x] == 1){
						tag = true;
						break;
					} 
				}else{
					if(a[i - x] != 0) a[i - x] = 1;
					else a[i + x] = 1;
				}	
			}
		}
		if(tag) puts("-1");
		else{
			for(int i = 1;i <= n;i++) printf("%d", a[i] == -1 ? 1 : a[i]);
			puts("");
		}
	}
}