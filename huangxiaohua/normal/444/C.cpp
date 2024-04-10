#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define md ((l+r)>>1)
#define ls (cur<<1)
#define rs ((cur<<1)+1)
#define len (r-l+1)
#define chk() if(l!=r&&sum[cur]){sum[ls]=(sum[ls]+sum[cur]);s[ls]=(s[ls]+sum[cur]*(md-l+1));sum[rs]=(sum[rs]+sum[cur]);s[rs]=(s[rs]+sum[cur]*(r-md));sum[cur]=0;}
int i,j,k,n,m,l[100500],col[100500],x,y,w,cl,cr,t,sb;
ll a[100500],s[400500],sum[400500],tmp;

void build(int l,int r,int cur){
	if(l==r){s[cur]=a[l];return;}
	build(l,md,ls);build(md+1,r,rs);
	s[cur]=(s[ls]+s[rs]);
}

void add(int l,int r,int nl,int nr,int cur,ll ad){
	if(l==nl&&r==nr){sum[cur]=(sum[cur]+ad);s[cur]=(s[cur]+ad*len);chk();return;}
	chk();
	if(nr<=md){add(l,md,nl,nr,ls,ad);}
	else{
		if(nl>md){add(md+1,r,nl,nr,rs,ad);}
		else{add(l,md,nl,md,ls,ad);add(md+1,r,md+1,nr,rs,ad);}
	}
	s[cur]=(s[ls]+s[rs]);
}

ll ask(int l,int r,int nl,int nr,int cur){
	chk();
	if(l==nl&&r==nr){return s[cur];}
	if(nr<=md){return ask(l,md,nl,nr,ls);}
	if(nl>md){return ask(md+1,r,nl,nr,rs);}
	return ask(l,md,nl,md,ls)+ask(md+1,r,md+1,nr,rs);
}

set<int> st;

int main(){
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i++){
		st.insert(i);
		l[i]=i;col[i]=i;
	}
	st.insert(-1);
	st.insert(114514);
	while(t--){
		int ty;
		scanf("%d",&ty);
		if(ty==1){
			scanf("%d%d%d",&x,&y,&w);
			while(1){
				auto it=st.lower_bound(x);
				if(*it==114514||l[*it]>y)break;
				cr=*it;cl=l[cr];sb=col[cr];
				if(cl<x){
					st.insert(x-1);
					l[x-1]=cl;col[x-1]=col[cr];cl=x;
				}
				if(cr>y){
					l[cr]=y+1;cr=y;
				}
				st.erase(cr);
				add(1,n,cl,cr,1,abs(sb-w));
			}
			l[y]=x;col[y]=w;
			st.insert(y);
		}
		else{
			scanf("%d%d",&x,&y);
			printf("%lld\n",ask(1,n,x,y,1));
		}
		
	}
}