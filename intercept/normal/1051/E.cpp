#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
#define ll long long
using namespace std;
const int mod=998244353;
const int M=1e6+9;
int n,q;
char a[M],b[M],c[M];
const int sed=131;
const int mod1=1e9+7;
const int mod2=1e9+87;
struct Hash{
	int x1,x2;
	Hash(int t1=0,int t2=0):x1(t1),x2(t2){}
	bool operator != (const Hash&o)const{return x1!=o.x1||x2!=o.x2;}
	bool operator == (const Hash&o)const{return x1==o.x1&&x2==o.x2;}
	bool operator <  (const Hash&o)const{return x1==o.x1?x2<o.x2:x1<o.x1;}
	Hash operator +  (const Hash&o)const{return Hash((x1+o.x1)%mod1,(x2+o.x2)%mod2);}
	Hash operator -  (const Hash&o)const{return Hash((x1-o.x1+mod1)%mod1,(x2-o.x2+mod2)%mod2);}
	Hash operator +  (const int&o)const{return Hash((x1+o)%mod1,(x2+o)%mod2);}
	Hash operator -  (const int&o)const{return Hash((x1+mod1-o)%mod1,(x2+mod2-o)%mod2);}
	Hash operator *  (const int&o)const{return Hash(1ll*x1*o%mod1,1ll*x2*o%mod2);}
	Hash operator *  (const Hash&o)const{return Hash(1ll*x1*o.x1%mod1,1ll*x2*o.x2%mod2);}
}pw[M],pa[M],pb[M],pc[M];
bool vl[M],vr[M];
int dp[M],sum[M];
bool check1(int x,int y,int len){
	return pa[y]-pa[x-1]*pw[len]==pb[len];
}
bool check2(int x,int y,int len){
	return pa[y]-pa[x-1]*pw[len]==pc[len];
}
int main(){
	cin>>(a+1)>>(b+1)>>(c+1);
	int n=strlen(a+1);
	int nl=strlen(b+1);
	int nr=strlen(c+1);
	pw[0]=Hash(1,1);
	for(int i=1;i<=n;++i)pw[i]=pw[i-1]*sed;
	for(int i=1;i<=n;++i){
		pa[i]=pa[i-1]*sed+a[i];
	}
	for(int i=1;i<=nl;++i){
		pb[i]=pb[i-1]*sed+b[i];
	}
	for(int i=1;i<=nr;++i){
		pc[i]=pc[i-1]*sed+c[i];
	}
	for(int i=1;i<=n-nl+1;++i){
		int l=0,r=nl;
		while(l<r){
			int mid=(l+r)>>1;
			if(check1(i,i+mid,mid+1))l=mid+1;
			else r=mid;
		}
		if(l==nl||a[i+l]>=b[l+1])vl[i]=1;
	}
	for(int i=1;i<=n-nr+1;++i){
		int l=0,r=nr;
		while(l<r){
			int mid=(l+r)>>1;
			if(check2(i,i+mid,mid+1))l=mid+1;
			else r=mid;
		}
		if(l==nr||a[i+l]<=c[l+1])vr[i]=1;
	}
	dp[n+1]=sum[n+1]=1;
	for(int i=n;i>=1;--i){
		int l=i+nl+(vl[i]==0);
		int r=min(i+nr-(vr[i]==0),n+1);
		if(a[i]!='0'){
			if(l>r)dp[i]=0;
			else dp[i]=(sum[l]+mod-sum[r+1])%mod;
		}
		else {
			if(nl==1&&b[1]=='0')dp[i]=dp[i+1];
		}
		sum[i]=(sum[i+1]+dp[i])%mod;
	}
	cout<<dp[1]<<"\n";
	return 0;
}
/*
23323
1
4
*/