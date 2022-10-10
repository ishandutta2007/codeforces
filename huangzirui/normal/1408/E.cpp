#include<bits/stdc++.h>
#define Mid ((L+R)/2)
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=200010;
int i,j,k,n,m,T,a[maxn],b[maxn];
struct edge{
	int x,y,z;
}e[maxn*2];int len;
bool tmp(edge a,edge b){
	return a.z>b.z;
}int F[maxn*2];ll ans;
int find(int x){
	return F[x]==x?x:F[x]=find(F[x]);
}
int main(){
	cin>>n>>m;
	for(i=1;i<=n;i++)a[i]=read();
	for(i=1;i<=m;i++)b[i]=read();
	for(i=1;i<=n+m;i++)F[i]=i;
	for(i=1;i<=n;i++){
		int g=read();
		for(j=1;j<=g;j++){
			int tmp=read();
			e[++len]={i,tmp+n,a[i]+b[tmp]};
			ans+=e[len].z;
		}
	}sort(e+1,e+1+len,tmp);
	for(i=1;i<=len;i++){
		int X=find(e[i].x),Y=find(e[i].y);
		if(X==Y)continue;
		F[X]=Y;ans-=e[i].z;
	}cout<<ans<<endl;
	return 0;
}