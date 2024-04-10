#include <bits/stdc++.h>
using namespace std;
inline void read(int &s){
	s=0;
	int f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(isdigit(c))
		s=(s<<3)+(s<<1)+(c^48),c=getchar();
	s*=f;
	return;
}
#define lson ls[u]
#define rson rs[u]
int val[2097152],ls[2097152],rs[2097152];
int ndcnt=1;
inline void pushup(int u){
	val[u]=val[lson]+val[rson];
	return;
}
inline int modify(int &u,int l,int r,int p,int k){
	if(!u)u=++ndcnt;
	if(l==r){
		val[u]+=k;
		return u;
	}
	int mid=(l+r)>>1;
	if(p<=mid)modify(lson,l,mid,p,k);
	else modify(rson,mid+1,r,p,k);
	pushup(u);
	return u;
}
inline int query(int u,int l,int r,int ql,int qr){
	if(!u)return 0;
	if(ql<=l&&r<=qr)return val[u];
	int mid=(l+r)>>1,ans=0;
	if(ql<=mid)ans+=query(lson,l,mid,ql,qr);
	if(mid<qr)ans+=query(rson,mid+1,r,ql,qr);
	return ans;
}
inline int kth(int u,int l,int r,int k){
	if(!u)return -1;
	if(l==r)return l;
	int mid=(l+r)>>1;
	if(k<=val[lson])return kth(lson,l,mid,k);
	else return kth(rson,mid+1,r,k-val[lson]);
}
int n,q,sz;
int main(){
	read(n);
	read(q);
	sz=n;
	int opt,x;
	int rt=1;
	for(int i=1;i<=n;i++){
		read(x);
		modify(rt,-1e7,1e7,x,1);
	}
	while(q--){
		read(x);
		if(x<0){
			x=-x;
			modify(rt,-1e7,1e7,kth(1,-1e7,1e7,x),-1);
			sz--;
		}
		else modify(rt,-1e7,1e7,x,1),sz++;
	}
	if(!sz){
		cout<<0;
	}
	else cout<<kth(1,-1e7,1e7,1);
	return 0;
}