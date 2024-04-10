#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long

int n,q,x[100010],y[100010],orig[100010],top,que[100010],Cor[100010][3];
double ans[100010];
__int128 gcd(__int128 a,__int128 b){return (!b)?a:gcd(b,a%b);}
struct fract{
	__int128 x,y;
	void simp(){
		__int128 _gcd=gcd(x,y);
		x/=_gcd,y/=_gcd;
		if(y<0)x=-x,y=-y;
	}
	fract(__int128 a=0,__int128 b=1){
		x=a,y=b;
		simp();
	}
	fract operator*(fract a){
		fract c;
		c.x=a.x*x;
		c.y=a.y*y;
		c.simp();
		return c;
	}
	fract operator+(fract a){
		fract c;
		c.x=a.x*y+a.y*x;
		c.y=a.y*y;
		c.simp();
		return c;
	}
	fract operator/(const __int128 &n){
		fract c=*this;
		c.y*=n;
		c.simp();
		return c;
	}
	bool operator<(const fract &a)const{
		return x*a.y<y*a.x;
	}
	bool operator==(const fract &a)const{
		return x==a.x&&y==a.y;
	}
	operator double(){
		return (double)x/(double)y;
	}
};
std::vector<fract>vec[100010];
fract cord[1000010];
fract f(int a,int b,int y){
	if(x[a]==x[b])return (fract){x[a],1};
	else{
		fract k=(fract){x[a]-x[b],(orig[::y[a]]-orig[::y[b]])};
//		printf("f %d %d %d : %lf\n",a,b,y,x[a]+k*(double)(orig[y]-orig[::y[a]]));
		return (fract){x[a],1}+k*(fract){orig[y]-orig[::y[a]],1};
	} 
}
double integral(double l,double r,double len){
//	printf("integral %lf %lf %lf %lf\n",l,r,len,(l+r)*len/2.0);
	return (l+r)*len/2.0;
}
struct segtree{
	double lazy[3][2000010];
	void update(int root,int l,int r,int el,int er,int ind,double y){
//		if(root==1&&!ind&&el<=9&&er>=9)printf("update %d %d %d %lf\n",el,er,ind,y);
		if(el>r||er<l)return;
		if(el<=l&&er>=r){
			lazy[ind][root]+=y;
			return;
		}
		update(root<<1,l,(l+r)>>1,el,er,ind,y);
		update(root<<1|1,((l+r)>>1)+1,r,el,er,ind,y);
	}
	double query(int root,int l,int r,int e){
		double v=lazy[0][root]+lazy[1][root]*cord[e]+lazy[2][root]*cord[e]*cord[e];
//		printf("query %d %d %d %d %lf %lf %lf\n",root,l,r,e,lazy[0][root],lazy[1][root],lazy[2][root]);
		if(l==r)return v;
		if((l+r)>>1>=e)return v+query(root<<1,l,(l+r)>>1,e);
		else return v+query(root<<1|1,((l+r)>>1)+1,r,e);
	}
	void addl(int l,int r,double len){
		if(l>r)std::swap(l,r);
		double coe=len/((cord[r]-cord[l])*2.0);
		if(l!=r){
			update(1,1,top,l,r,2,coe);
			update(1,1,top,l,r,1,-2.*coe*cord[r]);
			update(1,1,top,l,r,0,coe*cord[r]*cord[r]);
		}
		update(1,1,top,1,l-1,0,(len*(cord[r]-cord[l])/2.0)+(double)(cord[l])*len);
		update(1,1,top,1,l-1,1,-len);
	}
	void addr(int l,int r,double len){
		if(l>r)std::swap(l,r);
		double coe=len/((cord[r]-cord[l])*2.0);
		if(l!=r){
			update(1,1,top,l,r,2,coe);
			update(1,1,top,l,r,1,-2.*coe*cord[l]);
			update(1,1,top,l,r,0,coe*cord[l]*cord[l]);
		}
//		printf("addr %d %d %lf %lf\n",l,r,len,len*(cord[r]-cord[l])/2.0);
		update(1,1,top,r+1,top,0,(len*(cord[r]-cord[l])/2.0)-(double)cord[r]*len);
		update(1,1,top,r+1,top,1,len);
	}
}mid[2],l,r;
signed main(){
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++)scanf("%lld%lld",x+i,y+i),orig[i]=y[i];
	std::sort(orig+1,orig+n+1);
	int lim=std::unique(orig+1,orig+n+1)-orig-1;
	for(int i=1;i<=n;i++)y[i]=std::lower_bound(orig+1,orig+lim+1,y[i])-orig;//,printf("%d\n",y[i]);
	for(int i=1;i<=n;i++){
		int u=i,v=(i==n)?1:(i+1);
		if(y[u]>y[v])std::swap(u,v);
		for(int j=y[u];j<y[v];j++)
			vec[j].push_back(f(u,v,j));
		if(y[v]==lim)vec[lim].push_back(f(u,v,lim));
	}
	for(int i=1;i<=n;i++)cord[++top]=(fract){x[i],1};
	for(int i=1;i<=lim;i++)cord[++top]=vec[i][0],cord[++top]=vec[i][1];
	double ans=0.;
	for(int i=1;i<=lim;i++)if(vec[i][1]<vec[i][0])std::swap(vec[i][0],vec[i][1]);
	for(int i=1;i<=lim;i++){
//		printf("%lf %lf %lf\n",(double)orig[i],(double)vec[i][0],(double)vec[i][1]);
		cord[++top]=(vec[i][0]+vec[i][1])/2;
		if(i<lim)ans+=integral(vec[i][1]-vec[i][0],vec[i+1][1]-vec[i+1][0],(double)orig[i+1]-(double)orig[i]);
	}
	ans/=2.0;
	for(int i=1;i<=q;i++){
		scanf("%lld",que+i);
		cord[++top]=(fract){que[i],1};
	}
	std::sort(cord+1,cord+top+1);
	top=std::unique(cord+1,cord+top+1)-cord-1;
	for(int i=1;i<=lim;i++){
		Cor[i][0]=std::lower_bound(cord+1,cord+top+1,vec[i][0])-cord,
		Cor[i][1]=std::lower_bound(cord+1,cord+top+1,(vec[i][0]+vec[i][1])/2)-cord,
		Cor[i][2]=std::lower_bound(cord+1,cord+top+1,vec[i][1])-cord;
//		printf("%lf %lf %lf\n",(double)vec[i][0],(double)(vec[i][0]+vec[i][1])/2,(double)vec[i][1]);
	}
//	for(int i=1;i<=top;i++)printf("(%d/%d)",cord[i].x,cord[i].y);putchar('\n');
	for(int i=1;i<lim;i++){
//		printf("%d %d %d\n",Cor[i][0],Cor[i][1],Cor[i][2]);
		l.addl(Cor[i][0],Cor[i+1][0],(double)(orig[i+1]-orig[i]));
		mid[0].addl(Cor[i][1],Cor[i+1][1],(double)(orig[i+1]-orig[i]));
		mid[1].addr(Cor[i][1],Cor[i+1][1],(double)(orig[i+1]-orig[i]));
		r.addr(Cor[i][2],Cor[i+1][2],(double)(orig[i+1]-orig[i]));
	}
//	printf("*%lf\n",ans);
	for(int i=1;i<=q;i++){
		int u=std::lower_bound(cord+1,cord+top+1,(fract){que[i],1})-cord;
//		printf("%d\n",u);
//		printf("%lf\n",mid[0].query(1,1,top,u));
//		printf("%lf\n",mid[1].query(1,1,top,u));
//		printf("%lf\n",l.query(1,1,top,u));
//		printf("%lf\n",r.query(1,1,top,u));
		printf("%.9lf\n",ans+mid[0].query(1,1,top,u)+mid[1].query(1,1,top,u)-l.query(1,1,top,u)-r.query(1,1,top,u));
	}
}
//5 1
//0 0
//3 1
//1 2
//3 3
//0 4
//2