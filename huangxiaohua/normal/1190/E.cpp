#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double pi=acos(-1);
int i,j,k,t,n,m,it,f[100500][21],g[100500][21];
double x[100500],y[100500],mx=1e18,a[100500],d[100500];
bool vis[100500];

struct SB{
	int id;
	double l,r;
	bool operator<(const SB a)const{return l<a.l;}
}s[200500];

bool chk(double md){
	int i,j,k,nmsl;
	it=0;
	for(i=1;i<=n;i++){
		double t1=acos(md/d[i]);
		s[++it]={i,a[i]-t1,a[i]+t1};
		if(s[it].l<0){
			s[it].l+=pi*2;s[it].r+=pi*2;
		}
		it++;s[it]=s[it-1];
		s[it].l+=pi*2;s[it].r+=pi*2;
	}
	
	sort(s+1,s+it+1);
	memset(g,0,sizeof(g));
	memset(f,0,sizeof(f));

	double nmsl2=1e18;
	for(nmsl=n;;nmsl++){
		nmsl2=min(nmsl2,s[nmsl].r);
		if(nmsl2<s[nmsl].l){
			nmsl--;break;
		}
	}
	for(i=n;i>=1;i--){
		while(s[nmsl].l>s[i].r)nmsl--;
		f[s[i].id][0]=s[nmsl+1].id;
		g[s[i].id][0]=nmsl-i+1;
	}
	for(k=1;k<=18;k++){
		for(i=1;i<=n;i++){
			f[i][k]=f[f[i][k-1]][k-1];
			g[i][k]=g[i][k-1]+g[f[i][k-1]][k-1];
			g[i][k]=min(g[i][k],n+1);
		}
	}
	for(i=1;i<=n;i++){
		int sb=0,cur=i;
		k=m;
		for(j=18;j>=0;j--){
			if((1<<j)<=k){
				k-=(1<<j);
				sb+=g[cur][j];
				cur=f[cur][j];
			}
		}
		if(sb>=n)return 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%lf%lf",&x[i],&y[i]);
		if(!x[i]&&!y[i]){puts("0");return 0;}
		d[i]=sqrt(x[i]*x[i]+y[i]*y[i]);
		mx=min(mx,d[i]);
		a[i]=atan2(y[i],x[i]);
	}
	double l=0,r=mx,md,ans;
	t=40;
	while(t--){
		md=(l+r)/2;
		if(chk(md))ans=max(ans,md),l=md;
		else r=md;
	}
	printf("%.20lf",ans);
}