#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
char ch[60000];
int n;
int main(){
	scanf("%s",ch+1); n=strlen(ch+1); 
	for (int l=1;l*2<=n;l++){
		int now=l,p=0;
		for (int i=l+1;i<=n;i++){
			if (ch[i]==ch[now-l+1]) p++; else p=0;
			ch[++now]=ch[i]; if (p==l) {now-=l; p=0;}
		}
		n=now;
	}
	for (int i=1;i<=n;i++) putchar(ch[i]); cout<<endl; return 0;
}