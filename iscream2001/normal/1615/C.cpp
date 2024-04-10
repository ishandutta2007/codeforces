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
const int N=1e5+10;
const int INF=1e9;

void init(){
}

int n,m;
char A[N],B[N];

void MAIN(){
	int ans=INF,x,y;
	scanf("%d",&n);
	scanf("%s",A+1);
	scanf("%s",B+1);
	//0
	x=0;y=0;
	for(int i=1;i<=n;++i){
		if(A[i]=='0'&&B[i]=='1') ++y;
		if(A[i]=='1'&&B[i]=='0') ++x;
	}
	if(x==y){
		ans=min(ans,x+y);
	}
	
	x=0;y=0;
	for(int i=1;i<=n;++i){
		if(A[i]=='0'&&B[i]=='0') ++y;
		if(A[i]=='1'&&B[i]=='1') ++x;
	}
	if(x==y+1){
		ans=min(ans,x+y);
	}
	if(ans==INF) puts("-1");
	else printf("%d\n",ans);
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