#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int a[101000];
int lv[101000],rv[101000];
int mlen,pos;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	lv[1]=1;
	for(int i=2;i<=n;++i)
		lv[i]=(a[i]>a[i-1])?lv[i-1]+1:1;
	rv[n]=1;
	for(int i=n-1;i;--i)
		rv[i]=(a[i]>a[i+1])?rv[i+1]+1:1;
	for(int i=1;i<=n;++i)
		mlen=max(mlen,max(lv[i],rv[i]));
	for(int i=1;i<=n;++i)
		if(max(lv[i],rv[i])==mlen){
			if(pos){
				puts("0");return 0;
			}
			else pos=i;
		}
	if(lv[pos]==rv[pos]){
		if(lv[pos]%2==1)puts("1");
		else puts("0");
	}
	else puts("0");
	return 0;
}