#include <cstdio>
#include <algorithm>

const int P=1000000007;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
int t,n,a[200001];
int f[200001],g[200001];
int orig[200001],top;
bool cmp(int e,int f){
	return a[e]<a[f]||(a[e]==a[f]&&e<f);
}
struct info{
	int a,b,mx;
	info operator+(info r){
		info c;
		c.a=add(a,r.a);
		if(mx==r.mx){
			c.mx=mx;
			c.b=add(b,r.b);
		}
		else if(mx<r.mx){
			c.mx=r.mx;
			c.b=r.b;
		}
		else{
			c.mx=mx;
			c.b=b;
		}
		return c;
	}
}c[200001];
void update(int ind,info num){
	for(;ind<=top;ind+=ind&-ind)c[ind]=c[ind]+num;
}
info query(int ind){
	info tot=(info){0,0,0};
	for(;ind;ind-=ind&-ind)tot=tot+c[ind];
	return tot;
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		top=0;
		for(int i=1;i<=n;++i)scanf("%d",a+i),orig[++top]=a[i];
		for(int i=1;i<=n;++i)f[i]=g[i]=0,c[i]=(info){0,0,0};
		std::sort(orig+1,orig+top+1);
		top=std::unique(orig+1,orig+top+1)-orig-1;
		for(int i=1;i<=n;++i){
			a[i]=std::lower_bound(orig+1,orig+top+1,a[i])-orig;
			f[i]=add(query(a[i]-1).a,1);
			update(a[i],(info){f[i],0,0});
		}
		for(int i=1;i<=n;++i)c[i]=(info){0,0,0};
		int ans=0;
		for(int i=n,mx=0x7f7f7f7f;i;--i){
			auto now=query(top-a[i]);
			now=now+(info){1,1,i};
			g[i]=now.a;
			update(top-a[i]+1,now);
			ans=add(ans,mul(f[i],sub(g[i],now.b)));
			// printf("%d %d %d %d\n",f[i],g[i],now.b,now.mx);
		}
		printf("%d\n",ans);
	}
}