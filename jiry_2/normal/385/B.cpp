#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
char ch[40000];
int n,ans;
int main(){
	scanf("%s",ch+1); n=strlen(ch+1); int pre=1;
	for (int i=1;i<=n-3;i++) if (ch[i]=='b'&&ch[i+1]=='e'&&ch[i+2]=='a'&&ch[i+3]=='r') {ans+=(i-pre+1)*(n-(i+3)+1); pre=i+1;}
	cout<<ans<<endl; return 0;
}