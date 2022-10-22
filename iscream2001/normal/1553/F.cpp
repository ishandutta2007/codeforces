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

const int M=3e5;

int n;
int a[N];
LL F[N];
LL A[N],B[N],C[N];
void add(LL *t,int x,LL y){
	while(x<=M){
		t[x]+=y;
		x+=x&-x;
	}
	return;
}
LL ask(LL *t,int x){
	LL re=0;
	while(x){
		re+=t[x];
		x-=x&-x;
	}
	return re;
}
void MAIN(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	F[0]=0;
	LL ss=0;
	LL num,sum,w;
	for(int i=1;i<=n;++i){
		F[i]=F[i-1];
		//sum=ask(A,a[i]);
		//num=ask(C,a[i]);
		//F[i]+=ask(A,a[i]);
		F[i]+=(LL)a[i]*(LL)(i-1);
		F[i]-=ask(B,a[i]);
		//F[i]+=ask(A)
		F[i]+=ss;
	//	cout<<i<<" "<<F[i]<<endl;
		w=0;
		for(int j=a[i],k;j<=M;j=k+1){
			w+=a[i];
			k=min(j+a[i]-1,M);
			num=ask(C,k)-ask(C,j-1);
			F[i]-=w*num;
		}
	//	cout<<i<<" "<<F[i]<<endl;
	//	add(A,a[i],(LL)a[i]);
		add(C,a[i],(LL)1);
		w=0;
		for(int j=a[i],k;j<=M;j=k+1){
			w+=a[i];
			k=min(j+a[i]-1,M);
			add(B,j,w);
			add(B,k+1,-w);
		}
		ss+=a[i];
	}
	for(int i=1;i<=n;++i){
		printf("%lld",F[i]);
		if(i==n) puts("");
		else putchar(' ');
	}
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
*/