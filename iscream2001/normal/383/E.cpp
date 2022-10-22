#include<bits/stdc++.h>
#define LL long long
#define ll long long
#define LD long double
using namespace std;
LL qpow(LL x,LL y,LL P=998244353){
	LL re;x%=P;
	for(re=1;y;y>>=1){if(y&1) re=re*x%P;x=x*x%P;}
	return re;
}
const LL P=1e9+7;
const int N=2e5+10;
const LL INF=2e18;
void init(){
}

int n,m,cnt;
int a[(1<<24)+5];
char s[10];

int popc(int x){
	int re=0;
	while(x>0){
		x-=x&-x;
		++re;
	}
	return re;
}

void MAIN(){
	//cout<<(1<<24)<<endl;
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		x=0;
		for(int j=1;j<=3;++j){
			x|=(1<<(s[j]-'a'));
		}
		y=x;
		while(y){
			//cout<<y<<endl;
			a[y]+=(popc(y)&1)?1:-1;
			y=(y-1)&x;
		}
	}
	for(int j=0;j<24;++j){
		for(int i=0;i<(1<<24);++i){
			if(i&(1<<j)) continue;
			a[i^(1<<j)]+=a[i];
		}
	}
	int ans=0;
	for(int i=0;i<(1<<24);++i){
		ans^=(a[i]*a[i]);
	}
	printf("%d\n",ans);
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