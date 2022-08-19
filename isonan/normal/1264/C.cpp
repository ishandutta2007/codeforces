#include <cstdio>
#include <set>

const int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;} 
struct matrix{
	int num[2][2];
}se[1000001];
matrix operator*(const matrix &a,const matrix &b){
	matrix c;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++){
			c.num[i][j]=(1ll*a.num[i][0]*b.num[0][j]+1ll*a.num[i][1]*b.num[1][j])%P;
		}
	return c;
}
int p[200001],n,q,inv[101];
void build(int root,int l,int r){
	if(l==r){
		se[root].num[0][0]=se[root].num[1][0]=mul(100,inv[p[l]]);
		se[root].num[0][1]=0;
		se[root].num[1][1]=1;
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	se[root]=se[root<<1]*se[root<<1|1];
}
matrix query(int root,int l,int r,int el,int er){
	if(el<=l&&er>=r)return se[root];
	int mid=(l+r)>>1;
	if(el>mid)return query(root<<1|1,((l+r)>>1)+1,r,el,er);
	else if(er<=mid)return query(root<<1,l,(l+r)>>1,el,er);
	return query(root<<1,l,(l+r)>>1,el,er)*query(root<<1|1,((l+r)>>1)+1,r,el,er);
}
std::set<int>set;
int ans;
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",p+i);
	inv[0]=inv[1]=1;
	for(int i=2;i<=100;i++)inv[i]=mul(P-P/i,inv[P%i]);
	build(1,1,n);
	set.insert(1);
	set.insert(n+1);
	ans=se[1].num[1][0];
	for(int i=1,tem;i<=q;i++){
		scanf("%d",&tem);
		if(set.count(tem)){
			auto it=set.find(tem);
			int x=*(--it),y;
			++it;
			y=*(++it);
			ans=sub(ans,query(1,1,n,x,tem-1).num[1][0]);
			ans=sub(ans,query(1,1,n,tem,y-1).num[1][0]);
			ans=add(ans,query(1,1,n,x,y-1).num[1][0]);
			set.erase(tem);
		}
		else{
			set.insert(tem);
			auto it=set.find(tem);
			int x=*(--it),y;
			++it;
			y=*(++it);
			ans=add(ans,query(1,1,n,x,tem-1).num[1][0]);
			ans=add(ans,query(1,1,n,tem,y-1).num[1][0]);
			ans=sub(ans,query(1,1,n,x,y-1).num[1][0]);
		}
		printf("%d\n",ans);
	}
}