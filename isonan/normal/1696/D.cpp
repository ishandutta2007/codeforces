#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int>vec[4][2500001];
int T,n,a[250001],dis[250001];
int mn[2500001],mx[2500001];
int cmax(int a,int b){
	if(!a||!b)return a|b;
	if(::a[a]>::a[b])return a;
	else return b;
}
int cmin(int a,int b){
	if(!a||!b)return a|b;
	if(::a[a]<::a[b])return a;
	else return b;
}
void pushup(int x){
	mn[x]=cmin(mn[x<<1],mn[x<<1|1]);
	mx[x]=cmax(mx[x<<1],mx[x<<1|1]);
}
void build(int root,int l,int r){
	vec[0][root].clear();
	vec[1][root].clear();
	vec[2][root].clear();
	vec[3][root].clear();
	if(l==r){return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	pushup(root);
}
void clear(int root,int l,int r,int e){
	if(l==r){
		mn[root]=0,mx[root]=0;
		return;
	}
	if((l+r)>>1>=e)clear(root<<1,l,(l+r)>>1,e);
	else clear(root<<1|1,((l+r)>>1)+1,r,e);
	pushup(root);
}
int query(int root,int l,int r,int el,int er,int tp){
	if(el>r||er<l)return (!tp)?0:0;
	if(el<=l&&er>=r)return (tp)?mx[root]:mn[root];
	if(tp)return cmax(query(root<<1,l,(l+r)>>1,el,er,tp),query(root<<1|1,((l+r)>>1)+1,r,el,er,tp));
	else return cmin(query(root<<1,l,(l+r)>>1,el,er,tp),query(root<<1|1,((l+r)>>1)+1,r,el,er,tp));
}
void upd(int root,int l,int r,int el,int er,int x,int tp){
	// if(root==1)printf("ins %d %d %d %d\n",el,er,x,tp);
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		vec[tp][root].push_back(x);
		return;
	}
	upd(root<<1,l,(l+r)>>1,el,er,x,tp);
	upd(root<<1|1,((l+r)>>1)+1,r,el,er,x,tp);
}
void all(int root,int l,int r){
	std::sort(vec[0][root].begin(),vec[0][root].end());
	std::sort(vec[1][root].begin(),vec[1][root].end());
	std::sort(vec[2][root].begin(),vec[2][root].end());
	std::sort(vec[3][root].begin(),vec[3][root].end());
	std::reverse(vec[2][root].begin(),vec[2][root].end());
	std::reverse(vec[3][root].begin(),vec[3][root].end());
	
	if(l==r)return;
	all(root<<1,l,(l+r)>>1);
	all(root<<1|1,((l+r)>>1)+1,r);
}
int stk[250001],top;
int L[250001],R[250001];
int q[250001],h,t;
void upd(int a,int b){
	if(dis[a]!=n+1)return;
	// printf("upd %d %d\n",a,b);
	dis[a]=b;
	q[++t]=a;
	clear(1,1,n,a);
}
void solve(int root,int l,int r,int e,int tp,int d,int ql,int qr){
	// printf("%d %d %d\n",ql,qr,tp);
	if(1){
		for(;!vec[tp][root].empty();){
			int v=vec[tp][root].back();
			// printf("- %d %d %d %d\n",e,v,ql,qr);
			if(!(v>=ql&&v<=qr))break;
			upd(v,d);
			vec[tp][root].pop_back();
		}
	}
	if(l==r)return;
	if((l+r)>>1>=e)solve(root<<1,l,(l+r)>>1,e,tp,d,ql,qr);
	else solve(root<<1|1,((l+r)>>1)+1,r,e,tp,d,ql,qr);
}
int main(){
	scanf("%d",&T);
	for(int fd=1;fd<=T;++fd){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",a+i),dis[i]=n+1;
		dis[1]=0;
		build(1,1,n);
		top=0;
		stk[0]=0;
		for(int i=1;i<=n;++i){
			while(top&&a[stk[top]]>a[i])--top;
			if(a[i]<a[i-1])L[i]=stk[top]+1;
			stk[++top]=i;
		}
		top=0;
		for(int i=1;i<=n;++i){
			while(top&&a[stk[top]]<a[i])--top;
			if(a[i]>a[i-1])L[i]=stk[top]+1;
			stk[++top]=i;
		}
		top=0;
		stk[0]=n+1;
		for(int i=n;i;--i){
			while(top&&a[stk[top]]<a[i])--top;
			if(a[i]>a[i+1])R[i]=stk[top]-1;
			stk[++top]=i;
		}
		top=0;
		stk[0]=n+1;
		for(int i=n;i;--i){
			while(top&&a[stk[top]]>a[i])--top;
			if(a[i]<a[i+1])R[i]=stk[top]-1;
			stk[++top]=i;
		}
		for(int i=1;i<=n;++i){
			upd(1,1,n,L[i],i-1,i,2+(a[i]>a[i-1]));
			upd(1,1,n,i+1,R[i],i,(a[i]>a[i+1]));
		}
		all(1,1,n);
		h=t=0;
		q[++t]=1;
		// for(int i=1;i<=n;++i)printf("%d %d %d\n",i,L[i],R[i]);
		while(h<t){
			++h;
			// printf("-%d\n",q[h]);
			if(q[h]==n){
				printf("%d\n",dis[n]);
				break;
			}
			int i=q[h];
			solve(1,1,n,i,(a[i]<a[i-1]),dis[i]+1,L[i],i-1);
			solve(1,1,n,i,2+(a[i]<a[i+1]),dis[i]+1,i+1,R[i]);
		}
	}
}