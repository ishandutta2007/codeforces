#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
#define N 1000005
ll ans,pos;
struct sgt{
	ll mn[N<<2],tg[N<<2],c[N<<2];
	void build(int k,int l,int r){
		mn[k]=1e18;
		tg[k]=0;c[k]=r-l+1;
		if(l!=r)build(ls,l,mid),build(rs,mid+1,r);
	}
	void down(int k){
		if(tg[k]){
			mn[ls]+=tg[k];
			tg[ls]+=tg[k];
			mn[rs]+=tg[k];
			tg[rs]+=tg[k];
			tg[k]=0;
		}
	}
	void up(int k){
		mn[k]=min(mn[ls],mn[rs]);
		c[k]=0;
		if(mn[ls]==mn[k])c[k]+=c[ls];
		if(mn[rs]==mn[k])c[k]+=c[rs];
	}
	void modify(int k,int l,int r,int x,int y,int v){
		if(x<=l&&r<=y){
			tg[k]+=v;mn[k]+=v;
			return ;
		}
		if(x>r|y<l)return ;
		down(k);
		modify(ls,l,mid,x,y,v);modify(rs,mid+1,r,x,y,v);
		up(k);
	}
	int fir(int k,int l,int r){
		if(l==r){
			if(mn[k]<0)return l+1;
			else return l;
		}
		down(k);
		if(mn[rs]>=0)return fir(ls,l,mid);
		else return fir(rs,mid+1,r);
	}
	void dd(int k,int l,int r,int x){
		if(l==r){mn[k]=0;return ;}
		down(k);
		if(x<=mid)dd(ls,l,mid,x);
		else dd(rs,mid+1,r,x);
		up(k);
	}
	int sum(int k,int l,int r,int x,int y){
		if(x<=l&&r<=y){
			if(mn[k]==0){
				return c[k];
			}
			return 0;
		}
		if(x>r||y<l)return 0;
		down(k);
		return sum(ls,l,mid,x,y)+sum(rs,mid+1,r,x,y); 
	}
}s1,s2;
int T,n,a[N],i;
int main(){
	ios::sync_with_stdio(0);
	cin>>T;cout.tie(0);
	while(T--){
		cin>>n;
		for(i=1;i<=n;++i)cin>>a[i];
		s1.build(1,1,n);s2.build(1,1,n);
		ans=0;
		for(i=1;i<=n;++i){
			if(i&1){
				s1.dd(1,1,n,i);
				s1.tg[1]+=a[i];
				s1.mn[1]+=a[i];
				s2.tg[1]-=a[i];
				s2.mn[1]-=a[i];
			}
			else{
				s2.dd(1,1,n,i);
				s1.tg[1]-=a[i];
				s1.mn[1]-=a[i];
				s2.tg[1]+=a[i];
				s2.mn[1]+=a[i];
			}
			pos=max(s1.fir(1,1,n),s2.fir(1,1,n));
//			cout<<pos<<"+";
			ans+=s1.sum(1,1,n,pos,n)+s2.sum(1,1,n,pos,n);
//			cout<<ans<<"\n";
		}
		cout<<ans<<"\n";
	}
}