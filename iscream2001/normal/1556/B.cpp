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
	int num=0,now;
	LL ans=INF,res;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		a[i]=(a[i]&1);
		if(a[i]) ++num;
	}
	//1
	if(num==(int)((n+1)/2)){
		now=1;res=0;
		for(int i=1;i<=n;++i){
			if(a[i]){
				res+=abs(i-now);
				now+=2;
			}
		}
		ans=min(ans,res);
	} 
	//0
	if(num==(int)(n/2)){
		now=2;res=0;
		for(int i=1;i<=n;++i){
			if(a[i]){
				res+=abs(i-now);
				now+=2;
			}
		}
		ans=min(ans,res);
	} 
	if(ans==INF) puts("-1");
	else printf("%lld\n",ans);
	return;
} 

int main(){
	int ttt=1;scanf("%d",&ttt);
	while(ttt--) {
		MAIN();
	}
	return 0;
}
/*
*/