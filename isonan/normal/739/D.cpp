	#include <cstdio>
	#include <vector>
	#include <cstring>
	
	std::vector<int>vec[310][310],old[310][310];
	int n,x[310],y[310],head[1000001],nxt[6000001],b[6000001],v[6000001],k=1,S,T,dis[1000001],ans,p[1000001];
	int cnt,len[310],loop[310],req[310][310],node[310][310];
	int Ans[310];
	void push(int s,int t,int val){
		nxt[++k]=head[s];
		head[s]=k;
		b[k]=t;
		v[k]=val;
	}
	void link(int s,int t,int val){
	//	printf("%d %d %d\n",s,t,val);
		if(t==T)ans+=val;
		push(s,t,val);
		push(t,s,0);
	}
	int q[2000001],h,t;
	bool bfs(){
		for(int i=0;i<=cnt;i++)dis[i]=-1;
		h=t=0;
		q[++t]=S;
		dis[S]=0;
		while(h<t){
			++h;
			for(int i=head[q[h]];i;i=nxt[i])
				if(v[i]&&!~dis[b[i]]){
					dis[b[i]]=dis[q[h]]+1;
					q[++t]=b[i];
					if(b[i]==T)return 1;
				}
		}
		return 0;
	}
	int dfs(int x,int flow){
		if(x==T||!flow)return flow;
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
		if(!used)dis[x]=-1;
		return used;
	}
	bool vis[310]; 
	int get(){
		char ch=getchar();
		while(ch!='?'&&(ch<'0'||ch>'9'))ch=getchar();
		if(ch=='?')return n+1;
		int x=0;
		while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
		return x; 
	}
	int main(){
	//	freopen("in.txt","r",stdin);
		scanf("%d",&n);
		int mx=-1,bmx=-1,Cnt=0;
		for(int i=1;i<=n;i++){
			x[i]=get(),y[i]=get();
	//		printf("%d %d\n",x[i],y[i]);
			old[x[i]][y[i]].push_back(i);
			if(y[i]<=n){
				vis[y[i]]=1,++Cnt;
				if(x[i]<=n)mx=std::max(mx,x[i]);
			}else if(x[i]<=n)bmx=std::max(bmx,x[i]);
		}
		if(!Cnt)for(int i=0;i<=n+1;i++)old[i][1]=old[i][n+1],old[i][n+1].clear(),mx=bmx,bmx=-1;
		int p;
		for(p=1;p<=n;p++){
			for(int i=0;i<=n+1;i++)
				for(int j=0;j<=n+1;j++)
					vec[i][j]=old[i][j];
			for(int j=mx+1;j<=n;j++){
				for(int k=0;k<vec[j][n+1].size();k++)
					vec[j][p].push_back(vec[j][n+1][k]);
				vec[j][n+1].clear();//,printf("%d\n\n\n",j);
			} 
			int cnT=0;
			for(int j=0;j<=n;j++)
				for(int k=0;k<=n;k++)
					cnT+=vec[j][k].size();
	//		printf("%d %d %d\n",p,mx,vec[mx][p].size());
			if(mx>=bmx&&~mx&&vec[mx][p].empty())continue;
			for(int j=1;j<=n;j++)
				if(vec[n+1][j].size()){
					bool empty=1;
					for(int l=0;l<=n;l++)if(vec[l][j].size())empty=0;
	//				printf("%d %d\n",j,empty);
					if(empty)
						vec[0][j].push_back(vec[n+1][j].back()),vec[n+1][j].pop_back();
				}
			memset(head,0,sizeof head);
			memset(nxt,0,sizeof nxt);
			memset(b,0,sizeof b);
			memset(v,0,sizeof v);
			memset(req,0,sizeof req);
			::k=1;
			cnt=0;
			ans=0;
			T=++cnt;
			for(int i=0;i<n;i++)link(S,len[i]=++cnt,vec[i][n+1].size());
			for(int i=1;i<=n;i++)link(S,loop[i]=++cnt,vec[n+1][i].size());
			for(int i=1;i<=n;i++){
				int mx=-1;
				for(int j=0;j<=n;j++)if(vec[j][i].size())mx=j;
				if(!~mx)continue;
				int u=vec[0][i].size();
				if(!u)link(node[0][i]=++cnt,T,req[0][i]=i);
				else if(u%i)link(node[0][i]=++cnt,T,req[0][i]=i-(u%i));
				else node[0][i]=0;
				if(!u||(u%i)){
					link(len[0],node[0][i],0x7f7f7f7f);
					link(loop[i],node[0][i],0x7f7f7f7f);
					if(loop[i]==loop[i-1])return 4;
				}
				for(int j=1;j<=mx;j++){
					link(node[j][i]=++cnt,T,req[j][i]=(vec[j][i].size()==0));
	//				printf("%d %d %d\n",j,i,vec[j][i].size());
					link(len[j],node[j][i],0x7f7f7f7f);
					link(loop[i],node[j][i],0x7f7f7f7f);
				}
				if(ans>n-cnT)break;
			}
			if(ans>n-cnT)continue;
	//		printf("%d\n",p);
	//		printf("%d\n",ans);
			int nowans=0;
			while(bfs()){
				memcpy(::p,head,sizeof ::p);
				nowans+=dfs(S,0x7f7f7f7f);
			}
			for(int i=0;i<n;i++){
				int cnt=0;
				for(int j=head[len[i]];j;j=nxt[j])
					if((j%2==0))cnt+=v[j^1];
				if(vec[i][n+1].size()<cnt)return 2;
			}
			for(int i=1;i<=n;i++){
				int cnt=0;
				for(int j=head[loop[i]];j;j=nxt[j])
					if((j%2==0))cnt+=v[j^1];
				if(vec[n+1][i].size()<cnt)return 2;
			}
			if(ans-nowans<=vec[n+1][n+1].size()){
				ans=-1;
				break;
			}
		}
	//	for(int i=0;i<n;i++)
	//		for(int j=1;j<=n;j++)
	//			if(req[i][j])printf("%d %d %d\n",i,j,req[i][j]);
		if(~ans){
			puts("-1");
			return 0;
		}
		for(int i=0;i<n;i++)
			for(int j=1;j<=n;j++)
				if(req[i][j]){
					for(int k=head[node[i][j]];k;k=nxt[k])
						if((k&1)){
							std::vector<int> &p=(b[k]==len[i])?vec[i][n+1]:vec[n+1][j];
							if(v[k]>p.size()){
								printf("%d %d %d %d %d\n",b[k],i,j,v[k],p.size());
								printf("%d\n",::k);
								return 0;
							}
							for(int l=0;l<v[k];l++)vec[i][j].push_back(p.back()),p.pop_back();
							req[i][j]-=v[k];
						}
					for(int l=0;l<req[i][j];l++)vec[i][j].push_back(vec[n+1][n+1].back()),vec[n+1][n+1].pop_back();
				}
		for(int i=0;i<n;i++){
			std::vector<int> &P=((!i)?vec[0][1]:vec[i][p]);
	//		printf("%d\n",i);
			for(int j=0;j<vec[i][n+1].size();j++)P.push_back(vec[i][n+1][j]);
		}
		for(int i=1;i<=n;i++){
			std::vector<int>&p=vec[1][i];
			for(int j=0;j<vec[n+1][i].size();j++)p.push_back(vec[n+1][i][j]);
		}
		for(int i=0;i<vec[n+1][n+1].size();i++)vec[0][1].push_back(vec[n+1][n+1][i]);
	//	putchar('*');
		for(int i=1;i<=n;i++){
			for(int j=0;j<vec[0][i].size();j++){
				Ans[vec[0][i][j]]=(j%i==0)?vec[0][i][j+i-1]:vec[0][i][j-1];
			}
			for(int j=1;j<n;j++){
	//			printf("%d %d %d %d\n",j,i,vec[j-1][i].size(),vec[j][i].size());
				for(int k=0;k<vec[j][i].size();k++)
					Ans[vec[j][i][k]]=vec[j-1][i].back();
			}
		}
	//	return 0;
		for(int i=1;i<=n;i++)printf("%d ",Ans[i]);
	}