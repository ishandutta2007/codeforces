#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;

int i,j,k,n,m,fa[200500],a[200500],x,y,fb[100]={0,1},tmp,tmp2,tn,hd,z;
int f[400500],b[200500][2],tr[200500];
vector<int> v[200500],v2[200500];

int used[200500];

#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

void dfs0(int x){
	z++;
	tr[x]=z;used[x]=1;
	for(auto i:v2[x]){
		if(!used[i]){dfs0(i);}
	}
}

void dfs(int x){
	a[x]++;
	for(auto i:v[x]){
		dfs(i);a[x]+=a[i];
	}
}

void dfs2(int x){
	if((a[x]==tmp)||(a[x]==tmp2)){tn=x;return;}
	for(auto i:v[x]){
		if(fa[i]==x){dfs2(i);}
	}
}

void del(int x){
	a[x]-=tmp;
	if(fa[x]!=x){del(fa[x]);}
}

void chk(int x){
	if(a[x]<=3){return;}
	if(!f[a[x]]){puts("NO");exit(0);}
	int i,j,k;
	tmp=fb[f[a[x]]];tmp2=fb[f[a[x]]-1];tn=0;
	dfs2(x);
	if(!tn){puts("NO");exit(0);}
	tmp=a[tn];
	del(fa[tn]);
	fa[tn]=tn;
	chk(tn);chk(x);
}

int main(){
	for(i=2;i<=28;i++){
		fb[i]=fb[i-1]+fb[i-2];
		f[fb[i]]=i-1;
	}
	n=read();
	if(n<=3){puts("YES");return 0;}
	hd=2000000;
	for(i=1;i<n;i++){
		x=read();y=read();
		v2[x].push_back(y);
		v2[y].push_back(x);
		b[i][0]=x;b[i][1]=y;
		hd=min({hd,x,y});
	}
	dfs0(hd);
	
	for(i=1;i<n;i++){
		x=tr[b[i][0]];y=tr[b[i][1]];
		if(x>y){swap(x,y);}
		v[x].push_back(y);
		fa[y]=x;
		tmp=min(tmp,x);
	}
	
	fa[1]=1;
	dfs(1);
	chk(1);
	puts("YES");
}