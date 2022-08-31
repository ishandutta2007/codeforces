#include <cstring>
#include <cstdio>
#include <queue>

std::queue<int>q;
int head[300001],nxt[300001],b[300001],k,n,m,con[300001][2],d[300001],ans[300001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	++d[t];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d",&con[i][0],&con[i][1]);
	for(int i=1;i<=m;i++)push(con[i][0],con[i][1]);
	int now=n;
	for(int i=1;i<=n;i++)if(!d[i])--now,q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		if(!q.size())ans[x]+=now;
		else if(q.size()==1){
			bool cando=1;
			for(int i=head[q.front()];i;i=nxt[i])
				cando&=(d[b[i]]>1);
			ans[x]+=now*cando;
		}
		for(int i=head[x];i;i=nxt[i])
			if(!--d[b[i]])--now,q.push(b[i]);
	}
	memset(head,0,sizeof head);
	k=0;
	for(int i=1;i<=m;i++)push(con[i][1],con[i][0]);
	now=n;
	for(int i=1;i<=n;i++)if(!d[i])--now,q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		if(!q.size())ans[x]+=now;
		else if(q.size()==1){
			bool cando=1;
			for(int i=head[q.front()];i;i=nxt[i])
				cando&=(d[b[i]]>1);
			ans[x]+=now*cando;
		}
		for(int i=head[x];i;i=nxt[i])
			if(!--d[b[i]])--now,q.push(b[i]);
	}
	int fin=0;
	for(int i=1;i<=n;i++)fin+=(ans[i]>=n-2);
	printf("%d\n",fin); 
}