#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=100010;
int pm,p[N/5],phi[N];
LL pp[N];
LL fast_calc(int l,int r){
	LL res=0;
	for(int i=l,t,p;i<=r;i=t+1){
		p=r/i,t=r/p;
		res+=pp[p]*(t-i+1);
	}
	return res;
}
LL h[N][20];
void range_upd(int x,int y,int l,int r){
	r=std::min(x-1,r);
	l=std::min(r,std::max(1,l));
	LL a=fast_calc(l+1,x);
	for(int i=l;i<=r;i++){
		h[x][y]=std::min(h[x][y],h[i][y-1]+a);
		a-=pp[x/(i+1)];
	}
}
void range_upd2(int x,int y,int l,int r){
	r=std::min(x-1,r);
	l=std::min(r,std::max(1,l));
	LL a=fast_calc(l+1,x);
	for(int i=l;i<=r;i++){
		for(int j=y;j<=19;j++)h[x][j]=std::min(h[x][j],h[i][j-1]+a);
		a-=pp[x/(i+1)];
	}
}
int main(){
	for(int i=2;i<=N-1;i++){
		if(!phi[i])p[pm++]=i,phi[i]=i-1;
		for(int j=0;i*p[j]<N;j++){
			if(i%p[j]==0){
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}
			phi[i*p[j]]=phi[i]*(p[j]-1);
		}
	}
	for(int i=1;i<=N-1;i++)pp[i]=pp[i-1]+phi[i];
	int n=1e5;
	memset(h,0x3f,sizeof(h));
	for(int i=1;i<=n;i++){
		int pred2=pow(i,.68)*.579;
		int pred3=i<=1439*5?i/5:i<=1439*6?1439:i<=2429*6?i/6:i<=2429*7?2429:i<=7559*7?i/7:i<=7559*8?7559:i/8;
		int pred4=i>=67410&&i<=68753?22469:i>=97024&&i<=98520?24629:i<=22919*3?i/3:i<=22919*4?22919:i>=91728&&i<=23519*4?23519:i/4;
		int pred5=i>=81648&&i<=84230?28079:i<=25919*2?i/2:i<=25919*3?25919:i/3;
		h[i][1]=(LL)i*(i-1)>>1;
		range_upd(i,2,pred2-16,pred2+16);
		range_upd(i,3,pred3-189,pred3+189);
		range_upd(i,4,pred4-255,pred4+255);
		range_upd(i,5,pred5-359,pred5+359);
		if(i<=100)range_upd2(i,6,0,i-1);
		else range_upd2(i,6,i/2-5,i/2+5);
	}
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		if(m>19)m=19;
		printf("%lld\n",h[n][m]+n);
	}
}