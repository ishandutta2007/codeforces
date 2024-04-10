#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
using namespace std;
const int N=1e7+5,M=755;
int n,tt,ans,d[N],st[M],wz[N],ss;
int s[N][2],fa[N],id[N];
int dy[N*2],vi[N],vs;
vector<int>e[M*2];
bool b[M][M];
char c[N];
bool get(int x){
	if(vi[x]==vs)return 0;
	vi[x]=vs;
	for(int i:e[x])if(!dy[i]||get(dy[i]))return dy[i]=x,dy[x]=i,1;
	return 0;
}
void go(int x){
	vi[x]=vs;
	for(int i:e[x])if(dy[i]&&vi[i]<vs)vi[i]=vs,go(dy[i]);
}
int main(){
	scanf("%d",&n);tt=1;
	s[0][0]=s[0][1]=1;
	fo(i,1,n){
		scanf("\n%s",c+1);
		int len=strlen(c+1),j=1;
		st[i]=ss+1;
		fo(l,1,len){
			c[l]-='a';
			if(!s[j][c[l]])s[j][c[l]]=++tt;
			wz[++ss]=j=s[j][c[l]];
		}
		id[j]=i;
	}st[n+1]=ss+1;
	d[1]=1;
	for(int l=0,r=1,x;x=d[++l],l<=r;)
		fo(i,0,1)if(s[x][i]){
			int y=s[x][i],z=fa[x];
			d[++r]=y;
			for(;!s[z][i];)z=fa[z];
			fa[y]=s[z][i];
			if(!id[y])id[y]=id[fa[y]];
		}
	fo(i,1,n)
		fo(j,st[i],st[i+1]-1)
			b[i][id[wz[j]]]=1,b[i][id[fa[wz[j]]]]=1;
	fo(k,1,n)fo(i,1,n)fo(j,1,n)
		b[i][j]|=b[i][k]&b[k][j];
	fo(i,1,n)fo(j,1,n)
		if(i!=j&&b[i][j])e[i].push_back(j+n);
	fo(i,1,n)if(!dy[i])++vs,get(i);
	++vs;
	fo(i,1,n)if(!dy[i])go(i);
	fo(i,1,n)if(vi[i]==vs&&vi[i+n]<vs)++ans;
	cout<<ans<<endl;
	fo(i,1,n)if(vi[i]==vs&&vi[i+n]<vs)cout<<i<<" ";
}