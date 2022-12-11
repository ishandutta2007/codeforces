#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
struct bian{
	int next,point,w;
}b[610000];
int father[210000][18],p[210000],len,n,m,s,size[210000],d[210000],pd[210000],a[210000];
long long D[210000];
queue<int>Q;
void ade(int k1,int k2,int k3){
	b[++len]=(bian){p[k1],k2,k3}; p[k1]=len;
}
void add(int k1,int k2,int k3){
	ade(k1,k2,k3); ade(k2,k1,k3);
}
int compare(int k1,int k2){
	return D[k1]<D[k2];
}
void dfs(int k1,int k2){
	size[k1]=1;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2){
			dfs(j,k1); size[k1]+=size[j];
		}
	}
}
int getlca(int k1,int k2){
	if (d[k1]<d[k2]) swap(k1,k2);
	for (int i=17;i>=0;i--) if (d[k1]-d[k2]>=(1<<i)) k1=father[k1][i];
	if (k1==k2) return k1;
	for (int i=17;i>=0;i--)
		if (father[k1][i]!=father[k2][i]){
			k1=father[k1][i]; k2=father[k2][i];
		}
	return father[k1][0];
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	for (int i=1;i<=m;i++){
		int k1,k2,k3; scanf("%d%d%d",&k1,&k2,&k3); add(k1,k2,k3);
	}
	memset(D,0x3f,sizeof D);
	D[s]=0; Q.push(s); pd[s]=1;
	while (!Q.empty()){
		int k=Q.front();
		for (int i=p[k];i;i=b[i].next){
			int j=b[i].point;
			if (D[j]>D[k]+b[i].w){
				D[j]=D[k]+b[i].w;
				if (pd[j]==0){
					Q.push(j); pd[j]=1;
				}
			}
		}
		Q.pop(); pd[k]=0;
	}
	d[s]=1;
	for (int i=1;i<=n;i++) a[i]=i,father[i][0]=0;
	sort(a+1,a+n+1,compare); father[s][0]=0;
//	for (int i=1;i<=n;i++) cout<<D[i]<<" "; cout<<endl;
	for (int now=1;now<=n&&D[a[now]]<=1e17;now++){
		int k=a[now];
		for (int i=1;i<=17;i++) father[k][i]=father[father[k][i-1]][i-1];
		d[k]=d[father[k][0]]+1;
		for (int i=p[k];i;i=b[i].next){
			int j=b[i].point;
			if (D[j]==D[k]+b[i].w){
			//	cout<<"add "<<k<<" "<<j<<endl;
				if (father[j][0]==0){
					father[j][0]=k;
				} else father[j][0]=getlca(father[j][0],k);
			}
		}
	}
//	cout<<"asd"<<endl;
//	for (int i=1;i<=n;i++) cout<<father[i][0]<<" "; cout<<endl;
	len=0; memset(p,0x00,sizeof p);
	for (int i=1;i<=n;i++) if (father[i][0]) add(father[i][0],i,1);
	dfs(s,0);
	int ans=0;
	for (int i=1;i<=n;i++) if (i!=s) ans=max(ans,size[i]);
	cout<<ans<<endl;
	return 0;
}