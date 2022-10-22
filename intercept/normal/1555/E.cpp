#include<bits/stdc++.h>
using namespace std;
const int M=1e6+9;
int n,m;
int L[M],R[M],w[M],id[M];
int vis[M<<2],val[M<<2];
void update(int now,int l,int r,int x,int y,int v){
	if(x<=l&r<=y){
		vis[now]+=v;
		if(vis[now]==0)val[now]=val[now<<1]+val[now<<1|1];
		if(vis[now]==1)val[now]=r-l+1;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)update(now<<1,l,mid,x,y,v);
	if(y>mid)update(now<<1|1,mid+1,r,x,y,v);
	
	if(vis[now])val[now]=r-l+1;	
	else val[now]=val[now<<1]+val[now<<1|1];
	
}
int main(){
	scanf("%d%d",&n,&m);
	m--;
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&L[i],&R[i],&w[i]);
		R[i]--;
		id[i]=i;
	}
	sort(id+1,id+n+1,[&](const int&l,const int&r){return w[l]<w[r];});
	int mi=1e9;
	for(int o=1,l=1;o<=n;++o){
		int r=id[o];
		update(1,1,m,L[r],R[r],1);
		while(1){
			update(1,1,m,L[id[l]],R[id[l]],-1);
			if(val[1]!=m){
				update(1,1,m,L[id[l]],R[id[l]],1);
				break;
			}
			l++;
		}
		if(val[1]==m)mi=min(mi,w[r]-w[id[l]]);
	}
	printf("%d\n",mi);
	return 0;
}