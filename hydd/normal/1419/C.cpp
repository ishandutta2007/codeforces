/*********************************************************************
 * SourceCodeforces
 * ProblemCF1419C
 * Authorhydd
 * Date2020/11/10
*********************************************************************/
#include<bits/stdc++.h>
using namespace std;
char Getchar(){
	static char now[1<<20],*S,*T;
	if (T==S){
		T=(S=now)+fread(now,1,1<<20,stdin);
		if (T==S) return EOF;
	}
	return *S++;
}
int read(){
	int x=0,f=1;
	char ch=Getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=Getchar();
	}
	while (ch<='9'&&ch>='0') x=x*10+ch-'0',ch=Getchar();
	return x*f;
}
int T,n,x,y;
int main(){
	T=read();
	while (T--){
		n=read(); x=read();
		bool flag=false; int s1=0,s2=0;
		for (int i=1;i<=n;i++){
			y=read();
			if (x==y) flag=true;
			s1+=abs(y-x); s2+=y-x;
		}
		if (!s1) puts("0");
		else if (!s2||flag) puts("1");
		else puts("2");
	}
	return 0;
}