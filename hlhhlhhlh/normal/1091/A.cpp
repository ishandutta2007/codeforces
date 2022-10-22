// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int i,j,k;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int x,y,z,t;
int main(){
	x=read(); y=read(); z=read();
	t=min(x,y-1); t=min(t,z-2);
	printf("%d\n",t*3+3);
	return 0;
}