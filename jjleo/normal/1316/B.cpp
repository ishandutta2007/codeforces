#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int T, n;
char s[maxn], t[maxn];
int ans;

bool check(int x){
	int j = 1;
	for(int i = x;i <= n;i++, j++){
		if(s[i] < t[j]) return true;
		if(s[i] > t[j]) return false;
	} 
	if((n - x + 1) & 1){
		for(int i = x - 1;i;i--, j++){
			if(s[i] < t[j]) return true;
			if(s[i] > t[j]) return false;
		}
	}else{
		for(int i = 1;i < x;i++, j++){
			if(s[i] < t[j]) return true;
			if(s[i] > t[j]) return false;
		}
	}
		
	return false;
}


int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%s", &n, s + 1);
		for(int i = 1;i <= n;i++) t[i] = s[i];
		for(int i = 2;i <= n;i++){
			int k = 1;
			for(int j = 2;j <= n;j++){
				
			}
		}
		ans = 1;
		for(int i = 2;i <= n;i++){
			if(check(i)){
				ans = i;
				int j = 1;
				for(int k = i;k <= n;k++, j++) t[j] = s[k];
				if((n - i + 1) & 1) for(int k = i - 1;k;k--, j++) t[j] = s[k];
				else for(int k = 1;k < i;k++, j++) t[j] = s[k];
			}
		};
		for(int i = 1;i <= n;i++) printf("%c", t[i]);
		puts("");
		printf("%d\n", ans);
	}
}