#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, r, b;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &r, &b);
		for(int i = 1;i <= b + 1;i++){
			for(int j = 1;j <= r / (b + 1);j++) printf("R");
			if(i <= r % (b + 1)) printf("R");
			if(i < b + 1) printf("B");
		}
		puts("");
	}
}