#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=110;
int n,k,a[maxn];
inline int read(){
    int res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
void Proc(){
	n=read();k=read();
	for(int i=0;i<n;++i)
		a[i]=read();
	for(int i=0;i<n-1;++i)
		if(k>a[i]){
			k-=a[i];a[n-1]+=a[i];a[i]=0;
		}
		else{
			a[i]-=k;a[n-1]+=k;break;
		}
	for(int i=0;i<n;++i)
		printf("%d ",a[i]);
	printf("\n");
}
int main(){
	int T=read();
	while(T--)Proc();
    return 0;
}