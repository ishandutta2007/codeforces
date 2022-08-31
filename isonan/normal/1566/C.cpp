#include <cstdio>
#include <cstring>
#include <algorithm>

int t;
char str[2][100001];
int f[100001];
int calc(int x){
	if(str[0][x]!='0'&&str[1][x]!='0')return 0;
	if(str[0][x]!='1'&&str[1][x]!='1')return 1;
	return 2;
}
int calc2(int x){
	if(str[0][x]!='0'&&str[1][x]!='0'&&str[0][x-1]!='0'&&str[1][x-1]!='0')return 0;
	if(str[0][x]!='1'&&str[1][x]!='1'&&str[0][x-1]!='1'&&str[1][x-1]!='1')return 1;
	return 2;
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		int n;
		scanf("%d",&n);
		for(int i=0;i<2;++i)scanf("%s",str[i]+1);
		f[0]=0;
		for(int i=1;i<=n;++i){
			f[i]=0;
			f[i]=f[i-1]+calc(i);
			if(i>1)f[i]=std::max(f[i],f[i-2]+calc2(i));
		}
		printf("%d\n",f[n]);
	}
}