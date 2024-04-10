#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1001000;
int n,m,d;
int Ap[maxn],Bp[maxn],at,bt;
long long Asum[maxn],Bsum[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int cmp(int x,int y){
	return x>y;
}
int main(){
	n=read();d=read()+1;m=read();
	for(register int i=0,x;i<n;++i){
		x=read();
		if(x>m)Ap[++at]=x;
		else Bp[++bt]=x;
	}
	sort(Ap+1,Ap+at+1,cmp);
	sort(Bp+1,Bp+bt+1,cmp);
	for(register int i=1;i<=n;++i){
		Asum[i]=Asum[i-1]+Ap[i];
		Bsum[i]=Bsum[i-1]+Bp[i];
	}
	long long ans=Bsum[n];
	for(register int i=1,x;i<=at;++i){
        x=n-(i-1)*d-1;
        if(x<0)break;
		ans=max(ans,Asum[i]+Bsum[x]);
    }
	printf("%lld\n",ans);
	return 0;
}