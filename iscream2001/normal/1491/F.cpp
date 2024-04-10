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

int n,res,K,T,tp;
int q[N];
int b[N];
void MAIN(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		printf("? %d %d\n",1,n-i);
		fflush(stdout);
		printf("%d\n",i);
		fflush(stdout);
		for(int j=i+1;j<=n;++j){
			printf("%d ",j);
		}
		printf("\n");
		fflush(stdout);
		scanf("%d",&res);
		if(res!=0){
			K=i;
			b[K+1]=res;
			break;
		}
	}
	for(int i=K+2;i<=n;++i){
		printf("? %d %d\n",1,n-i+1);
		fflush(stdout);
		printf("%d\n",K);
		fflush(stdout);
		for(int j=i;j<=n;++j){
			printf("%d ",j);
		}
		printf("\n");
		fflush(stdout);
		scanf("%d",&res);
		b[i]=res;
	}
	
	tp=0;b[n+1]=0;
	for(int i=n;i>K;--i){
		if(b[i]==b[i+1]) q[++tp]=i;
	}
	T=0;
	if(K>1){
		n=K-1;
		int l=1,r=n,mid,fff=0;
		while(l<r){
				mid=(l+r)>>1;
				printf("? %d %d\n",1,mid-l+1);
				fflush(stdout);
				printf("%d\n",K);
				fflush(stdout);
				for(int j=l;j<=mid;++j){
					printf("%d ",j);
				}
				printf("\n");
				fflush(stdout);
				scanf("%d",&res);
				if(res==0) l=mid+1;
				else {
					r=mid;
					fff=1;
				}
		}
		T=l;
		if(fff==0){
			printf("? %d %d\n",1,1);
			fflush(stdout);
			printf("%d\n",K);
			fflush(stdout);
			printf("%d\n",T);
			fflush(stdout);
			scanf("%d",&res);
			fff=res;
		}
		if(fff==0) {
			for(int j=1;j<=n;++j) q[++tp]=j;
		}
		else {
			for(int j=1;j<=n;++j) if(j!=T) q[++tp]=j;
		}
	}
	printf("! %d",tp);
	for(int i=1;i<=tp;++i) printf(" %d",q[i]);
	printf("\n");
	fflush(stdout);
	return;
}

int main(){
    int ttt;scanf("%d",&ttt);
    while(ttt--) MAIN();
    return 0;
}