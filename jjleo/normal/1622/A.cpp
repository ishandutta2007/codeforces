#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, l1, l2, l3;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &l1, &l2, &l3);
		if(l2 == l3 && l1 % 2 == 0){
			puts("Yes");
			continue;
		}
		if(l1 == l2 + l3){
			puts("Yes");
			continue;
		}
		swap(l1, l2);
		if(l2 == l3 && l1 % 2 == 0){
			puts("Yes");
			continue;
		}
		if(l1 == l2 + l3){
			puts("Yes");
			continue;
		}
		swap(l1, l3);
		if(l2 == l3 && l1 % 2 == 0){
			puts("Yes");
			continue;
		}
		if(l1 == l2 + l3){
			puts("Yes");
			continue;
		}
		puts("No");
	}
}