#include <cstdio>
#include <cstring>

int n,b[1000001];
long long a[1000001];
// struct BIT{
// 	int c[600001],lim;
// 	void init(){
// 		memset(c,0,(lim+1)<<3);
// 	}
// 	void update(int ind,int num){
// 		for(;ind;ind-=ind&-ind)c[ind]+=num;
// 	}
// 	int query(int ind){
// 		int tot=0;
// 		for(;ind<=lim;ind+=ind&-ind)tot+=c[ind];
// 		return tot;
// 	}
// }cmn[60],cmx[60];
int cmn[61],cmx[61];
int pmn[1000001],pmx[1000001],Bmn[1000001],Bmx[1000001];
bool cmp(int l,int r){
	return (a[l]<a[r])||(a[l]==a[r]&&l<r);
}
long long ans=0;
void solve(int l,int r){
	if(l==r){
		++ans;
		return;
	}
	int mid=(l+r)>>1;
	memset(cmn,0,sizeof cmn);
	memset(cmx,0,sizeof cmx);
	// for(int i=0;i<60;++i){
	// 	cmn[i].lim=mid-l+1;
	// 	cmn[i].init();
	// 	cmx[i].lim=mid-l+1;
	// 	cmx[i].init();
	// }
	for(int i=mid,mn,mx,p=mid,pmn=mid,pmx=mid;i>=l;--i){
		if(i==mid)mn=mx=i;
		else{
			if(cmp(i,mn))mn=i;
			if(cmp(mx,i))mx=i;
		}
		while(p<r&&cmp(mn,p+1)&&cmp(p+1,mx))++p;
		while(pmn<r&&cmp(mn,pmn+1))++pmn;
		while(pmx<r&&cmp(pmx+1,mx))++pmx;
		if(b[mn]==b[mx])ans+=p-mid;
		::pmn[i]=pmn;
		::pmx[i]=pmx;
		Bmn[i]=b[mn];
		Bmx[i]=b[mx];
		// printf("%d %d %d\n",i,pmn,pmx);
	}
	for(int i=mid+1,mn,mx,p=mid+1,pmn=mid+1,pmx=mid+1,mnr=mid,mxr=mid;i<=r;++i){
		if(i==mid+1)mn=mx=i;
		else{
			if(cmp(i,mn))mn=i;
			if(cmp(mx,i))mx=i;
		}
		while(p>l&&cmp(mn,p-1)&&cmp(p-1,mx))--p;
		while(pmn>l&&cmp(mn,pmn-1)){
			--pmn;
			if(::pmx[pmn]>=i)++cmx[Bmx[pmn]];
		}
		while(pmx>l&&cmp(pmx-1,mx)){
			--pmx;
			if(::pmn[pmx]>=i)++cmn[Bmn[pmx]];
		}
		if(b[mn]==b[mx])ans+=mid+1-p;
		while(mnr>=pmn&&::pmx[mnr]<i){
			if(::pmx[mnr]>=i-1)--cmx[Bmx[mnr]];
			--mnr;
		}
		while(mxr>=pmx&&::pmn[mxr]<i){
			if(::pmn[mxr]>=i-1)--cmn[Bmn[mxr]];
			--mxr;
		}
		ans+=cmn[b[mx]];
		// printf("%d %d %d %d\n",i,cmx[b[mn]],pmn,mnr);
		ans+=cmx[b[mn]];
	}
	// printf("%d %d %d\n",l,r,ans);
	solve(l,mid);
	solve(mid+1,r);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld",a+i);
		long long tem=a[i];
		while(tem){
			++b[i];tem-=tem&-tem;
		}
	}
	// for(int i=1;i<=n;++i)
	solve(1,n);
	printf("%lld\n",ans);
}