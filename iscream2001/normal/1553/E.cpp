#include<bits/stdc++.h>
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
void init(){
	return;
}

int n,m;

int a[N];
int b[N];


int vis[N];

int tp;
int ans[N];
int pos[N];
void check(int K){
	int x,y,z;
	for(int i=1;i<=n;++i){
		x=i+K;
		if(x>n) x-=n;
		b[x]=i;
		pos[i]=x;
	}
	z=0;
	for(int i=1;i<=n;++i){
		if(a[i]==b[i]) continue;
		++z;
		pos[b[i]]=pos[a[i]];
		b[pos[a[i]]]=b[i];
		b[i]=a[i];
		pos[a[i]]=i;
	}
	if(z<=m) {
		ans[++tp]=K;
	}
	return;
}

void MAIN(){
	int x;
	scanf("%d%d",&n,&m);tp=0;
	for(int i=0;i<=n;++i) vis[i]=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;++i){
		x=i-a[i];
		if(x<0) x+=n;
		++vis[x];
	}
	x=n/3;
	for(int i=0;i<n;++i){
		if(vis[i]>=x){
			check(i);
		}
	}
	printf("%d",tp);
	for(int i=1;i<=tp;++i) printf(" %d",ans[i]);
	puts("");
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