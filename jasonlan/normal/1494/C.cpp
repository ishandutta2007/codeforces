#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[201000],b[201000],cnta[201000];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int GetSec(){
	int ap=0,bp=0,cbox=0,res=0,pos;
	memset(cnta,0,sizeof(0));
	while(ap<n&&a[ap+1]<0){
		++ap;
		while(bp<m&&b[bp+1]<=a[ap])++bp;
		cnta[ap]=cnta[ap-1]+(b[bp]==a[ap]);
	}
	while(bp){
		if(ap==0||b[bp]>a[ap]){
			pos=upper_bound(b+1,b+1+m,b[bp]+cbox-1)-b-1;
			res=max(res,cnta[ap]+(pos-bp+1));
			--bp;
		}
		else{
			++cbox;
			--ap;
		}
	}
	return res;
}
void process(){
	n=read();m=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	for(int i=1;i<=m;++i)
		b[i]=read();
	int ans=GetSec();
	for(int i=1;i<=n;++i)
		a[i]=-a[i];
	for(int i=1;i<=m;++i)
		b[i]=-b[i];
	reverse(a+1,a+1+n);
	reverse(b+1,b+1+m);
	ans+=GetSec();
	printf("%d\n",ans);
}
int main(){
	int T=read();
	b[0]=-1e9-7;
	while(T--)
		process();
	return 0;
}