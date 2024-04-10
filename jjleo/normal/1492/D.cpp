#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int k, a, b, A, B;

int main(){
	scanf("%d%d%d", &a, &b, &k);
	if(b == 1){
		if(k) return printf("No"), 0;
		puts("Yes");
		printf("1");for(int i = 1;i <= a;i++) printf("0");
		puts("");
		printf("1");for(int i = 1;i <= a;i++) printf("0");
		return 0;
	}else if(a == 0){
		if(k) return printf("No"), 0;
		puts("Yes");
		for(int i = 1;i <= b;i++) printf("1");
		puts("");
		for(int i = 1;i <= b;i++) printf("1");
		return 0;
	}
	if(k > a + b - 2) return printf("No"), 0;
	puts("Yes");
	if(k <= a){
		for(int i = 1;i <= b;i++) printf("1");
		for(int i = 1;i <= a;i++) printf("0");
		puts("");
		for(int i = 1;i <= b - 1;i++) printf("1");
		for(int i = 1;i <= k;i++) printf("0");
		printf("1");
		for(int i = 1;i <= a - k;i++) printf("0");
		return 0;
	}
	for(int i = 1;i <= b;i++) printf("1");
	for(int i = 1;i <= a;i++) printf("0");
	puts("");
	for(int i = 1;i <= b;i++) printf("%d", i != a + b - k);
	for(int i = 1;i <= a - 1;i++) printf("0");
	printf("1");
	
		
	
}