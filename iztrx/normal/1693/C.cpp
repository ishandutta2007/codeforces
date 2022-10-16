#include<bits/stdc++.h>
using namespace std;
#define N 1000005
struct node{
	int x,d;
	bool operator <(node aa)const{
		return d>aa.d;
	}
}tmp,ff;
node mak(int x,int d){
	tmp.x=x;tmp.d=d;return tmp;
}
priority_queue<node>pq;
vector<int>son[N];
int n,m,i,x,y,in[N],dis[N],qwq[N],T;
int main(){
	cin>>n>>m;
	for(i=1;i<=m;++i){
		cin>>x>>y;
		son[y].push_back(x); 
		++in[x];
	}
	for(i=1;i<=n;++i)dis[i]=1000000000;
	pq.push(mak(n,0));dis[n]=0;in[n]=0;
	while(pq.size()){
		ff=pq.top();pq.pop();
		if(dis[ff.x]+in[ff.x]==ff.d&&qwq[ff.x]==0){
			qwq[ff.x]=1;
			for(i=0;i<son[ff.x].size();++i){
				T=son[ff.x][i];
				if(qwq[T])continue;
				--in[T];
				if(dis[T]>ff.d) dis[T]=ff.d+1;
				else ++dis[T];
				pq.push(mak(T,dis[T]+in[T]));
			}
		}
	}
	cout<<dis[1]+in[1]<<"\n";
}