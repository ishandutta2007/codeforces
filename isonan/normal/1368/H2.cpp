#include <cstdio>
#include <algorithm>

int n,m,q,map[2][2][100001],f[100001][2];
char Getchar(){
	char ch=getchar();
	putchar(ch);putchar('\n');
	return ch;
}
int read(){
	char ch=getchar();
	while(ch!='R'&&ch!='B')ch=getchar();
	return (ch=='B');
}
struct solve{
	int cnt[2][100001],S,sum[800001];
	bool lazy[800001][2];
	struct info{
		int f[2][2];
		info(){
			for(int i=0;i<2;i++)
				for(int j=0;j<2;j++)
					f[i][j]=10000000;
		}
	}se[800001][2][2];
	info merge(info a,info b){
		info c;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				for(int k=0;k<2;k++)
					for(int l=0;l<2;l++)
						c.f[i][l]=std::min(c.f[i][l],a.f[i][j]+b.f[k][l]+(k!=j)*S);
		return c;
	}
	void pushdown(int x,int ind){
		if(ind){
			for(int i=0;i<2;i++)
				std::swap(se[x][i][ind],se[x][i][ind^1]);
		}
		else{
			for(int i=0;i<2;i++)
				std::swap(se[x][ind][i],se[x][ind^1][i]);
		}
		lazy[x][ind]^=1;
	}
	void spread(int root){
		for(int i=0;i<2;i++){
			if(lazy[root][i])pushdown(root<<1,i),pushdown(root<<1|1,i);
			lazy[root][i]=0;
		}
	}
	void pushup(int x){
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				se[x][i][j]=merge(se[x<<1][i][j],se[x<<1|1][i][j]);
	}
	void build(int root,int l,int r,int *a,int *b){
		if(l==r){
			for(int i=0;i<2;i++)
				for(int j=0;j<2;j++)
					for(int k=0;k<2;k++){
						se[root][i][j].f[k][k]=cnt[k][l];
						if(i)se[root][i][j].f[k][k]+=(b[l]==k)?-1:1;
						if(j)se[root][i][j].f[k][k]+=(a[l]==k)?-1:1;
					}
			return;
		}
		build(root<<1,l,(l+r)>>1,a,b);
		build(root<<1|1,((l+r)>>1)+1,r,a,b);	
		pushup(root);
	}
	int getans(){
		int cnt=0x7f7f7f7f;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				cnt=std::min(cnt,se[1][0][0].f[i][j]);
		return cnt;
	}
	void update(int root,int l,int r,int el,int er,int ind){
		if(el>r||er<l)return;
		if(el<=l&&er>=r){
			pushdown(root,ind);
			return;
		}
		spread(root);
		update(root<<1,l,(l+r)>>1,el,er,ind);
		update(root<<1|1,((l+r)>>1)+1,r,el,er,ind);
		pushup(root);
	}
	void upd(int root,int l,int r,int e,int y){
		spread(root);
		if(l==r){
			for(int i=0;i<2;i++)
				for(int j=0;j<2;j++)
					se[root][i][j].f[0][0]-=y,se[root][i][j].f[1][1]+=y;
			return;
		}
		if((l+r)>>1>=e)upd(root<<1,l,(l+r)>>1,e,y);
		else upd(root<<1|1,((l+r)>>1)+1,r,e,y);
		pushup(root);
	}
}N,M;
struct segtree{
	int se[800001],sz[800001];
	bool lazy[800001];
	void pushdown(int x){
		se[x]=sz[x]-se[x];
		lazy[x]^=1;
	}
	void spread(int x){
		if(lazy[x])pushdown(x<<1),pushdown(x<<1|1);
		lazy[x]=0;
	}
	void pushup(int x){
		se[x]=se[x<<1]+se[x<<1|1];
	}
	void build(int root,int l,int r,int *a){
		if(l==r){
			se[root]=a[l];
			sz[root]=1;
			return;
		}
		build(root<<1,l,(l+r)>>1,a);
		build(root<<1|1,((l+r)>>1)+1,r,a);
		sz[root]=sz[root<<1]+sz[root<<1|1];
		pushup(root);
	}
	int update(int root,int l,int r,int el,int er){
		if(el>r||er<l)return 0;
		if(el<=l&&er>=r){
			pushdown(root);
			return se[root];
		}
		spread(root);
		int cnt=0;
		cnt+=update(root<<1,l,(l+r)>>1,el,er);
		cnt+=update(root<<1|1,((l+r)>>1)+1,r,el,er);
		pushup(root);
		return cnt;
	}
}se[2][2];
int main(){
	scanf("%d%d%d",&n,&m,&q);
	N.S=m;
	M.S=n;
	for(int j=0;j<2;j++)
		for(int i=1;i<=n;i++){
			map[0][j][i]=read();
			++N.cnt[map[0][j][i]][i];
			++M.cnt[map[0][j][i]][(j==0)?1:m];
		}
	for(int j=0;j<2;j++)
		for(int i=1;i<=m;i++){
			map[1][j][i]=read();
			++M.cnt[map[1][j][i]][i];
			++N.cnt[map[1][j][i]][(j==0)?1:n];
		}
	N.build(1,1,n,map[0][1],map[0][0]);
	M.build(1,1,m,map[1][1],map[1][0]);
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			se[i][j].build(1,1,i?m:n,map[i][j]);
//	int ans=(n+m)<<1;
	for(int i=0;i<=q;i++){
		printf("%d\n",std::min((n+m)<<1,std::min(N.getans(),M.getans())));
		if(i<q){
			char ch=getchar();
			while(ch<'A'||ch>'Z')ch=getchar();
			int p1,p2,L,R;
			if(ch=='L')p1=p2=0;
			else if(ch=='R')p1=0,p2=1;
			else if(ch=='U')p1=1,p2=0;
			else p1=p2=1;
			scanf("%d%d",&L,&R);
			int u=se[p1][p2].update(1,1,p1?m:n,L,R);
			u=(u<<1)-(R-L+1);
			if(!p1){
				N.update(1,1,n,L,R,p2);
				M.upd(1,1,m,(p2==0)?1:m,u);
			}
			else{
				M.update(1,1,m,L,R,p2);
				N.upd(1,1,n,(p2==0)?1:n,u);
			}
		}
	}
}