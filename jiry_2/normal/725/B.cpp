#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char ch[1000];
long long n;
const int w[6]={4,5,6,3,2,1};
int main(){
	scanf("%s",ch+1); int len=strlen(ch+1);
	for (int i=1;i<len;i++) n=n*10+ch[i]-'0';
	long long ans=w[ch[len]-'a'];
	ans+=(n-1)/4*16+((n-1)%2)*7;
	cout<<ans<<endl;
	return 0;
}