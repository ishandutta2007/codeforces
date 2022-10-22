#include<bits/stdc++.h>
using namespace std;
const int M=2e5+9;
int n;
char s[M],a[M],b[M];
void work(){
	scanf("%d%s",&n,s+1);
	int x=0,num=0,tot=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='0'){
			num++;
			a[i]=x?'(':')';
			b[i]=x?')':'(';
			x^=1;
		} 
	}
	if(num%2||n%2||s[1]!='1'||s[n]!='1'){
		printf("NO\n");
		return;
	}
	for(int i=1;i<=n;++i){
		if(s[i]=='1'){
			tot++;
			a[i]=(tot<=(n-num)/2)?'(':')';
			b[i]=(tot<=(n-num)/2)?'(':')';
		} 
	}
	printf("YES\n");
	for(int i=1;i<=n;++i)printf("%c",a[i]);printf("\n");
	for(int i=1;i<=n;++i)printf("%c",b[i]);printf("\n");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*
1
4
1001

*/