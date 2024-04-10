#include<bits/stdc++.h>
using namespace std;
#define N 2000005
#define ll long long
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
ll T,n,i,j,ans,cnt,m,hd,k,a[N],st[N],mn[N],mx[N],MN[N],MX[N];
void build(int k,int l,int r){
	if(l==r){MN[k]=MX[k]=l;return ;}
	build(ls,l,mid),build(rs,mid+1,r);
	if(a[MN[ls]]<a[MN[rs]])MN[k]=MN[ls];
	else MN[k]=MN[rs];
	if(a[MX[ls]]>a[MX[rs]])MX[k]=MX[ls];
	else MX[k]=MX[rs];
}
int MIN(int k,int l,int r,int x,int y){
	if(x<=l&&r<=y)return MN[k];
	if(y<=mid)return MIN(ls,l,mid,x,y);
	else if(x>mid)return MIN(rs,mid+1,r,x,y);
	else{
		int f1=MIN(ls,l,mid,x,y),f2=MIN(rs,mid+1,r,x,y);
		if(a[f1]<a[f2])return f1;
		else return f2;
	}
}int MAX(int k,int l,int r,int x,int y){
	if(x<=l&&r<=y)return MX[k];
	if(y<=mid)return MAX(ls,l,mid,x,y);
	else if(x>mid)return MAX(rs,mid+1,r,x,y);
	else{
		int f1=MAX(ls,l,mid,x,y),f2=MAX(rs,mid+1,r,x,y);
		if(a[f1]>a[f2])return f1;
		else return f2;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n;cnt=0;
		for(i=1;i<=n;++i)cin>>a[i];
		mx[n]=mn[n]=n+1;
		build(1,1,n);
		st[hd=1]=n;
		for(i=n-1;i;--i){
			while(hd&&a[st[hd]]>a[i])--hd;
			if(!hd)mn[i]=n+1;
			else mn[i]=st[hd];
			st[++hd]=i;
		}st[hd=1]=n;
		
		for(i=n-1;i;--i){
			while(hd&&a[st[hd]]<a[i])--hd;
			if(!hd)mx[i]=n+1;
			else mx[i]=st[hd];
			st[++hd]=i;
		}
		for(i=1;i<n;i=j){
			if(a[i]<a[i+1]){
				j=MAX(1,1,n,i+1,mn[i]-1);
			}
			else{
				j=MIN(1,1,n,i+1,mx[i]-1);
			}
			++cnt;
		}
		cout<<cnt<<"\n";
	}
}