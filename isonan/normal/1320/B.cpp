#include <cstdio>

int n,m,head[200001],nxt[400001],b[400001],k,q[200001],h,t,dis1[200001],disn[200001],p[200001],l;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void getdis(int *dis,int s){
	for(int i=1;i<=n;i++)dis[i]=-1;
	dis[s]=0;
	h=t=0;
	q[++t]=s;
	while(h<t){
		++h;
		for(int i=head[q[h]];i;i=nxt[i])
			if((i&1)==0&&!~dis[b[i]]){
				dis[b[i]]=dis[q[h]]+1;
				q[++t]=b[i];
			}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u);
	scanf("%d",&l);
	for(int i=1;i<=l;i++)scanf("%d",p+i);
	getdis(disn,p[l]);
	int ans1=0,ans2=0;
	for(int i=1;i<l;i++){
		if(disn[p[i+1]]+1!=disn[p[i]])++ans1;
//		printf("%d %d %d %d %d\n",p[i],p[i+1],dis1[p[i]],disn[p[i+1]],disn[p[i]]);
		bool cando=0;
		for(int j=head[p[i]];j;j=nxt[j])
			if((j&1)==1&&b[j]!=p[i+1]){
				if(disn[b[j]]+1==disn[p[i]]){
					cando=1;
					break;
				}
			}
		if(cando)++ans2;
	}
	printf("%d %d\n",ans1,ans2);
}