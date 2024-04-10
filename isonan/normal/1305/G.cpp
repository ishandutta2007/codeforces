#include <queue>
#include <cstdio>
#include <algorithm>

struct point{
	int mx,skdmx,pos,skdpos;
	void add(int x,int y){
		if(x>mx){
			if(pos!=y)skdmx=mx,skdpos=pos;
			mx=x;
			pos=y;
		}
		else if(pos!=y&&x>skdmx)skdmx=x,skdpos=y;
	}
	void add(point a){
		add(a.mx,a.pos);
		add(a.skdmx,a.skdpos);
	}
}g[524288],con[200010];
int n,a[200010],f[200010],lim,L;
std::priority_queue<std::pair<int,int> >heap;
long long ans;
bool cando;
int find(int x){return f[x]?f[x]=find(f[x]):x;}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	lim=1;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		while(lim<=a[i])lim<<=1,++L;
	}
	++n;
	do{
		cando=0;
		for(int i=0;i<lim;i++)g[i]=(point){-1,-1,0,0};
		for(int i=1;i<=n;i++)con[i]=(point){-1,-1,0,0};
		for(int i=1;i<=n;i++)g[a[i]].add(a[i],find(i));
		for(int i=0;i<lim;i++)
			for(int j=0;j<=L;j++)
				if(!(i&(1<<j)))g[i|(1<<j)].add(g[i]);
		for(int i=1;i<=n;i++){
			int v,p;
			auto &now=g[(lim-1)^a[i]];
			(now.pos==find(i))?(v=now.skdmx,p=now.skdpos):(v=now.mx,p=now.pos);
//			printf("%d %d %d\n",a[i],v,p);
			if(p&&find(p)!=find(i))
				con[find(i)].add(a[i]+v,find(p));
		}
		for(int i=1;i<=n;i++)
			if(!f[i]&&con[i].pos){
				int fu=i,fv=find(con[i].pos);
				if(fu==fv)continue;
				ans+=con[i].mx;
				cando=1;
				f[fu]=fv;
			}
	}while(cando);
	for(int i=1;i<=n;i++)ans-=a[i];
	printf("%lld\n",ans);
}