#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((ch!='-')&&(!isdigit(ch))) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
char S[1001010];
int n,i,ans;
void Main(){
	n=read();
	scanf("%s",S+1);S[0]=' ';
	ans=0;
	for (i=1;i<=n*2;i++)
	    if ((S[i]=='(')&&(S[i-1]=='(')) ans++;
	printf("%d\n",ans+1);
	return ;
}
int main(){
	int Testing=read();
	for (;Testing;Testing--) Main();
	return 0;
}