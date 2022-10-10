#include<stdio.h>
#include<iostream>
using namespace std;
const int maxk=12;
int T,n;
int bitcnt[1<<maxk];
string s;
int dfs(int len,int S,int lst,int flg){
	if(flg==0){
		if(len+bitcnt[S]<=n){
			for(int i=0;i<len-1;i++)
				putchar(s[i]);
			putchar(lst+48);
			for(int i=1;i+len+bitcnt[S]<=n;i++)
				putchar('9');
			for(int i=9;i>=0;i--)
				if((S>>i)&1)
					putchar(i+48);
			return 1;
		}
		return 0;
	}
	int f=len==0? 1:0;
	for(int i=s[len]-48;i>=f;i--)
		if(dfs(len+1,S^(1<<i),i,i==s[len]-48))
			return 1;
	return 0;
}
int main(){
	for(int i=1;i<1024;i++)
		bitcnt[i]=bitcnt[i>>1]+(i&1);
	scanf("%d",&T);
	while(T--){
		cin>>s,n=s.size();
		if(dfs(0,0,10,1)==0)
			for(int i=0;i<n-2;i++)
				putchar('9');
		puts("");
	}
	return 0;
}