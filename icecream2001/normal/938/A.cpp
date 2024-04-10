#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
#define LL long long
using namespace std;
int n,top=0;
char s[200],c[200];
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='y'){
			if(!top){
				c[++top]=s[i];
			}
		}
		else{
			while(top){
				printf("%c",c[top]);top--;
			}
			printf("%c",s[i]);
		}
	}
	while(top){
		printf("%c",c[top]);top--;
	}
	return 0;
}