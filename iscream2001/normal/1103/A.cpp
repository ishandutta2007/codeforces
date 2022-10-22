#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e5+10;
int n;
int A=0,B=0;
char s[N];
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;++i){
		if(s[i]=='0'){
			if(A==0) puts("3 4");
			else puts("1 4");
			A^=1;
		}
		else{
			if(B==0) puts("1 1");
			else puts("1 3");
			B^=1;
		}
	} 
	return 0;
}