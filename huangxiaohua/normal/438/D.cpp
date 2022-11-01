#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[100500],it=1,x,y,z;
ll su[500500],ls[500500],rs[500500],mx[500500];

void upd(int id){
	su[id]=su[ls[id]]+su[rs[id]];
	mx[id]=max(mx[ls[id]],mx[rs[id]]);
}

void build(int id,int l,int r){
	int md=(l+r)/2;
	if(l==r){
		mx[id]=su[id]=a[l];
		return;
	}
	ls[id]=++it;build(ls[id],l,md);
	rs[id]=++it;build(rs[id],md+1,r);
	upd(id);
}

ll get(int id,int l,int r,int x,int y){
	if(r<x||l>y)return 0;
	if(x<=l&&r<=y)return su[id];
	int md=(l+r)/2;
	return get(ls[id],l,md,x,y)+get(rs[id],md+1,r,x,y);
}

void mod(int id,int l,int r,int x,int y,int z){
	if(mx[id]<z||r<x||l>y)return;
	if(l==r){su[id]%=z;mx[id]=su[id];return;}
	int md=(l+r)/2;
	mod(ls[id],l,md,x,y,z);
	mod(rs[id],md+1,r,x,y,z);
	upd(id);
}

void ass(int id,int l,int r,int x,int y){
	if(r<x||l>x)return;
	if(l==r){
		su[id]=mx[id]=y;return;
	}
	int md=(l+r)/2;
	ass(ls[id],l,md,x,y);
	ass(rs[id],md+1,r,x,y);
	upd(id);
}

int main() {
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	while(t--){
		scanf("%d%d%d",&k,&x,&y);
		if(k==1){
			printf("%lld\n",get(1,1,n,x,y));
		}
		if(k==2){
			scanf("%d",&z);
			mod(1,1,n,x,y,z);
		}
		if(k==3){
			ass(1,1,n,x,y);
		}
	}
}