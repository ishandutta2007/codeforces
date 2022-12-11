#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int a[101000],b[101000],lp,rp;
double ans;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void process(){
	n=read();
	lp=rp=0;
	for(int i=1,x,y;i<=(n<<1);++i){
		x=abs(read());y=abs(read());
		if(x==0)
			a[++lp]=y;
		else
			b[++rp]=x;
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	ans=0;
	for(int i=1;i<=n;++i)
		ans+=sqrt((double)a[i]*a[i]+(double)b[i]*b[i]);
	printf("%.15lf\n",ans);
}
int main(){
	int T=read();
	while(T--){
		process();
	}
	return 0;
}