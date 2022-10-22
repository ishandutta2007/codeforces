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
const int N=1e6+10;

void init(){
}

int n,m;
int a[1005];
bool vis[1005];
int ans[2005];
int cal(){
	for(int i=0;i<n;++i){
		vis[a[i]]=1;
	}
	int res=0;
	while(vis[res]) ++res;
	for(int i=0;i<n;++i){
		vis[a[i]]=0;
	}
	return res;
}
void MAIN(){
	int x,K=0,num=0,y,z;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
		if(a[i]!=i) ++num;
	}
	while(num>0){
		
		x=cal();
		if(x==n){
			y=z=n+1;
			for(int i=0;i<n;++i){
				if(a[i]!=i){
					if(a[i]<y){
						y=a[i];
						z=i;
					}
				}
			}
			ans[++K]=z;
			a[z]=x;
		}
		else{
			a[x]=x;
			ans[++K]=x;
		}
		num=0;
		for(int i=0;i<n;++i){
			if(a[i]!=i) ++num;
		}
	}
	printf("%d\n",K);
	for(int i=1;i<=K;++i){
		printf("%d ",ans[i]+1);
	}
	puts("");
	return;
}
/*
*/
int main(){
    init();
    int ttt=1;scanf("%d",&ttt);
    while(ttt--) MAIN();
    return 0;    
}