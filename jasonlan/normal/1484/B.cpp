#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=301100;
int n,m;
int a[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1==-'-'?-res:res;
}
void process(){
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	if(a[2]>a[1]||n==1){
		for(int i=2;i<=n;++i)
			if(a[i]-a[i-1]!=a[2]-a[1]){
				int delta=a[2]-a[1];
				if(a[i]>delta-1){
					puts("-1");return;
				}
				m=a[i-1]-a[i]+delta;
				for(int j=2;j<=n;++j)
					if(a[j]!=(a[j-1]+delta)%m){
						puts("-1");return;
					}
				printf("%d %d\n",m,delta);
				return;
			}
		puts("0");
		return;
	}
	else if(a[2]==a[1]){
		for(int i=2;i<=n;++i)
			if(a[i]!=a[i-1]){
				puts("-1");return;
			}
		puts("0");
		return;
	}
	else{
		for(int i=2;i<=n;++i)
			if(a[i]-a[i-1]!=a[2]-a[1]){
				int delta=a[2]-a[1];
				if(a[i-1]>=-delta){
					puts("-1");return;
				}
				m=-(a[i-1]-a[i]+delta);
				if(m<=a[1]){
					puts("-1");return;
				}
				for(int j=2;j<=n;++j)
					if(a[j]!=(a[j-1]+delta+m)%m){
						puts("-1");return;
					}
				printf("%d %d\n",m,m+delta);
				return;
			}
		puts("0");
		return;
	} 
}
int main(){
	int T=read();
	while(T--)process();
	return 0;
}