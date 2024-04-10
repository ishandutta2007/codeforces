#include<bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=998244353;
const int N=2e5+10;
const LL INF=1e18;
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
struct Node{
	int x,y,z;
}a[N];
LL tr[N+N];
void add(int x,LL y){
	while(x<=n+n){
		tr[x]+=y;
		x+=x&-x;
	}
} 
LL ask(int x){
	LL re=0;
	while(x){
		re+=tr[x];
		x-=x&-x;
	}
	return re;
}
LL F[N];
int b[N+N];
map<int,int> mp;
void MAIN(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		b[i]=a[i].x;
		b[i+n]=a[i].y;
	}
	sort(b+1,b+1+n+n);
	for(int i=1;i<=n+n;++i) mp[b[i]]=i;
	LL re;
	for(int i=1;i<=n;++i){
		F[i]=abs(a[i].x-a[i].y);
		u=mp[a[i].x];
		v=mp[a[i].y];
		F[i]+=ask(u)-ask(v);
		F[i]=F[i]%P;
		add(u,F[i]);
	}
	int now=0;
	LL ans=0;
	for(int i=1;i<=n;++i){
		ans+=abs(now-a[i].x);
		if(a[i].z) ans+=F[i];
		now=a[i].x;
	}
	ans=(ans%P+P)%P;
	ans=(ans+(LL)1)%P;
	printf("%lld\n",ans);
	return;
}
int main(){
//	freopen("1.in","r",stdin);
	init();
	int ttt=1;//scanf("%d",&ttt);
	while(ttt--) MAIN();
	return 0;	
}
/*
735134400
*/