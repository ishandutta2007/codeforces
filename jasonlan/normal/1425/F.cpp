#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1010;
int n,pre,px;
int a[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int get(int l,int r){
	printf("? %d %d\n",l,r);
	cout.flush();
	scanf("%d",&l);
	return l;
}
int main(){
	n=read();
	pre=get(1,n);
	for(register int i=n-1;i>1;--i){
		px=get(1,i);
		a[i+1]=pre-px;
		pre=px;
	}
	px=get(2,3);
	a[2]=px-a[3];
	a[1]=pre-a[2];
	printf("!");
	for(register int i=1;i<=n;++i)
		printf(" %d",a[i]);
	return 0;
}