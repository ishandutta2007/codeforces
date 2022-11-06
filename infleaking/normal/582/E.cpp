#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
const int N=505,mo=1e9+7;
char s[N];
int n,M=1<<16;
vec ept;
vec make(int x){
	int a[5],z=x<0,w=0,t=0;
	x*=(!z)*2-1;
	vec c=ept;
	for (a[1]=0;a[1]<=1;a[1]++)
	for (a[2]=0;a[2]<=1;a[2]++)
	for (a[3]=0;a[3]<=1;a[3]++)
	for (a[4]=0;a[4]<=1;a[4]++)
		w=(a[x]^z)<<t|w,t++;
	c[w]=1;
	return c;
}
vec alt;
vec add(vec a,vec b){
	for (int i=0;i<M;i++)
		a[i]=(a[i]+b[i])%mo;
	return a;
}
void ofwt(vec &a){
	for (int n=1;n<M;n<<=1)
		for (int i=n;i<M;i=(i+1)|n)
			a[i]+=a[i^n];
	for (int i=0;i<M;i++)a[i]%=mo;
}
void oifwt(vec &a){
	for (int n=1;n<M;n<<=1)
		for (int i=n;i<M;i=(i+1)|n)
			a[i]-=a[i^n];
	for (int i=0;i<M;i++)a[i]=(a[i]%mo+mo)%mo;
}
void afwt(vec &a){
	for (int n=1;n<M;n<<=1)
		for (int i=n;i<M;i=(i+1)|n)
			a[i^n]+=a[i];
	for (int i=0;i<M;i++)a[i]%=mo;
}
void aifwt(vec &a){
	for (int n=1;n<M;n<<=1)
		for (int i=n;i<M;i=(i+1)|n)
			a[i^n]-=a[i];
	for (int i=0;i<M;i++)a[i]=(a[i]%mo+mo)%mo;
}
vec And(vec a,vec b){
	vec c=ept;
	afwt(a);
	afwt(b);
	for (int i=0;i<M;i++)a[i]=a[i]*b[i]%mo;
	aifwt(a);
	return a;
}
vec Or(vec a,vec b){
	vec c=ept;
	ofwt(a);
	ofwt(b);
	for (int i=0;i<M;i++)a[i]=a[i]*b[i]%mo;
	oifwt(a);
	return a;	
}
void makealt(){
	vec a=ept;
	for (int i=1;i<=4;i++)
		a=add(add(make(i),make(-i)),a);
	alt=a;
}
vec ans;
vec solve(int l,int r){
	if (l==r){
		if (s[l]=='?')return alt;
		if (s[l]<='D')return make(s[l]-'A'+1);
		else return make(-(s[l]-'a'+1));
	}
	int cnt=0,M;
	for (int i=l;i<=r;i++){
		if (s[i]=='(')cnt++;
		else if (s[i]==')')cnt--;
		else if (!cnt)M=i;
	}
	vec L=solve(l+1,M-2),R=solve(M+2,r-1);
	if (s[M]=='&')return And(L,R);
	if (s[M]=='|')return Or(L,R);
	return add(And(L,R),Or(L,R));
}
int lim[16];
int main(){
	ept.resize(M);
	makealt();
	scanf("%s",s);
	n=strlen(s);
	ans=solve(0,n-1);
	memset(lim,255,sizeof lim);
	cin>>n;
	for (int i=1;i<=n;i++){
		int w,x=0,z;
		for (int j=1;j<=4;j++){
			scanf("%d",&z);
			x=x<<1|z;
		}
		scanf("%d",&w);
		lim[x]=w^1;
	}
	ll Ans=0;
	for (int i=0;i<M;i++){
		int can=1;
		for (int j=0;j<16;j++)
			if (((i>>j)&1)==lim[j])can=0;
		Ans=(Ans+can*ans[i])%mo;
	}
	
	cout<<Ans<<endl;
}