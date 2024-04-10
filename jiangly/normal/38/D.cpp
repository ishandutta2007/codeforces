#include<bits/stdc++.h>
typedef long long ll;
const int MAXN=100;
template<class T>void swap(T&a,T&b){
	T c=a;
	a=b;
	b=c;
}
int n;
ll x1[MAXN+5],y1[MAXN+5],x2[MAXN+5],y2[MAXN+5],w[MAXN+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%I64d%I64d%I64d%I64d",&x1[i],&y1[i],&x2[i],&y2[i]);
		x1[i]<<=1;
		y1[i]<<=1;
		x2[i]<<=1;
		y2[i]<<=1;
		if(x1[i]>x2[i])
			swap(x1[i],x2[i]);
		if(y1[i]>y2[i])
			swap(y1[i],y2[i]);
		w[i]=(x2[i]-x1[i])*(x2[i]-x1[i])*(x2[i]-x1[i]);
		ll sumx=0,sumy=0,sumw=0;
		for(int j=i-1;j>=1;--j){
			sumx+=((x1[j+1]+x2[j+1])>>1)*w[j+1];
			sumy+=((y1[j+1]+y2[j+1])>>1)*w[j+1];
			sumw+=w[j+1];
			if(sumx<x1[j]*sumw||sumx>x2[j]*sumw||sumy<y1[j]*sumw||sumy>y2[j]*sumw){
				printf("%d\n",i-1);
				return 0;
			}
		}
	}
	printf("%d\n",n);
	return 0;
}