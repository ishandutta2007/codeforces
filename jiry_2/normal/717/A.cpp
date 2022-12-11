#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct atom{
	int x,y;
};
const int mo=1e9+7;
int quick(int k1,int k2){
	int k3=1;
	while (k2){
		if (k2&1) k3=1ll*k3*k1%mo; k2>>=1; k1=1ll*k1*k1%mo;
	}
	return k3;
}
atom operator + (atom k1,atom k2){
	return (atom){(k1.x+k2.x)%mo,(k1.y+k2.y)%mo};
}
atom operator - (atom k1,atom k2){
	return (atom){(k1.x-k2.x+mo)%mo,(k1.y-k2.y+mo)%mo};
}
atom operator * (atom k1,atom k2){
	return (atom){(1ll*k1.x*k2.x+5ll*k1.y%mo*k2.y)%mo,(1ll*k1.x*k2.y+1ll*k1.y*k2.x)%mo};
}
atom operator * (atom k1,int k2){
	k2=(k2+mo)%mo;
	return (atom){1ll*k1.x*k2%mo,1ll*k1.y*k2%mo};
}
atom operator / (atom k1,int k2){
	return k1*quick(k2,mo-2);
}
atom operator / (atom k1,atom k2){
	atom k3=(atom){k2.x,(mo-k2.y)%mo}; int k4=((1ll*k2.x*k2.x-5ll*k2.y%mo*k2.y)%mo+mo)%mo;
	return k1*k3/k4;
}
long long l,r;
int K,flag;
atom w[500],A[500];
const int st=200,N=400;
void add(int k){
	atom k1=(atom){0,(mo-k)%mo};
	memcpy(A,w,sizeof A);
	memset(w,0x00,sizeof w);
	for (int i=0;i<N;i++)
		if (i<st) w[i]=w[i]-A[i+1];
		else w[i]=w[i]-A[i+1]*flag;
	for (int i=1;i<=N;i++) 
		if (i>st) w[i]=w[i]+A[i-1];
		else w[i]=w[i]+A[i-1]*flag;
	for (int i=0;i<=N;i++) w[i]=w[i]+A[i]*k1;
}
atom quick(atom k1,long long k2){
	atom k3=(atom){1,0};
	while (k2){
		if (k2&1) k3=k3*k1; k1=k1*k1; k2>>=1;
	}
	return k3;
}
atom calc(atom k1,int k2,long long n){
	k1=quick(k1,k2); atom k3=k1*k1; k3.x=(k3.x-1+mo)%mo;
	atom k4=quick(k1*k1,n+1); k4.x=(k4.x-1+mo)%mo;
//	atom k4=(atom){0,0};
//	for (int i=1;i<=n;i++) k4=k4+quick(k1,i);
//	return k4;
	if (flag==1)
		return k4/k3;
	else return k4*k1/k3;
}
int calc2(long long n,int pd){ 
	memset(w,0x00,sizeof w); flag=pd;
	w[st]=(atom){1,0};
	for (int i=0;i<K;i++) add(i);
	atom k1=quick((atom){0,quick(5,mo-2)},K);
	for (int i=1;i<=K;i++) k1=k1*quick(i,mo-2);
	atom a=(atom){quick(2,mo-2),quick(2,mo-2)};
	atom b=(atom){quick(2,mo-2),mo-quick(2,mo-2)};
	atom ans=w[st]*(n%mo);
	for (int i=st+1;i<=N;i++) ans=ans+w[i]*calc(a,i-st,n);
	for (int i=0;i<st;i++) ans=ans+w[i]*calc(b,st-i,n);
	ans=ans*k1;
	return ans.x;
}
int calc(long long n){
	long long k1=n/2,k2=n-k1-1;
	return (calc2(k1,1)+calc2(k2,-1))%mo;
}
int main(){
	scanf("%d%I64d%I64d",&K,&l,&r);
	printf("%d\n",(calc(r+2)-calc(l+1)+mo)%mo);
	return 0;
}