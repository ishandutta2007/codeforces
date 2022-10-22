#include<bits/stdc++.h>
#define eb emplace_back
#define ll long long
using namespace std;
const int M=2e5+9;
int n;
ll a[M],s[M],sum=0,ans=0;
struct line{ll k,b;ll operator ()(int x){return k*x+b;}};
struct Li_Chao{
	line t[M<<2];
	void insert(int num,int l,int r,line o){
		int mid=l+r>>1,lv=o(l)>t[num](l),mv=o(mid)>t[num](mid),rv=o(r)>t[num](r);
		if(mv)swap(t[num],o);
		if(lv==rv||l==r)return;
		lv^mv?insert(num<<1,l,mid,o):insert(num<<1|1,mid+1,r,o);
	}
	void insert(int num,int l,int r,int x,int y,line o){
		if(x<=l&&r<=y){insert(num,l,r,o);return;}
		int mid=l+r>>1;
		if(x<=mid)insert(num<<1,l,mid,x,y,o);
		if(y>mid)insert(num<<1|1,mid+1,r,x,y,o);
	}
	ll query(int num,int l,int r,int x){
		if(l==r)return t[num](x);
		int mid=l+r>>1;
		return max(t[num](x),x<=mid?query(num<<1,l,mid,x):query(num<<1|1,mid+1,r,x));
	}
	void build(int num,int l,int r){
		t[num]=line{0,-(1ll<<60)};
		if(l==r)return;
		int mid=(l+r)>>1;
		build(num<<1,l,mid);
		build(num<<1|1,mid+1,r);
	}
}T,D;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		sum+=i*a[i];
		s[i]=s[i-1]+a[i];
	}
	ans=sum;
	T.build(1,1,n);
	D.build(1,1,n);
	for(int i=1;i<=n;++i){
		ans=max(ans,sum-s[i]+T.query(1,1,n,i));
		T.insert(1,1,n,1,n,line{a[i],s[i]-a[i]*i});
	}
	for(int i=n;i>=1;--i){
		ans=max(ans,sum-s[i-1]+D.query(1,1,n,i));
		D.insert(1,1,n,1,n,line{a[i],s[i-1]-a[i]*i});
	}
	cout<<ans<<"\n";
	return 0;
}