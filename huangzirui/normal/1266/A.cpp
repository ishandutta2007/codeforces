#include<stdio.h>
#include<iostream>
using namespace std;
int T;
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		cin>>s;
		int cnt=0,tot=0,ok=0;
		for(int i=0;i<s.size();i++)
			cnt+=s[i]=='0',tot+=s[i]-48,ok+=(s[i]%2==0);
		if(cnt>=1&&tot%3==0&&ok>=2)
			puts("red");
		else puts("cyan");
	}
	return 0;
}