#include<bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=998244353;
const int N=1e5+10;
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
int a[N];
struct Node{
	int l,r;
}b[N];
bool cmp(Node x,Node y){
	return x.l<y.l;
}
void MAIN(){
	int u,v;
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n+n;++i) a[i]=0;
	for(int i=1;i<=K;++i){
		scanf("%d%d",&b[i].l,&b[i].r);
		a[b[i].l]=1;
		a[b[i].r]=1;
		if(b[i].l>b[i].r) swap(b[i].l,b[i].r);
	}
	int j=1;
	for(int i=K+1;i<=n;++i){
		while(a[j]) ++j;
		b[i].l=j;a[j]=1;
	}
	for(int i=K+1;i<=n;++i){
		while(a[j]) ++j;
		b[i].r=j;a[j]=1;
	}
	sort(b+1,b+1+n,cmp);
	int ans=0;
	for(int i=1;i<=n;++i){
	//	cout<<"now "<<b[i].l<<" "<<b[i].r<<endl;
		for(j=1;j<i;++j){
			if(b[j].r>b[i].l&&b[j].r<b[i].r) ++ans;
		}
	}
	printf("%d\n",ans);
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
735134400
*/