#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
bool s[maxn];
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++){
			scanf("%d", &a[i]);
			s[a[i]] = true;
		}
		for(int i = 1;i <= 2047;i++){
			int cnt = 0;
			for(int j = 1;j <= n;j++){
				if(s[a[j] ^ i]) cnt++;
			}
			if(cnt == n){
				printf("%d\n", i); 
				break;
			}
			if(i == 2047) puts("-1");
		}
		for(int i = 1;i <= n;i++){
			s[a[i]] = false;
		}
	}
}