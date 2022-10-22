#include <bits/stdc++.h>
#define ll long long
#define popcnt __builtin_popcountll
using namespace std;
const int maxn=1e6+5;
ll a[maxn];
int b[maxn];
ll read(){
    ll x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
ll res;
ll lmx[maxn],lmn[maxn],rmx[maxn],rmn[maxn];
int suf[maxn];
int wmx[65],wmn[65];
void calc(int l,int r){
	int mid=l+((r-l)>>1);
	for(int i=0;i<=60;i++)wmx[i]=wmn[i]=0;
	lmx[mid+1]=rmx[mid]=-1,lmn[mid+1]=rmn[mid]=1e18;
	for(int i=mid;i>=l;i--)lmx[i]=max(a[i],lmx[i+1]),lmn[i]=min(a[i],lmn[i+1]);
	for(int i=mid+1;i<=r;i++)rmx[i]=max(a[i],rmx[i-1]),rmn[i]=min(a[i],rmn[i-1]);
	suf[r+1]=0;for(int i=r;i>=mid+1;i--)suf[i]=suf[i+1]+(popcnt(rmx[i])==popcnt(rmn[i]));
	int p=mid,q=mid;
	for(int i=mid;i>=l;i--){
		while(p<r&&a[p+1]<=lmx[i]){++p;wmx[popcnt(rmx[p])]--,wmn[popcnt(rmn[p])]++;}
		while(q<r&&a[q+1]>=lmn[i]){++q;wmx[popcnt(rmx[q])]++,wmn[popcnt(rmn[q])]--;}
		if(popcnt(lmx[i])==popcnt(lmn[i]))res+=min(p,q)-mid;
		res+=suf[max(p,q)+1];
		if(p<q)res+=wmx[popcnt(lmn[i])];
		if(p>q)res+=wmn[popcnt(lmx[i])];
	}
	return ;
}
void solve(int l,int r){
	if(l==r){res++;return ;}
	int mid=l+((r-l)>>1);
	ll cur=res;
	calc(l,r);
	solve(l,mid),solve(mid+1,r);
	return ;
}
int main(){
    int n;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),b[i]=popcnt(a[i]);
	solve(1,n);
	printf("%lld\n",res);
	return 0;
}