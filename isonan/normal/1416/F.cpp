#include <cstdio>
#include <cstring>
#include <algorithm>

int _t,n,m,map[100001],head[100010],nxt[1000001],b[1000001],v[1000001],k,S,T,SS,TT;
int dis[100010],p[100010],q[100010],h,t;
int ans[100001],val[100001];
void push(int s,int t,int val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
void link(int s,int t,int val){
//	printf("%d %d %d\n",s,t,val);
	push(s,t,val);
	push(t,s,0);
}
int hash(int i,int j){
	return (i-1)*m+j;
}
bool bfs(){
	memset(dis,0,sizeof dis);
	h=t=0;
	q[++t]=SS;
	dis[SS]=1;
	while(h<t){
		++h;
		for(int i=head[q[h]];i;i=nxt[i])
			if(v[i]&&!dis[b[i]]){
				dis[b[i]]=dis[q[h]]+1;
				q[++t]=b[i];
				if(b[i]==TT)return 1;
			}
	}
	return 0;
}
int dfs(int x,int flow){
	if(!flow||x==TT)return flow;
	int used=0;
	for(int i=p[x];i;i=nxt[i])
		if(v[i]&&dis[b[i]]==dis[x]+1){
			int w=dfs(b[i],std::min(flow-used,v[i]));
			v[i]-=w;
			v[i^1]+=w;
			if(w)p[x]=i;
			used+=w;
			if(used==flow)return used;
		}
	if(!used)dis[x]=0;
	return used;
}
int main(){
	scanf("%d",&_t);
	for(int fd=1;fd<=_t;fd++){
		k=1;
		memset(head,0,sizeof head);
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&map[hash(i,j)]);
		T=n*m+1;
		int fS=0,fT=0;
		SS=T+1;
		TT=T+2;
		bool Ans=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				bool cando=0;
				cando|=(i>1&&map[hash(i-1,j)]<map[hash(i,j)]);
				cando|=(j>1&&map[hash(i,j-1)]<map[hash(i,j)]);
				cando|=(i<n&&map[hash(i+1,j)]<map[hash(i,j)]);
				cando|=(j<m&&map[hash(i,j+1)]<map[hash(i,j)]);
				if(!cando&&map[hash(i,j)]==1)Ans=0;
				if((i+j)&1){
					if(cando)link(S,hash(i,j),1);
					else link(SS,hash(i,j),1),++fS;
					if(i>1&&map[hash(i-1,j)]==map[hash(i,j)])link(hash(i,j),hash(i-1,j),1);
					if(j>1&&map[hash(i,j-1)]==map[hash(i,j)])link(hash(i,j),hash(i,j-1),1);
					if(i<n&&map[hash(i+1,j)]==map[hash(i,j)])link(hash(i,j),hash(i+1,j),1);
					if(j<m&&map[hash(i,j+1)]==map[hash(i,j)])link(hash(i,j),hash(i,j+1),1);
				}
				else{
					if(cando)link(hash(i,j),T,1);
					else link(hash(i,j),TT,1),++fT;
				}
			}
		link(S,TT,fS);
		link(SS,T,fT);
		link(T,S,0x7f7f7f7f);
		while(bfs()){
			memcpy(p,head,sizeof p);
			dfs(SS,0x7f7f7f7f);
		}
		memset(ans,-1,sizeof ans);
		//0 L 1 R 2 U 3 D
		for(int i=2;i<=k;i+=2){
			if(!v[i]){
				int s=b[i],t=b[i^1];
				if(s>=1&&s<=n*m&&t>=1&&t<=n*m){
					int x1=(s-1)/m+1,y1=(s-1)%m+1,x2=(t-1)/m+1,y2=(t-1)%m+1;
//					printf("%d %d %d %d %d %d\n",s,x1,y1,t,x2,y2);
					if(x1==x2)ans[s]=(y1<y2),ans[t]=(y1>y2);
					else ans[s]=(x1<x2)+2,ans[t]=(x1>x2)+2;
					val[s]=1,val[t]=map[t]-1;
				}
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(!~ans[hash(i,j)]){
					bool cando=0;
					cando|=(i>1&&map[hash(i-1,j)]<map[hash(i,j)]);
					cando|=(j>1&&map[hash(i,j-1)]<map[hash(i,j)]);
					cando|=(i<n&&map[hash(i+1,j)]<map[hash(i,j)]);
					cando|=(j<m&&map[hash(i,j+1)]<map[hash(i,j)]);
					if(!cando)Ans=0;
				}
		if(!Ans)puts("NO");
		else{
			puts("YES");
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++){
					char ch='0';
					switch(ans[hash(i,j)]){
						case 0:{ch='L';break;}
						case 1:{ch='R';break;}
						case 2:{ch='U';break;}
						case 3:{ch='D';break;}
						case -1:{ch='0';break;}
					}
//					printf("%d %c\n",ans[hash(i,j)],ch);
					if(ch=='0'){
						if(i>1&&map[hash(i-1,j)]<map[hash(i,j)])ch='U',val[hash(i,j)]=map[hash(i,j)]-map[hash(i-1,j)];
						if(j>1&&map[hash(i,j-1)]<map[hash(i,j)])ch='L',val[hash(i,j)]=map[hash(i,j)]-map[hash(i,j-1)];
						if(i<n&&map[hash(i+1,j)]<map[hash(i,j)])ch='D',val[hash(i,j)]=map[hash(i,j)]-map[hash(i+1,j)];
						if(j<m&&map[hash(i,j+1)]<map[hash(i,j)])ch='R',val[hash(i,j)]=map[hash(i,j)]-map[hash(i,j+1)];
					}
					ans[hash(i,j)]=ch;
				}
			for(int i=1;i<=n;i++,putchar('\n'))
				for(int j=1;j<=m;j++)
					printf("%d ",val[hash(i,j)]);
			for(int i=1;i<=n;i++,putchar('\n'))
				for(int j=1;j<=m;j++)
					putchar(ans[hash(i,j)]),putchar(' ');
		}
	}
}