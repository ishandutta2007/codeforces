#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

int i,j,k,del,no,n,m;
bool vis[100500],vis2[100500],no1[100500],tmp[100500];
vector<int> v[100500];

void dfs3(int x){
	if(no||x==del)return;
	
	if(vis[x]){
		no=x;tmp[x]=1;return;
	}
	if(vis2[x])return;
	vis2[x]=1;
	vis[x]=1;
	for(auto i:v[x]){
		
		dfs3(i);
		if(no){
			if(no!=-1){
				tmp[x]=1;
				if(no==x)no=-1;
			}
			break;
		}
	}
	vis[x]=0;
}

bool chk(int x){
	int i,j,k;
	no=0;
	for(i=1;i<=n;i++){
		if(vis2[i]||i==del)continue;
		no=0;
		dfs3(i);
		if(no)break;
	}
	if(!no)return 1;
	for(i=1;i<=n;i++){
		if(!tmp[i])no1[i]=1;
	}
	memset(tmp,0,sizeof(tmp));
	memset(vis2,0,sizeof(vis2));
	memset(vis,0,sizeof(vis));
	return 0;
}

#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int main(){
	srand(chrono::steady_clock::now().time_since_epoch().count()+1);
	n=read();m=read();
	for(i=1;i<=m;i++){
		j=read();k=read();
		v[j].push_back(k);
	}
	for(i=1;i<=n;i++){
		if(no1[i]){
			continue;
		}
		del=i;
		if(chk(i)){
			cout<<i;return 0;
		}
		if(1.0*clock()/CLOCKS_PER_SEC>0.8)break;
	}
	cout<<-1;
}