#include<bits/stdc++.h>
using namespace std;
const int M=1e5+9;
int n;
int p[M];
char c[M];
void work(){
	scanf("%s",c+1);
	n=strlen(c+1);
	int mi=1e9,ma=0;
	for(int i=1;i<=n;++i){
		if(c[i]=='0')mi=min(mi,i),ma=max(ma,i);
		p[i]=p[i-1]+c[i]-'0';
	}
	if(ma==0)puts("0");
	else {
		if(p[ma]-p[mi-1]==0)puts("1");
		else puts("2");
	}
}
int main(){
	int T;
	for(scanf("%d",&T);T;--T)work();
	return 0;
}