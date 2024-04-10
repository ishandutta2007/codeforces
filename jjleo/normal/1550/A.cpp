#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;;i++){
			if(i * i >= n){
				printf("%d\n", i);
				break;
			}
		} 
	}
}