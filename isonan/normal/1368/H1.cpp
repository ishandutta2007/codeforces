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
	int cnt[2][100001],S;
	struct info{
		int f[2][2];
		info(){
			for(int i=0;i<2;i++)
				for(int j=0;j<2;j++)
					f[i][j]=10000000;
		}
	}se[800001];
	info merge(info a,info b){
		info c;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				for(int k=0;k<2;k++)
					for(int l=0;l<2;l++)
						c.f[i][l]=std::min(c.f[i][l],a.f[i][j]+b.f[k][l]+(k!=j)*S);
		return c;
	}
	void build(int root,int l,int r){
		if(l==r){
			se[root]=info();
			se[root].f[0][0]=cnt[0][l];
			se[root].f[1][1]=cnt[1][l];
			return;
		}
		build(root<<1,l,(l+r)>>1);
		build(root<<1|1,((l+r)>>1)+1,r);
		se[root]=merge(se[root<<1],se[root<<1|1]);
	}
	void upd(int root,int l,int r,int e,int x){
		if(l==r){
			se[root]=info();
			--se[root].f[x^1][x^1];
			++se[root].f[x][x];
			return;
		}
		if((l+r)>>1>=e)upd(root<<1,l,(l+r)>>1,e,x);
		else upd(root<<1|1,((l+r)>>1)+1,r,e,x);
		se[root]=merge(se[root<<1],se[root<<1|1]);
	}
	int getans(){
		int cnt=0x7f7f7f7f;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				cnt=std::min(cnt,se[1].f[i][j]);
		return cnt;
	} 
}N,M;
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
	N.build(1,1,n);
	M.build(1,1,m);
	int ans=(n+m)<<1;
	for(int i=0;i<=q;i++){
		printf("%d\n",std::min((n+m)<<1,std::min(N.getans(),M.getans())));
		if(i<q){
			char ch=getchar();
			while(ch<'A'||ch>'Z')ch=getchar();
			int p1,p2,p3;
			if(ch=='L')p1=p2=0;
			else if(ch=='R')p1=0,p2=1;
			else if(ch=='U')p1=1,p2=0;
			else p1=p2=1;
			scanf("%d",&p3);
			int now=(map[p1][p2][p3]^=1);
			if(!p1){
				N.upd(1,1,n,p3,now);
				M.upd(1,1,m,(p2==0)?1:m,now);
			}
			else{
				M.upd(1,1,m,p3,now);
				N.upd(1,1,n,(p3==0)?1:n,now);
			}
		}
	}
}