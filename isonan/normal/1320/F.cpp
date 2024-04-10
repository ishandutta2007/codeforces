#include <cstdio>

int merge(int a,int b){
	if(a==-2)return b;
	if(b==-2)return a;
	if(!a||!b)return 0;
	if(a==b)return a;
	return -1;
}
struct dat{
	int see[2][200001];
	int pre[200001],nxt[200001];
	int get(int x,int y){
		int p=-2;
		if(!nxt[x])p=merge(p,see[1][y]);
		if(!pre[x])p=merge(p,see[0][y]);
		return p;
	}
	void del(int x){nxt[pre[x]]=nxt[x],pre[nxt[x]]=pre[x];}
	void con(int x,int y){nxt[x]=y,pre[y]=x;}
}a,b,c;
int n,m,k,h,t;
bool del[200001],good[3][200001];
int ans[200001];
struct cor{
	int x,y,z;
	int hash(){return (x-1)*m*k+(y-1)*k+z;}
	int hash_x(){return (y-1)*k+z;}
	int hash_y(){return (x-1)*k+z;}
	int hash_z(){return (x-1)*m+y;}
}q[200001];
void check(int hsh){
	if(del[hsh]||!hsh)return;
//	printf("check %d\n",hsh);
	int z=(hsh%k==0)?k:(hsh%k);
	(hsh-=z)/=k;
	int y=(hsh%m)+1;
	(hsh-=y-1)/=m;
	int x=hsh+1;
	cor now=(cor){x,y,z};
//	printf("%d %d %d %d\n",x,y,z,now.hash());
	int p=-2;
	p=merge(p,a.get(now.hash(),now.hash_x()));
	p=merge(p,b.get(now.hash(),now.hash_y()));
	p=merge(p,c.get(now.hash(),now.hash_z()));
	if(p==-1||p==0){
		del[now.hash()]=1;
		q[++t]=now;
		a.del(now.hash());
		b.del(now.hash());
		c.del(now.hash()); 
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=k;j++)
			scanf("%d",&a.see[0][(cor){0,i,j}.hash_x()]);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=k;j++)
			scanf("%d",&a.see[1][(cor){n+1,i,j}.hash_x()]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++)
			scanf("%d",&b.see[0][(cor){i,0,j}.hash_y()]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++)
			scanf("%d",&b.see[1][(cor){i,m+1,j}.hash_y()]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&c.see[0][(cor){i,j,0}.hash_z()]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&c.see[1][(cor){i,j,k+1}.hash_z()]);
	for(int x=1;x<=n;x++)
		for(int y=1;y<=m;y++)
			for(int z=1;z<=k;z++){
				if(x>1)a.con((cor){x-1,y,z}.hash(),(cor){x,y,z}.hash());
				if(y>1)b.con((cor){x,y-1,z}.hash(),(cor){x,y,z}.hash());
				if(z>1)c.con((cor){x,y,z-1}.hash(),(cor){x,y,z}.hash());
			}
	for(int x=1;x<=n;x++)
		for(int y=1;y<=m;y++)
			for(int z=1;z<=k;z++)
				check((cor){x,y,z}.hash());
	while(h<t){
		int hsh=q[++h].hash();
//		printf("%d\n",hsh);
		check(a.pre[hsh]);
		check(a.nxt[hsh]);
		check(b.pre[hsh]);
		check(b.nxt[hsh]);
		check(c.pre[hsh]);
		check(c.nxt[hsh]);
	}
	for(int x=1;x<=n;x++)
		for(int y=1;y<=m;y++)
			for(int z=1;z<=k;z++){
				cor now=(cor){x,y,z};
				if(!del[now.hash()]){
					good[0][now.hash_x()]=1;
					good[1][now.hash_y()]=1;
					good[2][now.hash_z()]=1;
				}
			}
	for(int x=1;x<=n;x++)
		for(int y=1;y<=m;y++)
			for(int z=1;z<=k;z++){
				cor now=(cor){x,y,z};
				if((a.see[0][now.hash_x()]||a.see[1][now.hash_x()])&&!good[0][now.hash_x()]){puts("-1");return 0;}
				if((b.see[0][now.hash_y()]||b.see[1][now.hash_y()])&&!good[1][now.hash_y()]){puts("-1");return 0;}
				if((c.see[0][now.hash_z()]||c.see[1][now.hash_z()])&&!good[2][now.hash_z()]){puts("-1");return 0;}
			}
	for(int x=1;x<=n;x++,putchar('\n'))
		for(int y=1;y<=m;y++,putchar('\n'))
			for(int z=1;z<=k;z++){
				cor now=(cor){x,y,z};
//				if(del[now.hash()])continue;
				int p=-2;
				p=merge(p,a.get(now.hash(),now.hash_x()));
				p=merge(p,b.get(now.hash(),now.hash_y()));
				p=merge(p,c.get(now.hash(),now.hash_z()));
				if(p==-2||del[now.hash()])p=0;
				printf("%d ",p);
			}
}