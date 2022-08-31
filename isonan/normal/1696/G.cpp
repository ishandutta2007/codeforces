#include <cstdio>
#include <algorithm>

int n,q,x,y,a[200001];
double v[3];
bool can[3][3];
struct mat{
	double f[3][3];
	mat operator+(mat a){
		mat c;
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j){
				c.f[i][j]=-1e18;
				for(int k=0;k<3;++k)
					for(int l=0;l<3;++l)
						if(can[k][l])
							c.f[i][j]=std::max(c.f[i][j],f[i][k]+a.f[l][j]);
			}
		return c;
	}
	operator double(){
		double ans=-1e18;
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
				ans=std::max(ans,f[i][j]);
		return ans;
	}
	double getans(){
		double ans=-1e18;
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
				ans=std::max(ans,f[i][j]);
		return ans;
	}
}se[2000001];
void build(int root,int l,int r){
	if(l==r){
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j){
				if(i!=j)se[root].f[i][j]=-1e18;
				else se[root].f[i][j]=(double)a[l]*v[i];
			}
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	se[root]=se[root<<1]+se[root<<1|1];
}
void set(int root,int l,int r,int e){
	if(l==r){
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j){
				if(i!=j)se[root].f[i][j]=-1e18;
				else se[root].f[i][j]=(double)a[l]*v[i];
			}
		return;
	}
	if((l+r)>>1>=e)set(root<<1,l,(l+r)>>1,e);
	else set(root<<1|1,((l+r)>>1)+1,r,e);
	se[root]=se[root<<1]+se[root<<1|1];
}
mat query(int root,int l,int r,int el,int er){
	if(el<=l&&er>=r)return se[root];
	if(er<=((l+r)>>1))return query(root<<1,l,(l+r)>>1,el,er);
	else if(el>((l+r)>>1))return query(root<<1|1,((l+r)>>1)+1,r,el,er);
	else return query(root<<1,l,(l+r)>>1,el,er)+query(root<<1|1,((l+r)>>1)+1,r,el,er);
}
int main(){
	scanf("%d%d%d%d",&n,&q,&x,&y);
	v[1]=1.0/(double)(x+y),v[2]=1.0/(double)(std::max(x,y));
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			can[i][j]=(i==0)||(j==0)||(i==1&&j==1);
	build(1,1,n);
	for(int i=1,opt,v1,v2;i<=q;++i){
		scanf("%d%d%d",&opt,&v1,&v2);
		if(opt==1){
			a[v1]=v2;
			set(1,1,n,v1);
		}
		else{
			mat ans=query(1,1,n,v1,v2);
			printf("%.10lf\n",ans.getans());
		}
	}
}