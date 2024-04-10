#include <bits/stdc++.h>
using namespace std;
 
int n,t,i;
char sb[114514];
 
int main(){
	scanf("%d\n",&t);
	while(t--){
		gets(sb);
		n=strlen(sb);
		printf("%c",sb[0]);
		for(i=1;i<=strlen(sb)-1;i+=2){
			printf("%c",sb[i]);
		}puts("");
	}
	return 0;
}