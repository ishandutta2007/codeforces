#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
const int maxn=2e5+10;
const int mod=1e9+7;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f;
}
int n,m,p[maxn],mx,X,Y,cnt;
int dl[maxn],dr[maxn],Mx[maxn];
int main(){
	n=read();
	for(int i=1;i<=n;i++)p[i]=read();
	for(int i=1;i<=n;i++){
		dl[i]=i;if(i==1)continue;
		if(p[i-1]<p[i])dl[i]=dl[i-1];
	}
	for(int i=n;i;--i){
		dr[i]=i;if(i==n)continue;
		if(p[i+1]<p[i])dr[i]=dr[i+1];
	}
	for(int i=1;i<=n;i++)
		Mx[i]=max(i-dl[i],dr[i]-i);
	for(int i=1;i<=n;i++)
		if(mx<Mx[i])mx=Mx[i],X=i,cnt=1;
		else if(mx==Mx[i])++cnt;
	if(cnt>1||X==1||X==n)return puts("0")&0;
	if(Mx[X]>min(X-dl[X],dr[X]-X))return puts("0")&0;
	Y=(X-dl[X]>dr[X]-X?dl[X]:dr[X]);
	puts(((Y-X)&1)?"0":"1");
    return 0;
}
// wo ri ni xian ren