#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
const int N=1e6;
const int maxn=1e6+10;
const int mod=1e9+7;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f;
}
struct node{
	int id,x;
}a[maxn];
bool operator<(node a,node b){
	if(a.x==b.x)return a.id<b.id;
	return a.x<b.x;
}
set<node>S;
set<node>::iterator it; 
int n,A,p[maxn],vis[maxn],c[maxn];
int main(){
	n=read(),A=read();
	for(int i=1;i<=n;i++)
		p[i]=read();
	for(int i=1;i<=N;i++)
		S.insert((node){i,0});
//	printf("%d\n",S.size());
	for(int i=1;i<=n;i++){
		if(vis[p[i]])continue;
//		printf("%d %d\n",i,p[i]);
		it=S.lower_bound((node){p[i],c[p[i]]});
		S.erase(*it);++c[p[i]];
		S.insert((node){p[i],c[p[i]]});
//		printf("%d\n",S.size());
		if(p[i]==A){
//			puts("inside");
			for(it=S.begin();it!=S.end();){
				node tmp=*it;
				if(tmp.x>=c[A])break;
				it++;S.erase(tmp);
				vis[tmp.id]=1;
//				printf("del %d\n",tmp.id);
			}
		}
	}
	int flag=-1;
	for(int i=1;i<=N;i++)
		if(!vis[i]&&(i!=A)){flag=i;break;}
	printf("%d\n",flag);
    return 0;
}