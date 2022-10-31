#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll sb[11],i,j,n,m,tmp=1;
char s[11]="codeforces";
int main(){
	scanf("%llu",&n);
	m=floor(pow(n,0.1));
	for(i=1;i<=10;i++){
		sb[i]=m;
		tmp*=m;
	}
	for(i=1;i<=10;i++){
		if(tmp>=n){break;}
		sb[i]++;
		tmp/=m;tmp*=(m+1);
		if(tmp>=n){break;}
	}
	for(i=1;i<=10;i++){
		for(j=1;j<=sb[i];j++){
			printf("%c",s[i-1]);
		}
	}
}