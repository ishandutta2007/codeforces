#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
char s[maxn];
int a[maxn], b[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		bool tag = false;
		for(int i = 1;i <= n;i++){
			if(s[i] == '2'){
				if(!tag) a[i] = b[i] = 1;
				else a[i] = 0, b[i] = 2;
				continue;
			}
			if(s[i] == '1'){
				if(!tag) a[i] = 1, b[i] = 0, tag = true;
				else a[i] = 0, b[i] = 1;
				continue;
			}
			if(s[i] == '0'){
				a[i] = b[i] = 0;
			}
		}
		
		for(int i = 1;i <= n;i++) printf("%d", a[i]);puts("");
		for(int i = 1;i <= n;i++) printf("%d", b[i]);puts("");
	}
}