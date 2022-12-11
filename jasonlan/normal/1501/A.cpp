#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1000;
int n;
int a[maxn],b[maxn],tm[maxn];
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
void process(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		b[i]=read();
	}
	for(int i=1;i<=n;++i)
		tm[i]=read();
	int ans=0,dout;
	for(int i=1;i<=n;++i){
		dout=max(b[i-1],ans+(b[i-1]-a[i-1]+1)/2);
		ans=dout+(a[i]-b[i-1]+tm[i]);
	}
	printf("%d\n",ans);
}
int main(){
	int T=read();
	while(T--)process();
    return 0;
}