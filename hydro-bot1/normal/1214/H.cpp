// Hydro submission #616cb62660f0aa1f3263e745@1634545298081
#include<iostream>
using namespace std;
struct abawbwpo{
	int v,next;
}_[1000005]; 
int head[1000005],tot=1;
void add(int u,int v){
	_[tot].v=v;
	_[tot].next=head[u];
	head[u]=tot;
	tot++;
}
int dis[1000005];
void dfs0(int asdf,int step){ // 
	dis[asdf]=step;
	int i;
	for(i=head[asdf];i;i=_[i].next){
		if(!dis[_[i].v]){
			dfs0(_[i].v,step+1);
		}
	}
}
int f[1000005],maxlen[1000005];
int dfs1(int asdf,int step){ // 
	dis[asdf]=step;
	int i,Max=0,ykb;
	for(i=head[asdf];i;i=_[i].next){
		if(!f[_[i].v]){
			f[_[i].v]=asdf;
			ykb=dfs1(_[i].v,step+1);
			if(ykb>Max){
				Max=ykb;
			}
		}
	}
	maxlen[asdf]=Max+1;
	return Max+1;
}
int fat[1000005];
void dfs2(int asdf){ // 
	int i;
	for(i=head[asdf];i;i=_[i].next){
		if(!fat[_[i].v]){
			fat[_[i].v]=fat[asdf];
			dfs2(_[i].v);
		}
	}
}
int tkr[1000005];
bool jingen[1000005],zhijing[1000005]; // 
int main(){
	int n,m,i,j,A,B,Max=0,root,leaf,Min=0;
	cin>>n>>m;
	for(i=1;i<n;i++){
		scanf("%d %d",&A,&B);
		add(A,B);
		add(B,A);
	}
	dfs0(1,1);
//	for(i=1;i<=n;i++){
//		cout<<dis[i]<<" ";
//	}
//	cout<<endl;
	for(i=1;i<=n;i++){
		if(dis[i]>Max){
			Max=dis[i];
			root=i;
		}
	}
	f[root]=root;
	dfs1(root,0);
//	for(i=1;i<=n;i++){
//		cout<<dis[i]<<" ";
//	}
//	cout<<endl;
	Max=0;
	for(i=1;i<=n;i++){
		if(dis[i]>Max){
			Max=dis[i];
			leaf=i;
		}
	}
	fat[root]=root;
	for(i=leaf;i!=root;i=f[i]){
		fat[i]=i;
	}
	for(i=leaf;i!=root;i=f[i]){
		dfs2(i);
	}
	dfs2(root);
//	for(i=1;i<=n;i++){
//		cout<<fat[i]<<" ";
//	}
//	cout<<endl;
//	for(i=1;i<=n;i++){
//		cout<<f[i]<<" ";
//	}
//	cout<<endl;
//	cout<<":"<<root<<","<<leaf<<endl; 
	for(i=f[leaf];i!=root;i=f[i]){
		Max=0;
		jingen[i]=(dis[i]<maxlen[i]);
//		cout<<"i="<<i<<",dis="<<dis[i]<<",maxlen="<<maxlen[i]<<endl;
		for(j=head[i];j;j=_[j].next){
//			cout<<"|	v="<<_[j].v<<endl;
			if(fat[_[j].v]!=_[j].v){
				if(dis[i]<maxlen[i]){
					Max=max(Max,dis[i]+maxlen[_[j].v]+2);
//					cout<<"|	,:"<<maxlen[i]<<",:"<<dis[i]+maxlen[_[j].v]+2<<","<<dis[i]<<"+"<<maxlen[_[j].v]<<endl;
				}else{
					Max=max(Max,maxlen[i]+maxlen[_[j].v]+1);
//					cout<<"|	,:"<<dis[i]<<",:"<<maxlen[i]+maxlen[_[j].v]+1<<","<<maxlen[i]<<"+"<<maxlen[_[j].v]<<endl;
				}
			}
		}
		Min=max(Min,Max);
	}
	if(m==0){
		if(n>=1){
			cout<<"No";
		}else{
			cout<<"Yes";
		}
		return 0;
	}
	if(m==1){
		cout<<"Yes"<<endl;
		for(i=1;i<=n;i++){
			cout<<"1 ";
		}
		return 0;
	}
	if(m==2){
		cout<<"Yes"<<endl;
		for(i=1;i<=n;i++){
			cout<<(dis[i]&1)+1<<" ";
		}
		return 0;
	}
	if(m<Min){
		cout<<"No";
		return 0;
	}
	cout<<"Yes"<<endl;
	for(i=1;i<=n;i++){
		if(fat[i]!=i&&jingen[fat[i]]){
//			cout<<"*";
			cout<<(dis[fat[i]]*2-dis[i])%m+1<<" ";
		}else{
			cout<<dis[i]%m+1<<" ";
		}
	}
	return 0;
}
/*
7 3
1 3
2 3
3 4
4 5
5 6
5 7
ans:no

4 3
1 2
1 3
1 4
ans:no

15 6
1 2
2 3
1 4
3 5
5 6
4 7
4 8
6 9
9 10
2 11
5 12
4 13
9 14
4 15
ans:
Yes
3 4 5 2 6 1 1 1 2 3 3 1 1 3 1
*/