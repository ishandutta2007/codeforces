#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
LL qpow(LL x,LL y,LL P){
	LL re=1;
	x=x%P;
	while(y){
		if(y&1) re=re*x%P;
		x=x*x%P;y>>=1;
	}
	return re;
}

const int N=1e6+10;
const double eps=1e-6;
const LL sed=1e9+7;
const LL P=998244353;
const LL INF=2e18;

LL fac[N+10],inv[N+10];
LL bin[70];
void init(){
	bin[0]=1;
	for(int i=1;i<=60;++i){
		bin[i]=bin[i-1]<<1;
	}
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(LL i=2;i<=N;++i){
		fac[i]=fac[i-1]*i%P;
	}
	inv[N]=qpow(fac[N],P-2,P);
	for(LL i=N;i>1;--i){
		inv[i-1]=inv[i]*i%P;
	}
	return;
}
set<int> S;
set<int>::iterator it;
int n,m;
char s[N];
char op[5];
void MAIN(){
	int x,y,z;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	int cnt=0;
	for(int i=1;i<=n-2;++i){
		if(s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c'){
			++cnt;
		}
	}
	//cout<<cnt<<endl;
	while(m--){
		scanf("%d%s",&x,op);
		if(s[x]=='a'&&x+2<=n&&s[x+1]=='b'&&s[x+2]=='c'){
			--cnt;
		}
		if(s[x]=='b'&&x+1<=n&&s[x+1]=='c'&&x-1>=1&&s[x-1]=='a'){
			--cnt;
		}
		if(s[x]=='c'&&x-2>=1&&s[x-1]=='b'&&s[x-2]=='a'){
			--cnt;
		}
		s[x]=op[0];
		if(s[x]=='a'&&x+2<=n&&s[x+1]=='b'&&s[x+2]=='c'){
			++cnt;
		}
		if(s[x]=='b'&&x+1<=n&&s[x+1]=='c'&&x-1>=1&&s[x-1]=='a'){
			++cnt;
		}
		if(s[x]=='c'&&x-2>=1&&s[x-1]=='b'&&s[x-2]=='a'){
			++cnt;
		}
		printf("%d\n",cnt);
	}
	
	return;
}
int main(){
	int ttt=1;//scanf("%d",&ttt);
	while(ttt--){
		MAIN();
	}
    return 0;
}