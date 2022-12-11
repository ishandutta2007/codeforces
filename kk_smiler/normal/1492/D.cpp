#include <bits/stdc++.h>
using namespace std;
int n,m,T,p,a,b,k;
char s[200010],t[200010];
int main(){
	scanf("%d%d%d",&a,&b,&k);
	if(a==0&&k) return puts("No"),0;
	if(k==a+b) return puts("No"),0;
	for(int i=1;i<=b;i++) s[i]=t[i]='1';
	for(int i=1;i<=a;i++) s[i+b]=t[i+b]='0';
	int nw=b+1;
	while(k--){
		if(nw<=a+b&&nw>b){
			if(nw-1>1) swap(t[nw-1],t[nw]),nw++;
			else return puts("No"),0;
		}
		else{
			if(nw==a+b+1) nw=b;
			if(nw-1>1) swap(t[nw-1],t[nw]),nw--;
			else return puts("No"),0;
		}
	}
	puts("Yes");
	puts(s+1);
	puts(t+1);
}