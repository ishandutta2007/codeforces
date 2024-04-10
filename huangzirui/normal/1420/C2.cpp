#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=300010;
int i,j,k,n,m,a[maxn],is[maxn];ll dp[maxn][2],ans;
void check(int x){
	if(x<=0 || x>n)return;
	if((a[x-1]<a[x] && a[x]<a[x+1])||(a[x-1]>a[x] && a[x]>a[x+1])){
		ans+=(0-is[x])*a[x];
		is[x]=0;
	}if(a[x-1]<a[x] && a[x]>a[x+1]){
		ans+=(1-is[x])*a[x];
		is[x]=1;
	}if(a[x-1]>a[x] && a[x]<a[x+1]){
		ans+=(-1-is[x])*a[x];
		is[x]=-1;
	}
}
int main(){
	int T=read();
	while(T--){
		n=read();m=read();
		for(i=1;i<=n;i++)a[i]=read();ans=0;
		int Is=0;ans=0;
		a[0]=a[n+1]=-1e9;is[n+1]=0;
		for(i=1;i<=n;i++){
			if(!Is && a[i]>a[i+1])is[i]=1,ans+=a[i],Is=1;
			else if(Is && a[i]<a[i+1])is[i]=-1,ans-=a[i],Is=0;
			else is[i]=0;
		}printf("%I64d\n",ans);
//		for(j=1;j<=n;j++)cout<<":"<<a[j]<<' '<<is[j]<<endl;
		for(i=1;i<=m;i++){
			int x=read(),y=read();
			swap(a[x],a[y]);swap(is[x],is[y]);
			check(x-1);check(x);check(x+1);
			check(y-1);check(y);check(y+1);
			printf("%I64d\n",ans);
//			for(j=1;j<=n;j++)cout<<":"<<a[j]<<' '<<is[j]<<endl;
		}
	}
	return 0;
}