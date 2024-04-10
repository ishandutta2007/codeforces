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
int n,k;
int a[N];
int bin[35];
int c[3],d[3];
void MAIN(){
	int u,v;
	bin[0]=1;for(int i=1;i<30;++i)bin[i]=bin[i-1]<<1;
	scanf("%d%d",&n,&k);
	
	a[1]=a[2]=a[3]=0;
	
	printf("and %d %d\n",1,2);
	fflush(stdout);
	scanf("%d",&c[1]);
	printf("or %d %d\n",1,2);
	fflush(stdout);
	scanf("%d",&d[1]);
	
	printf("and %d %d\n",1,3);
	fflush(stdout);
	scanf("%d",&c[2]);
	printf("or %d %d\n",1,3);
	fflush(stdout);
	scanf("%d",&d[2]);
	
	printf("and %d %d\n",2,3);
	fflush(stdout);
	scanf("%d",&c[3]);
	printf("or %d %d\n",2,3);
	fflush(stdout);
	scanf("%d",&d[3]);
	int res;
	for(int i=0;i<30;++i){
		if((c[1]&bin[i])==(d[1]&bin[i])){
			if(c[1]&bin[i]){
				res=bin[i];
			}
			else{
				res=0;
			}
			a[1]^=res;a[2]^=res;
			if((c[2]&bin[i])!=(d[2]&bin[i])){
				res^=bin[i];
			}
			a[3]^=res;
			continue;
		}
		
		if((c[2]&bin[i])==(d[2]&bin[i])){
			if(c[2]&bin[i]){
				res=bin[i];
			}
			else{
				res=0;
			}
			a[1]^=res;a[3]^=res;
			//if((c[2]&bin[i])!=(d[2]&bin[i])){
				res^=bin[i];
			//}
			a[2]^=res;
			continue;
		}
		
		if((c[3]&bin[i])==(d[3]&bin[i])){
			if(c[3]&bin[i]){
				res=bin[i];
			}
			else{
				res=0;
			}
			a[2]^=res;a[3]^=res;
			//if((c[2]&bin[i])!=(d[2]&bin[i])){
				res^=bin[i];
			//}
			a[1]^=res;
			continue;
		}
	}
	
	for(int j=4;j<=n;++j){
		printf("and %d %d\n",1,j);
		fflush(stdout);
		scanf("%d",&u);
		printf("or %d %d\n",1,j);
		fflush(stdout);
		scanf("%d",&v);
		a[j]=0;
		for(int i=0;i<30;++i){
			if((u&bin[i])==(v&bin[i])){
				a[j]^=(a[1]&bin[i]);
			}
			else{
				a[j]^=((a[1]&bin[i])^bin[i]);
			}
		}
	}
	a[n+1]=0;
	sort(a+1,a+1+n);
	printf("finish %d\n",a[k]);
	fflush(stdout);
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
4 4
1
1
0
3
0
3
1
3

*/