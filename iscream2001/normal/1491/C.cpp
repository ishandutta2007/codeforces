#include <bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=998244353;
const int N=3e5+10;
const int INF=1e9;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
void pls(LL &x,LL y){
    x+=y;if(x>=P)x-=P;
}
int n;
LL a[N],b[N],c[N];
void MAIN(){
    n=read();
    for(int i=1;i<=n;++i) {
    	a[i]=read();
    	b[i]=0;c[i]=0;
	}
	b[0]=c[0]=0;
    LL ans=0;
    for(int i=1;i<=n;++i){
    	//a[i]=a[i]-b[i];
    	//b[i]=0;
    	//a[i]=max(a[i],(LL)1);
    	c[i]=c[i-1]+c[i];
    	b[i]+=c[i];
    	if(b[i]<a[i]-1) {
    		ans+=(a[i]-1)-b[i];
    		b[i]=a[i]-1;
		}
		if(a[i]+(LL)i<=n) c[a[i]+i+1]--;
		c[i+2]++;
		b[i]-=(a[i]-1);
		b[i+1]+=b[i];
	}
	printf("%lld\n",ans);
	return;
}

int main(){
    int ttt=read();
    while(ttt--) MAIN();
    return 0;
}