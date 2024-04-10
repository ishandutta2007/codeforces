//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=1e6+5;
char s[maxn];
string st[maxn];
int pos[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
vec e[maxn];
int tot,t[maxn][26],fail[maxn],up[maxn],dep[maxn];
queue<int> q;
void init(){
	for(int i=0;i<26;i++)if(t[0][i])q.push(t[0][i]);
	while(q.size()){
		int k=q.front();
		q.pop();
		for(int i=0;i<26;i++){
			int tmp=t[k][i];
			if(tmp)fail[tmp]=t[fail[k]][i],q.push(tmp);
			else t[k][i]=t[fail[k]][i];
		}
	}
	return ;
}
int dfsnum,dfn[maxn],siz[maxn];
void dfs(int x){
	dfn[x]=++dfsnum;siz[x]=1;
	for(auto y:e[x]){
		if(!up[y])up[y]=up[x];
		dfs(y);
		siz[x]+=siz[y];
	}
	return ;
}
int lim,lowbit[maxn],sum[maxn];
void update(int x,int v){while(x<=lim)sum[x]+=v,x+=lowbit[x];return ;}
int query(int x){int res=0;while(x)res+=sum[x],x-=lowbit[x];return res;}
vector<pii> S;
int F[maxn];
int main(){
    int n;
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%s",s),st[i]=s;
		int k=0,len=strlen(s);
		for(int j=0;j<len;j++){
			int c=s[j]-'a';
			if(!t[k][c])t[k][c]=++tot;
			k=t[k][c];dep[k]=j+1;
		}
		up[k]=i,pos[i]=k;
	}
	init();
	for(int i=1;i<=tot;i++)e[fail[i]].eb(i);
	dfs(0);lim=dfsnum;
	for(int i=1;i<=lim;i++)lowbit[i]=i&-i;
	int res=0;
	for(int i=1;i<=n;i++){
		int k=0,len=st[i].size();
		S.clear();
		for(int j=0;j<len;j++){
			int c=st[i][j]-'a';
			k=t[k][c];
			update(dfn[k],1);
			if(j==len-1)k=fail[k];
			if(up[k])S.eb(pii(pos[up[k]],j));
		}
		for(auto p:S)F[p.fi]=query(dfn[p.fi]+siz[p.fi]-1)-query(dfn[p.fi]-1);
		reverse(S.begin(),S.end());
		int pre=len;
		for(auto p:S){
			int x=p.fi,pos=p.se;
			if(pos-dep[x]+1<pre)F[x]--,pre=pos-dep[x]+1;
		}
		for(auto p:S)if(F[p.fi]==0)res++,F[p.fi]=1;
		k=0;
		for(int j=0;j<len;j++){
			int c=st[i][j]-'a';
			k=t[k][c];
			update(dfn[k],-1);
		}
	}
	printf("%d\n",res);
    return 0;
}