#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>
using namespace std;
const int N=1e6+10;
int w[N],ne[N],la[N],t;
int le[N],ri[N],n,m;
typedef pair<int,int> pi;
map<pi,int> p;
void del(int x){
	le[ri[x]]=le[x];
	ri[le[x]]=ri[x];
}
int d[N],vis[N];
int main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		p[make_pair(x,y)]=p[make_pair(y,x)]=1;
	}
	for (int i=1;i<=n;i++)p[make_pair(i,i)]=1;
	for (int i=1;i<=n;i++)ri[i]=i+1,le[i]=i-1;
	ri[0]=1;
	int l=0,r=0,ans=0;
	for (int i=1;i<=n;i++){
		if (!vis[i]){
			d[++r]=i;
			ans++;
			while (l<r){
				int x=d[++l];
				vis[x]=1;
				for (int i=ri[0];i!=n+1;i=ri[i]){
					if (p[make_pair(x,i)])continue;
					d[++r]=i;
					del(i);
				}
			}
		}
	}
	cout<<ans-1<<endl;
}