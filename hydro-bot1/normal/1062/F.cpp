// Hydro submission #62505e8d35d3f88a89debc41@1649434253813
#include<bits/stdc++.h>
using namespace std;
#define maxn 300009
int n,m,d[maxn],rd[maxn],ans=0,cnt[maxn];
bool awa[maxn];
queue<int > qaq;
vector<int > to[maxn],rto[maxn]; 
inline int read(){
	int sum=0,fh=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')fh=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		sum*=10;
		sum+=c-'0';
		c=getchar();
	}
	return sum*fh;
}
int main(){
//    freopen(".in","r",stdin);
//    freopen(".out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		to[u].push_back(v);d[v]++;
		rto[v].push_back(u);rd[u]++;
	}
	for(int i=1;i<=n;i++)awa[i]=true;
	for(int i=1;i<=n;i++)if(d[i]==0)qaq.push(i);
	int tot=0;
	while(!qaq.empty()){
		tot++;
		int u=qaq.front();qaq.pop();
		if(awa[u]){
		if(qaq.size()<=1){
			if(qaq.size()==1){
				int ru=qaq.front(),sn=to[ru].size();
				for(int i=0;i<sn;i++){
					int v=to[ru][i];
					if(d[v]==1)awa[u]=false;
				}
				sn=to[u].size();
				for(int i=0;i<sn;i++){
					int v=to[u][i];
					if(d[v]==1)awa[ru]=false;
				}
				cnt[u]+=n-tot-1;
			}
			else cnt[u]+=n-tot;
		}
		else{
			awa[u]=false;
			queue<int > qwq; 
			while(!qaq.empty()){
				int nw=qaq.front();qaq.pop();awa[nw]=false;qwq.push(nw);
			}
			while(!qwq.empty()){
				int nw=qwq.front();qwq.pop();qaq.push(nw);
			}
		}
		}
		int sn=to[u].size();
		for(int i=0;i<sn;i++){
			int v=to[u][i];
			d[v]--;
			if(d[v]==0)qaq.push(v);
		}
	}
	tot=0;
	for(int i=1;i<=n;i++)if(rd[i]==0)qaq.push(i);
	while(!qaq.empty()){
		tot++; 
		int u=qaq.front();qaq.pop();
		if(awa[u]){
		if(qaq.size()<=1){
			if(qaq.size()==1){
				int ru=qaq.front(),sn=rto[ru].size();
				for(int i=0;i<sn;i++){
					int v=rto[ru][i];
					if(rd[v]==1)awa[u]=false;
				}
				sn=rto[u].size();
				for(int i=0;i<sn;i++){
					int v=rto[u][i];
					if(rd[v]==1)awa[ru]=false;
				}
				cnt[u]+=n-tot-1;
			}
			else cnt[u]+=n-tot;
		}
		else{
			awa[u]=false;
			queue<int > qwq; 
			while(!qaq.empty()){
				int nw=qaq.front();qaq.pop();awa[nw]=false;qwq.push(nw);
			}
			while(!qwq.empty()){
				int nw=qwq.front();qwq.pop();qaq.push(nw);
			}
		}
		}
		int sn=rto[u].size();
		for(int i=0;i<sn;i++){
			int v=rto[u][i];
			rd[v]--;
			if(rd[v]==0)qaq.push(v);
		}
	}
	for(int i=1;i<=n;i++){
		if(cnt[i]>=n-2)ans+=awa[i];
//		cout<<i<<" "<<awa[i]<<endl;
	}
	cout<<ans;
//	  fclose(stdin);
//    fclose(stdout);
	return 0;
}