#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define fd(i,a,b)for(int i=b,E=a;i>=E;i--)
#define ll long long
using namespace std;
const int N=4.2e6+5;
int n,m,a[N],mx,mn,an,b[N*2];
void R(int &n){
	char c;int fh=1;for(;(c=getchar())<'0'||c>'9';);
	for(n=0;c<='9'&&c>='0';c=getchar())n=n*10+c-48;n*=fh;
}
void dfs(int x){
	b[x]=2;
	if(x<=mx){
		if(b[x|mn]==3)dfs(x|mn);
	}
	else{
		x^=mn;
		if(b[mx^x]==3)dfs(mx^x);
		for(int S=mx^x,j;j=S&-S,S;S^=j)
			if(b[x|j|mn]==3)dfs(x|j|mn);
	}
}
int main(){
//	freopen("a.in","r",stdin);
	R(n);R(m);mn=1<<n;mx=mn-1;
	fo(i,1,m)R(a[i]),b[a[i]]=3;
	fo(i,mn,mn|mx)b[i]=3;
	fo(i,1,m)if(b[a[i]]==3)dfs(a[i]),an++;
	printf("%d",an);
}