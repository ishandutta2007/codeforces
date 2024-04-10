#include<bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=1e9+7;
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
void init(){
	return;
}

int n,K;
int a[2010];
int f[2010][2010];
void MAIN(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		a[i]=i-a[i];
	}
	
	//for(int i=1;i<=n;++i) cout<<a[i]<<" ";puts("");
	for(int i=0;i<=n;++i){
		for(int j=0;j<=i;++j){
			f[i][j]=0;
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<=i;++j){
			f[i+1][j+1]=max(f[i+1][j+1],f[i][j]);
			if(a[i+1]==j) f[i+1][j]=max(f[i+1][j],f[i][j]+1);
			else f[i+1][j]=max(f[i+1][j],f[i][j]);
		}
	}
	int ans=n+1;
	for(int i=0;i<=n;++i){
		if(f[n][i]>=K){
			ans=i;
			break;
		}
	}
	if(ans>n) puts("-1");
	else printf("%d\n",ans);
	return;
}
int main(){
//	freopen("1.in","r",stdin);
	init();
	int ttt=1;scanf("%d",&ttt);
	while(ttt--) MAIN();
	return 0;	
}
/*
*/