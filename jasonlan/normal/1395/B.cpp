#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,x,y;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main()
{
	n=read();m=read();x=read();y=read();
	printf("%d %d\n",x,y);
	for(register int i=x,id=x;i<n+x;++i,id=id%n+1)
		if(i&1){
			for(register int j=1;j<=m;++j)
				if(id!=x||j!=y)
					printf("%d %d\n",id,j);
		}
		else{
			for(register int j=m;j;--j)
				if(id!=x||j!=y)
					printf("%d %d\n",id,j);
		}
	return 0;
}