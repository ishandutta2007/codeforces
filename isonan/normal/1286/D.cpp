#include <cstdio>
#include <algorithm>

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
struct matrix{
	int num[2][2];
	matrix operator*(matrix a){
		static matrix c;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				c.num[i][j]=(1ll*num[i][0]*a.num[0][j]+1ll*num[i][1]*a.num[1][j])%P;
		return c;
	}
}se[1000001],f[100001];
int n,top,x[100001],v[100001],p[100001];
void build(int root,int l,int r){
	if(l==r){
		se[root]=f[l];
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	se[root]=se[root<<1]*se[root<<1|1];
}
void update(int root,int l,int r,int e){
	if(l==r){
		se[root]=f[l];
		return;
	}
	if((l+r)>>1>=e)update(root<<1,l,(l+r)>>1,e);
	else update(root<<1|1,((l+r)>>1)+1,r,e);
	se[root]=se[root<<1]*se[root<<1|1];
}
struct col{
	int u,p1,p2,a,b;
}num[300001];
bool cmp(col a,col b){
	return 1ll*a.a*b.b<1ll*a.b*b.a;
}
int main(){
	scanf("%d",&n);
	int inv=qsm(100,P-2);
	for(int i=1;i<=n;i++)scanf("%d%d%d",x+i,v+i,p+i),p[i]=mul(p[i],inv);
	for(int i=1;i<=n;i++){
		f[i].num[0][0]=f[i].num[1][0]=sub(1,p[i]);
		f[i].num[0][1]=f[i].num[1][1]=p[i];
	}
	build(1,1,n);
	for(int i=1;i<n;i++){
		num[++top]=(col){i+1,1,0,x[i+1]-x[i],v[i]+v[i+1]};
		if(v[i]>v[i+1])num[++top]=(col){i+1,1,1,x[i+1]-x[i],v[i]-v[i+1]};
		if(v[i]<v[i+1])num[++top]=(col){i+1,0,0,x[i+1]-x[i],v[i+1]-v[i]};
	}
	std::sort(num+1,num+top+1,cmp);
	int ans=0;
	for(int i=1,last=1;i<=top;i++){
		f[num[i].u].num[num[i].p1][num[i].p2]=0;
		update(1,1,n,num[i].u);
		int now=add(se[1].num[0][0],se[1].num[0][1]);
		ans=add(ans,mul(sub(last,now),mul(num[i].a,qsm(num[i].b,P-2))));
		last=now;
	}
	printf("%d\n",ans);
}