#include <bits/stdc++.h>
using namespace std;

int n,i,t,p,s,r;
char sb[200500];
int main(){
	scanf("%d\n",&t);
	while(t--){
		gets(sb);p=s=r=0;
		n=strlen(sb);
		for(i=0;i<=n-1;i++){
			if(sb[i]=='R'){p++;}
			if(sb[i]=='P'){s++;}
			if(sb[i]=='S'){r++;}
		}
		
		if(p>=s&&p>=r){for(i=0;i<=n-1;i++){putchar('P');}puts("");continue;}
		if(s>=p&&s>=r){for(i=0;i<=n-1;i++){putchar('S');}puts("");continue;}
		if(r>=p&&r>=s){for(i=0;i<=n-1;i++){putchar('R');}puts("");continue;}
		
	}
}