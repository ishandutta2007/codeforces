#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n == 1){
			puts("FastestFinger");
			continue;
		}
		if(n & 1){
			puts("Ashishgup");
			continue;
		}
		int cnt = 0;
		int a = 0;
		while(n % 2 == 0) n /= 2, a++;
		for(int i = 3;i * i <= n && n != 1;i++){
			while(n % i == 0) n /= i, cnt++;
		}
		if(n != 1) cnt++;
		if(cnt > 1){
			puts("Ashishgup");
			continue;
		}
		if(a == 1){
			if(!(cnt & 1)) puts("Ashishgup");
			else puts("FastestFinger");
		}else{
			if(cnt & 1) puts("Ashishgup");
			else puts("FastestFinger");
		}
		
	}
}