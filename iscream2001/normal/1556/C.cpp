#include<bits/stdc++.h>
#define LL long long
#define LD long double
#define pa pair<int,int>
using namespace std;
const LL P=998244353;
const LL INF=1e18;
const int N=1e5+10;
const LL g=3;
static char ss[1<<17],*A=ss,*B=ss;
char gc(){
    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
int read(){
    int f=1,c; 
	while (c=gc(),c<48||c>57) if (c=='-') f=-1; 
	int x=c-'0';
    while(c=gc(),c>47&&c<58) x=x*10+c-'0'; 
	return f>0?x:-x;
}
LL qpow(LL x,LL y){
    LL re=1;
    while(y){
        if(y&1) re=re*x%P;
        x=x*x%P;y>>=1;	
    } 
    return re;
}
int n;
int a[N];
void MAIN(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	LL ans=0,x,y,z,res;
	for(int i=1;i<=n;i+=2){
		x=0;y=0;
		for(int j=i+1;j<=n;++j){
			if(j&1){
				y+=a[j];
			} 
			else{
				res=min(a[i],a[j]);
				res=min(res,min(a[i]-x+1,a[j]-y+1));
				res=max((LL)0,res);
				ans+=res;
				z=min(y,(LL)a[j]);
				y-=z;
				if(a[j]>=z){
					x+=a[j]-z;
				}
			}
		}
	}
	printf("%lld\n",ans);
	return;
} 

int main(){
	int ttt=1;//scanf("%d",&ttt);
	while(ttt--) {
		MAIN();
	}
	return 0;
}
/*
*/