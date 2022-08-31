#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

typedef std::vector<int> poly;
int t1[1600001],t2[1600001],w[1600001],R[1600001],lim,n;
long long x;
const int P=998244353;
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
void NTT(int *a){
	for(int i=0;i<lim;i++)if(i<R[i])std::swap(a[i],a[R[i]]);
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=(i<<1))
			for(int k=0;k<i;k++){
				const int Ny=mul(a[i+j+k],w[i+k]);
				a[i+j+k]=sub(a[j+k],Ny);
				a[j+k]=add(a[j+k],Ny);
			}
}
poly operator*(poly a,poly b){
	int size=a.size()+b.size()-1;
	lim=1;
	while(lim<=size)lim<<=1;
	for(int i=0;i<lim;i++)R[i]=(R[i>>1]>>1)|((i&1)?lim>>1:0);
	memset(t1,0,lim<<2);
	memset(t2,0,lim<<2);
//	printf("mul\n");
//	for(int i=0;i<a.size();i++)printf("%d ",a[i]);putchar('\n');
//	for(int i=0;i<b.size();i++)printf("%d ",b[i]);putchar('\n');
	for(int i=a.size()-1;~i;--i)t1[i]=a[i];
	for(int i=b.size()-1;~i;--i)t2[i]=b[i];
	NTT(t1);
	NTT(t2);
	for(int i=0;i<lim;i++)t1[i]=mul(t1[i],t2[i]);
	NTT(t1);
	std::reverse(t1+1,t1+lim);
	int inv=qsm(lim,P-2);
	a.resize(size);
	for(int i=0;i<size;i++)a[i]=mul(t1[i],inv);
//	for(int i=0;i<a.size();i++)printf("%d ",a[i]);putchar('\n');
	return a;
}
void operator+=(poly &a,poly b){
	if(a.size()<b.size())a.resize(b.size());
	for(int i=0;i<b.size();i++)a[i]=add(a[i],b[i]);
}
struct matrix{
	poly num[2][2];
	matrix operator*(matrix a){
		matrix c;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++){
				c.num[i][j].clear();
				for(int k=0;k<2;k++)
					c.num[i][j]+=num[i][k]*a.num[k][j];
			}
		return c;
	}
}mat[100001];
poly ans[100001];
int head[100001],nxt[200001],b[200001],k,son[100001],light[100001],top[100001],size[100001],fa[100001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs1(int x,int f){
	size[x]=1;
	fa[x]=f;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs1(b[i],x);
			size[x]+=size[b[i]];
			if(size[son[x]]<size[b[i]])son[x]=b[i];
		}
}
void solve(int l,int r){
	if(l==r)return;
	solve(l,(l+r)>>1),solve(((l+r)>>1)+1,r);
	mat[l]=mat[((l+r)>>1)+1]*mat[l];
//	for(int i=0;i<2;i++)
//		for(int j=0;j<2;j++,putchar('\n'))
//			for(int k=0;k<mat[l].num[i][j].size();k++)
//				printf("%d ",mat[l].num[i][j][k]);
//	for(int i=0;i<2;i++)
//		for(int j=0;j<2;j++,putchar('\n'))
//			for(int k=0;k<mat[((l+r)>>1)+1].num[i][j].size();k++)
//				printf("%d ",mat[((l+r)>>1)+1].num[i][j][k]);
//	printf("solve %d %d\n",l,r);
//	for(int i=0;i<2;i++)
//		for(int j=0;j<2;j++,putchar('\n'))
//			for(int k=0;k<mat[l].num[i][j].size();k++)
//				printf("%d ",mat[l].num[i][j][k]);
}
void getans(int x){
	int top=0;
	for(int tem=x;tem;tem=son[tem]){
		for(int j=head[tem];j;j=nxt[j])
			if(b[j]!=fa[tem]&&b[j]!=son[tem])
				getans(b[j]);
	}
	for(int tem=x;tem;tem=son[tem]){
		++top;
		if(ans[tem].size()<1)ans[tem].resize(1);
		ans[tem][0]=add(ans[tem][0],1);
		ans[tem].push_back(0);
		for(int i=ans[tem].size()-1;i;i--)ans[tem][i]=ans[tem][i-1];
		ans[tem][0]=0;
		mat[top].num[0][0]=mat[top].num[1][0]=ans[tem];
		ans[tem].clear();
		mat[top].num[0][1].clear();
		mat[top].num[1][1].resize(1);
		mat[top].num[1][1][0]=1;
	}
	solve(1,top);
	ans[fa[x]]=mat[1].num[1][0];
//	printf("getans %d\n",x);
//	for(int i=0;i<ans[fa[x]].size();i++)
//		printf("%d ",ans[fa[x]][i]);
//	putchar('\n');
}
int main(){
	scanf("%d%lld",&n,&x);
	for(int i=1,wn;i<(800000);i<<=1){
		wn=qsm(3,(P-1)/(i<<1)),w[i]=1;
		for(int j=1;j<i;j++)w[i+j]=mul(w[i+j-1],wn);
	}
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u);
	dfs1(1,0);
	getans(1);
	int fin=0;
	for(int i=1,Mul=1;i<ans[0].size();i++){
//		printf("%d\n",Mul);
		fin=add(fin,mul(ans[0][i],Mul));
		Mul=mul(Mul,(x+i)%P);
		Mul=mul(Mul,qsm(i,P-2));
	}
	printf("%d\n",fin);
}