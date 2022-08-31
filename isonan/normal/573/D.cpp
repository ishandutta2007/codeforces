#include <cstdio>
#include <utility>
#include <algorithm>

int n,q;
std::pair<int,int>w[30001],h[30001];
int match[30001],ow[30001],oh[30001];
int num[4];
long long Val[30001][3];
long long Calc(int x,int y){
	long long v;
	if(match[x]==y)v=-1e16;
	else v=1ll*w[x].first*h[y].first;
	return v;
}
struct matrix{
	long long num[3][3];
	matrix operator*(matrix a){
		matrix c;
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j){
				c.num[i][j]=-1e16;
				for(int k=0;k<3;++k)
					c.num[i][j]=std::max(c.num[i][j],num[i][k]+a.num[k][j]);
			}
		return c;
	}
	void clear(){
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
				num[i][j]=-1e16;
	}
}se[300001];
void set(int root,int l,int r,int e){
	if(l==r){
		se[root].clear();
		se[root].num[0][1]=0;
		se[root].num[1][2]=0;
		se[root].num[0][0]=Val[l][0];
		se[root].num[1][0]=Val[l][1];
		se[root].num[2][0]=Val[l][2];
		return;
	}
	if((l+r)>>1>=e)set(root<<1,l,(l+r)>>1,e);
	else set(root<<1|1,((l+r)>>1)+1,r,e);
	se[root]=se[root<<1]*se[root<<1|1];
}
void recalc(int x){
	for(int i=1;i<=3;++i){
		for(int j=std::max(x,i);j<=n&&j<=x+i-1;++j){
			long long &p=Val[j][i-1];
			p=-1e16;
			for(int k=1;k<=i;++k)num[k]=k;
			do{
				long long sum=0;
				for(int k=1;k<=i;++k)sum+=Calc(j-k+1,j-num[k]+1);
				if(p<sum)p=sum;
			}while(std::next_permutation(num+1,num+i+1));
		}
	}
	for(int i=0;i<3&&x+i<=n;++i)
		set(1,1,n,x+i);
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)scanf("%d",&w[i].first),w[i].second=i;
	for(int i=1;i<=n;++i)scanf("%d",&h[i].first),h[i].second=i;
	std::sort(w+1,w+n+1);
	std::sort(h+1,h+n+1);
	for(int i=1;i<=n;++i)ow[w[i].second]=i,oh[h[i].second]=i;
	for(int i=1;i<=n;++i)match[ow[i]]=oh[i];
	for(int i=1;i<=n;++i)
		for(int j=0;j<3;++j)
			Val[i][j]=-1e16;
	for(int i=1;i<=n;++i)recalc(i);
	// for(int i=1;i<=n;++i)printf("%d ",match[i]);putchar('\n');
	for(int i=1,a,b;i<=q;++i){
		scanf("%d%d",&a,&b);
		a=ow[a],b=ow[b];
		std::swap(match[a],match[b]);
		recalc(a);
		recalc(b);
		printf("%lld\n",se[1].num[0][0]);
	// for(int i=1;i<=n;++i,putchar('\n'))
	// 	for(int j=0;j<3;++j)
	// 		printf("%lld ",Val[i][j]);
	}
}