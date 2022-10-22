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
const LL INF=1e11;

void init(){
}

int n,m;
void MAIN(){
	LL a[5]={0,0,0,0,0},b[5],x,y,las=-1;
	scanf("%lld%lld%lld",&a[1],&a[2],&a[3]);
	cout<<"First"<<endl;
	fflush(stdout);
	printf("%lld\n",INF);fflush(stdout);
	scanf("%lld",&x);if(!x) return;
	a[x]+=INF;
	b[1]=a[1];b[2]=a[2];b[3]=a[3];
	sort(b+1,b+1+3);
	y=b[3]+b[3]-b[1]-b[2];
	printf("%lld\n",y);fflush(stdout);
	scanf("%lld",&x);if(!x) return;
	a[x]+=y;
	b[1]=a[1];b[2]=a[2];b[3]=a[3];
	sort(b+1,b+1+3);
	y=b[3]-b[2];
	printf("%lld\n",y);fflush(stdout);
	scanf("%lld",&x);if(!x) return;
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