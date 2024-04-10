#include<bits/stdc++.h>
using namespace std;
int n,m,q,k,a,b,c,d;
int f[59],sum[59];
long long ans=0;
struct P{
	int u,v,w;
	bool operator < (const P&o)const{
		return abs(w)==abs(o.w)?w>o.w:abs(w)<abs(o.w);
	}
}p[309],s[309];
struct Q{
	long long u;
	int v,w;
	bool operator < (const Q&o)const{
		return w<o.w;
	}
}t[200009];
int num=0;
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void work(int x){
	Q &o=t[++num]=Q{0ll,0,0};
	for(int i=1;i<=m;++i){
		s[i]=p[i];
		s[i].w=s[i].w-x;
		
	}
	for(int i=1;i<=n;++i)f[i]=i,sum[i]=1;
	sort(s+1,s+m+1);
	for(int i=1,u,v,d=0;i<=m;++i){
		u=find(s[i].u),v=find(s[i].v);
		if(u!=v){
			if(sum[u]>sum[v])swap(u,v);
			f[u]=v;
			sum[v]+=sum[u];
			o.u+=abs(s[i].w);
			if(s[i].w<=0)o.v++;
			else o.v--;
			d++;
			if(d==n-1)break;
		}
	}
	o.w=x;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&p[i].u,&p[i].v,&p[i].w);
	}
	sort(p+1,p+m+1);
	work(0);
	for(int i=1;i<=m;++i){
		work(p[i].w);
		for(int j=i+1;j<=m;++j)work(p[i].w+p[j].w+1>>1);
	}
	sort(t+1,t+num+1);
	scanf("%d%d%d%d%d",&q,&k,&a,&b,&c);
	for(int i=1,l,r;i<=k;++i){
		if(i<=q)scanf("%d",&d);
		else d=(1ll*d*a+b)%c;
		l=1,r=num;
		while(l<=r){
			int mid=l+r>>1;
			if(t[mid].w<=d)l=mid+1;
			else r=mid-1;
		}
		ans^=t[r].u+1ll*(d-t[r].w)*t[r].v;
	} 
	printf("%lld\n",ans);
	return 0;
}