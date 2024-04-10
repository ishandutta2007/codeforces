#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7; unordered_map<int,int>c[N]; bool fl;
int t,n,f[N],g[N],w[N],p[N]; vector<int>v[N];
inline int getpos(int u){
	int l=1,r=w[0];
	while(l<=r){
		int d=(l+r)>>1;
		if(w[d]==u) return d;
		if(w[d]<u) l=d+1; else r=d-1;
	}
	return 1919810;
}
inline int read(){
	int num=0; char g=getchar(); while(g<48||57<g) g=getchar();
	while(47<g&&g<58) num=(num<<1)+(num<<3)+g-48,g=getchar(); return num;
}
inline void write(int u){
	if(u>9) write(u/10); putchar(u%10+'0');
}
int main(){
//	freopen("in.txt","r",stdin);
	cin>>t;
	while(t--){
		n=read(); int x; w[0]=0,fl=0;
		for(int i=1;i<=n;i++) v[i].resize(0);
		for(int i=1;i<=n;i++){
			int l; l=read(),v[i].resize(l);
			for(int j=1;j<=l;j++) g[j]=read(),w[++w[0]]=g[j];
			sort(g+1,g+l+1);
			for(int j=1;j<=l;j++) v[i][j-1]=g[j];
		}
		sort(w+1,w+w[0]+1);
		for(int i=1;i<=w[0];i++) c[i].clear();
		for(int i=1;i<=n;i++)
			for(int j=0;j<v[i].size();j++) v[i][j]=getpos(v[i][j]);
		for(int i=1;i<=n;i++){
			if(v[i].size()<=50) continue;
			for(int j=0;j<v[i].size();j++) p[v[i][j]]++;
			for(int k=1;k<=n;k++){
				if(i==k) continue; if(fl) break; int ans=0;
				if(v[k].size()>50&&i>k) continue;
				for(int q=0;q<v[k].size();q++) if(p[v[k][q]]) ans++;
				if(ans>=2){
					write(i),putchar(' '),write(k),putchar('\n'),fl=1;
				}
			}
			for(int j=0;j<v[i].size();j++) p[v[i][j]]--;
		}
		if(fl) continue;
		for(int i=1;i<=n;i++){
			if(v[i].size()>50) continue;
			for(int j=0;j<v[i].size();j++)
				for(int k=j+1;k<v[i].size();k++){
					if(fl) break;
					if(c[v[i][j]].count(v[i][k])){
						write(c[v[i][j]][v[i][k]]),putchar(' '),write(i),putchar('\n');
						fl=1; break;
					}
					c[v[i][j]][v[i][k]]=i;
				}
		}
		if(!fl) puts("-1");
	}
	return 0;
}