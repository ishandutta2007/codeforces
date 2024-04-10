#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, x;

int main(){
	scanf("%d", &t);
	while(t--){
		int sum = 0;
		for(int i = 1;i <= 4;i++) scanf("%d", &x), sum += x;
		if(sum == 0) puts("0");
		else if(sum == 4) puts("2");
		else puts("1");
	}
}