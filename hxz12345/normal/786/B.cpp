#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((ch!='-')&&(!isdigit(ch))) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}struct SegmentTree{
int x,l,r,id;} tree[2][2001010];
int leaf[3][301010];
bool vis[3001010];
long long dis[4001010];
priority_queue< pair<long long ,int > > q;
int opt,x,y,n,Q,rt,i,l,r,v,w,u,cnt,lim[10],a[8001010],b[8001010],c[8001010],d[3001010];
void add(int x,int y,int z){cnt++;a[cnt]=y;b[cnt]=d[x];c[cnt]=z;d[x]=cnt;}
int ls(int sta,int x){return x<<1;}
int rs(int sta,int x){return x<<1|1;}
//1:
//0: 
void build(int sta,int x,int l,int r){
	tree[sta][x].l=l;tree[sta][x].r=r;tree[sta][x].id=x+lim[sta];
	if (l==r){
		leaf[sta][l]=x+lim[sta];return ;
	}
	int mid=(l+r)/2;
	build(sta,x<<1,l,mid);build(sta,x<<1|1,mid+1,r);
	if (sta==1) add(tree[sta][ls(sta,x)].id,tree[sta][x].id,0),add(tree[sta][rs(sta,x)].id,tree[sta][x].id,0);
	if (sta==0) add(tree[sta][x].id,tree[sta][ls(sta,x)].id,0),add(tree[sta][x].id,tree[sta][rs(sta,x)].id,0);
}void update_down(int v,int x,int l,int r,int tl,int tr,int w){
	if ((l>=tl)&&(r<=tr)) {add(leaf[0][v],tree[0][x].id,w);return ;}
	int mid=(l+r)/2;
	if (mid>=tl) update_down(v,x<<1,l,mid,tl,tr,w);if (mid<tr) update_down(v,x<<1|1,mid+1,r,tl,tr,w);
}void update_up(int v,int x,int l,int r,int tl,int tr,int w){
	if ((l>=tl)&&(r<=tr)) {add(tree[1][x].id,leaf[1][v],w);return ;}
	int mid=(l+r)/2;
	if (mid>=tl) update_up(v,x<<1,l,mid,tl,tr,w);if (mid<tr) update_up(v,x<<1|1,mid+1,r,tl,tr,w);
}
int main() {lim[1]=1000000;
    n=read();Q=read();rt=read();build(0,1,1,n);
	build(1,1,1,n);
    
	for (i=1;i<=n;i++) add(leaf[0][i],leaf[1][i],0),add(leaf[1][i],leaf[0][i],0);
    for (;Q;Q--){
    	opt=read();
    	if (opt==1){v=read();l=read();r=l;w=read();update_down(v,1,1,n,l,r,w);}
    	if (opt==2){v=read();l=read();r=read();w=read();update_down(v,1,1,n,l,r,w);}
    	if (opt==3){v=read();l=read();r=read();w=read();update_up(v,1,1,n,l,r,w);}
		}
	for (i=1;i<=4000000;i++) dis[i]=1e18;
	dis[leaf[0][rt]]=0;q.push(make_pair(0,leaf[0][rt]));
	while (!q.empty()){
	 
		y=q.top().first;x=q.top().second;q.pop();
		for (i=d[x];i;i=b[i])
		{
			//cout<<x<<"-----"<<tree[0][a[i]].l<<" "<<tree[0][a[i]].r<<" "<<a[i]<<endl;
		    if (dis[x]+c[i]<dis[a[i]])
			   {
		    	dis[a[i]]=dis[x]+c[i];
		    	q.push(make_pair(-dis[a[i]],a[i]));
			}
	}
	}
    for (i=1;i<=n;i++)
       if (min(dis[leaf[0][i]],dis[leaf[0][i]])==1e18) printf("-1 ");
    else printf("%lld ",min(dis[leaf[0][i]],dis[leaf[0][i]]));
    puts("");
	return 0;
}