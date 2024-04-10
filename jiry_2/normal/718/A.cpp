#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char ch[210000],ans[210000];
int n,t,ne[210000],where;
void change(int k){
	int len;// cout<<k<<endl;
	if (k!=n+1){
		if (k==where+1){
			len=0;
			int rem=1;
			for (int i=where-1;i;i--){
				rem+=ch[i]-'0';
				ans[++len]=rem%10+'0'; rem/=10;
			}
			if (rem>0){
				ans[++len]=rem+'0';
			}
		} else {
			len=0; int rem=1;
			for (int i=k-1;i;i--)
				if (ch[i]=='.'){
					ans[++len]='.';
				} else {
					rem+=ch[i]-'0';
					ans[++len]=rem%10+'0'; rem/=10;
				}
			if (rem>0){
				ans[++len]=rem+'0';
			}
		}
	} else {
		len=n;
		for (int i=1;i<=n;i++) ans[n-i+1]=ch[i];
	}
	for (int i=len;i;i--) putchar(ans[i]); putchar('\n');
}
int main(){
	scanf("%d%d",&n,&t);
	scanf("%s",ch+1);
	for (int i=1;i<=n;i++) if (ch[i]=='.') where=i;
	ne[n+1]=2e9;
	for (int i=n;i>where;i--)
		if (ch[i]>='5') ne[i]=i;
		else if (ch[i]=='4') ne[i]=ne[i+1];
		else ne[i]=2e9;
	for (int i=where+1;i<=n+1;i++)
		if (i==n+1||ne[i]-i+1<=t){
			change(i); return 0;
		}
}