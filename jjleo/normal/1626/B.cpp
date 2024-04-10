#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

int t;
char s[maxn];
int a[maxn];
int n;

void solve(){
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(int i = 1;i <= n;i++) a[i] = s[i] - '0';
	bool tag = false; 
	for(int i = 1;i < n;i++) if(a[i] + a[i + 1] > 9) tag = true;
	if(tag){
		for(int i = n - 1;i;i--) if(a[i] + a[i + 1] > 9){
			for(int j = 1;j < i;j++) printf("%d", a[j]);
			printf("%d%d", 1, a[i] + a[i + 1] - 10);
			for(int j = i + 2;j <= n;j++) printf("%d", a[j]);
			return;
		} 
	}else{
		for(int i = 1;i < n;i++){
			if(a[i] + a[i + 1] > a[i]){
				for(int j = 1;j < i;j++) printf("%d", a[j]);
				printf("%d", a[i] + a[i + 1]);
				for(int j = i + 2;j <= n;j++) printf("%d", a[j]);
				return;
			}
		}
		s[n] = 0;
		printf("%s", s + 1);
	}
}

int main(){
	scanf("%d", &t);
	while(t--) solve(), puts("");
}