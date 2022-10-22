#include<bits/stdc++.h>
#define LL long long
#define ll long long
#define LD long double
using namespace std;
LL qpow(LL x,LL y,LL P=998244353){
	LL re;
	for(re=1;y;y>>=1){if(y&1) re=re*x%P;x=x*x%P;}
	return re;
}
const LL P=1e9+7;
const int N=2e5+10;
const LL INF=2e18;
void init(){
}

int n,m,c;
int a[1005];
bool check(){
	for(int i=1;i<=n;++i) if(a[i]==0) return 0;
	for(int i=2;i<=n;++i){
		if(a[i]<a[i-1]) return 0;
	}
	return 1;
}
void MAIN(){
	int x,y,mid;
	scanf("%d%d%d",&n,&m,&c);
	mid=(c+1)>>1;
	bool flag=0;
	while(flag==0){
		scanf("%d",&x);
		if(x<=mid){
			for(int i=1;i<=n;++i){
				if(a[i]==0){
					a[i]=x;y=i;
					break;
				}
				if(a[i]<=x) continue;
				a[i]=x;y=i;break;
			}
		}
		else{
			for(int i=n;i>=1;--i){
				if(a[i]==0){
					a[i]=x;y=i;
					break;
				}
				if(a[i]>=x) continue;
				a[i]=x;y=i;break;
			}
		}
		printf("%d\n",y);
		fflush(stdout);
		flag=check();
	}
	return;
}
/*
*/
int main(){
    init();
    int ttt=1;//scanf("%d",&ttt);
    while(ttt--) MAIN();
    return 0;    
}