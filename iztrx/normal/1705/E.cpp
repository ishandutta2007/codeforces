#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
int n,q,a[N],z[N],o[N],tg[N],i,pos,x,y; 
void up(int k){
	if(z[ls]||z[rs])z[k]=1;
	else z[k]=0;
	if(o[ls]||o[rs])o[k]=1;
	else o[k]=0;
}
void down(int k){
	if(tg[k]==0){
		tg[ls]=tg[rs]=0;
		z[ls]=z[rs]=1;
		o[ls]=o[rs]=0;
		tg[k]=-1;
	}
	if(tg[k]==1){
		tg[ls]=tg[rs]=1;
		z[ls]=z[rs]=0;
		o[ls]=o[rs]=1;
		tg[k]=-1;
	}
}
void build(int k,int l,int r){
	z[k]=1;tg[k]=-1;
	if(l==r)return ;
	build(ls,l,mid);build(rs,mid+1,r);
}
int find(int k,int l,int r,int x,int y,int v){
	if(x<=l&&r<=y){
		if(v==0){
			if(z[k]){
				if(l==r)return l;
				down(k);
				if(z[ls]){
					return find(ls,l,mid,x,y,v);
				}
				else{
					return find(rs,mid+1,r,x,y,v);
				}
			}
			else return -1;
		}
		else{
			if(o[k]){
				if(l==r)return l;
				down(k);
				if(o[ls]){
					return find(ls,l,mid,x,y,v);
				}
				else{
					return find(rs,mid+1,r,x,y,v);
				}
			}
			else return -1;
		}
	}
	if(x>r||y<l)return -1;
	down(k);
	int f1=find(ls,l,mid,x,y,v);
	if(f1!=-1)return f1;
	return find(rs,mid+1,r,x,y,v);
}
void fz(int k,int l,int r,int x,int y,int v){
	if(x<=l&&r<=y){
		tg[k]=v;
		if(v==0)z[k]=1,o[k]=0;
		else z[k]=0,o[k]=1;
		return ;
	}
	if(x>r||y<l)return ;
	down(k);
	fz(ls,l,mid,x,y,v);fz(rs,mid+1,r,x,y,v);
	up(k);
}
int MX(int k,int l,int r){
	if(l==r)return l;down(k);
	if(o[rs])return MX(rs,mid+1,r);
	else return MX(ls,l,mid);
}
//void print(int k,int l,int r){
//	if(r<=10&&l==r){
//		if(z[k])cout<<0;
//		else cout<<1;
//	}
//	if(l==r)return ; 
//	down(k);
//	print(ls,l,mid);print(rs,mid+1,r);
//	up(k);
//}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;build(1,1,210000);
	for(i=1;i<=n;++i){
		cin>>a[i];
		pos=find(1,1,210000,a[i],210000,0);
		if(a[i]!=pos)fz(1,1,210000,a[i],pos-1,0);
		fz(1,1,210000,pos,pos,1);
	}
	while(q--){
		cin>>x>>y;
		pos=find(1,1,210000,a[x],210000,1);
		if(a[x]!=pos)fz(1,1,210000,a[x],pos-1,1);
		fz(1,1,210000,pos,pos,0);
		a[x]=y;
		pos=find(1,1,210000,a[x],210000,0);
		if(a[x]!=pos)fz(1,1,210000,a[x],pos-1,0);
		fz(1,1,210000,pos,pos,1);
		cout<<MX(1,1,210000)<<"\n"; 
	}
}