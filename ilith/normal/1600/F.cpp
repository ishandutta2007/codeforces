#include <bits/stdc++.h>
using namespace std;
int n,m;
#define ll long long
inline int read(){
	int x;
	scanf("%d",&x);
	return x;	
}
const int N=100005;
struct node{
	int to,nxt;
}e[N<<1];
int head[N],tot;
inline void add(int u,int v){
	e[++tot].to=v,e[tot].nxt=head[u],head[u]=tot;
	e[++tot].to=u,e[tot].nxt=head[v],head[v]=tot;
}
int a[6];
inline bool check(){
	bool f1=1,f2=1;
	int cnt[5];
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=5;++i){
		for(int j=head[a[i]];j;j=e[j].nxt){
			int v=e[j].to;
			for(int k=1;k<=5;++k){
				if(v==a[k]) f1=0,++cnt[i];
			}
		}	
	}
	for(int i=1;i<=5;++i){
		if(cnt[i]<4) f2=0;
	}
	return f1||f2;
}
map<ll,int> ma;
int main(){
	srand(time(0));
	n=read(),m=read();
	for(int i=1,u,v;i<=m;++i){
		u=read(),v=read();
		add(u,v);
	}
	int maxx=min(n,60);
	int b[100];
	for(int i=1;i<=maxx;++i) b[i]=0;
	for(int i=1;i<=5;++i) b[maxx-i+1]=1;
	do{
		int kkk=0;
		for(int i=1;i<=maxx;++i){
			if(b[i]==1) a[++kkk]=i;//cout<<a[kkk]<<" ";
		}
	//	cout<<endl;
		if(check()){
			for(int i=1;i<=5;++i){
				printf("%d ",a[i]);	
			}
			cout<<endl;
			return 0;
		}
	}while(next_permutation(b+1,b+1+maxx));
	puts("-1");
	return 0;	
}