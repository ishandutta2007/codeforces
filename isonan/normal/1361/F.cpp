#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#define int long long

int n,P[400001],W[400001],fa[400001],ch[400001][2],L[400001],R[400001],S[400001];
long long f[400001];
int build(int l,int r){
	if(l>r){L[l]=R[l]=l;return l;}
	int p=l;
	for(int i=l+1;i<=r;i++)if(W[p]>W[i])p=i;
	fa[ch[p+n][0]=build(l,p-1)]=p+n;
	fa[ch[p+n][1]=build(p+1,r)]=p+n;
	L[p+n]=l,R[p+n]=r+1;
	return p+n;
}
bool vis[400001];
int now;
struct BIT{
	int c[400001],S,tag[400010];
	void update(int ind,int x){
		if(tag[0]<now)tag[0]=now,S=0; 
		S+=x;
		for(;ind<=n;ind+=ind&-ind){
			if(tag[ind]<now)tag[ind]=now,c[ind]=0;
			c[ind]+=x;
		}
	}
	int getsmall(int ind){
		--ind;
		int tot=0;
		for(;ind;ind-=ind&-ind){
			if(tag[ind]<now)tag[ind]=now,c[ind]=0;
			tot+=c[ind];
		}
		return tot;
	}
	int getbig(int ind){
		if(tag[0]<now)tag[0]=now,S=0; 
		return S-getsmall(ind);
	}
}_L,_R;
std::vector<std::pair<int,int> >vec[400010];
int LCA(int x,int y){
	int tem=x;
	while(tem)vis[tem]=1,tem=fa[tem];
	tem=y;
	while(tem){
		if(vis[tem])break;
		tem=fa[tem];
	}
	while(x)vis[x]=0,x=fa[x];
	return tem;
}
bool son(int x){return ch[fa[x]][1]==x;}
long long ans[200010];
signed main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",P+i);
	for(int i=1;i<n;i++)scanf("%lld",W+i);
	build(1,n-1);
	int q;
	scanf("%lld",&q);
	for(int i=1;i<(n<<1);i++){
		S[i]=(R[i]-L[i]+1);
		if(fa[i]){
			for(int j=L[i];j<=R[i];j++)
				vec[fa[i]].push_back(std::make_pair((son(i)?-q-1:0),P[j]));
		}
	}
	for(int i=1,x,y;i<=q;i++){
		scanf("%lld%lld",&x,&y);
		if(x!=y){
			int tem=x,lca=LCA(x,y);
			while(tem!=lca){
				vec[fa[tem]].push_back(std::make_pair((son(tem)?-q-1:0)+i,-P[x]));
				tem=fa[tem];
			}
			tem=y;
			while(tem!=lca){
				vec[fa[tem]].push_back(std::make_pair((son(tem)?-q-1:0)+i,-P[y]));
				tem=fa[tem];
			}
			tem=x;
			while(tem!=lca){
				vec[fa[tem]].push_back(std::make_pair((son(tem)?-q-1:0)+i,P[y]));
				tem=fa[tem];
			}
			tem=y;
			while(tem!=lca){
				vec[fa[tem]].push_back(std::make_pair((son(tem)?-q-1:0)+i,P[x]));
				tem=fa[tem];
			}
			std::swap(P[x],P[y]);
		}
//		printf("%lld\n",ans);
	}
	for(int i=n+1;i<(n<<1);i++){
//		if(i%1000==0)fprintf(stderr,"%d\n",i);
		++now;
		long long Siz=1ll*S[ch[i][0]]*S[ch[i][1]],f=0;
		for(int j=0;j<vec[i].size();j++){
//			fprintf(stderr,"%d\n",j);
			int p=vec[i][j].first,v=vec[i][j].second,p1,p2;
			p1=(p<0),p2=(v<0)?-1:1;
			if(p1)p+=q+1;if(p2==-1)v=-v;
			ans[p]-=std::min(f,Siz-f);
//			printf("add %d %d %d %d\n",i,p1,p2,v);
//			printf("%d ",f);
			if(p1)f+=p2*_L.getbig(v);//,printf("%d\n",_L.getbig(v));
			else f+=p2*_R.getsmall(v);
//			printf("%d\n",f);
			if(p1)_R.update(v,p2);
			else _L.update(v,p2);
			ans[p]+=std::min(f,Siz-f);
		}
	}
	for(int i=1;i<=q;i++)ans[i]+=ans[i-1],printf("%lld\n",ans[i]);
	return 0;
}