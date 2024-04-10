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
int a[310][310];
void MAIN(){
	int x;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			x=2;
			if(i!=1&&i!=n) ++x;
			if(j!=1&&j!=m) ++x;
			if(a[i][j]>x){
				puts("NO");
				return;
			}
			a[i][j]=x;
		}
	}
	puts("YES");
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			printf("%d ",a[i][j]);
		}
		puts("");
	}
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