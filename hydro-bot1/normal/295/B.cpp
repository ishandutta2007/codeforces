// Hydro submission #60d5cd0e0b778688e9ce6ee5@1624624398437
// author : Encounter_qty
// this is just a remote_judge
// just for test , sorry for trouble caused!

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;

int n,flag[N],del[N];
ll dis[N][N],ans[N];

inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)) { if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}

int main(){
	//freopen("CF295B.in","r",stdin);
	//freopen("CF295B.out","w",stdout);
	n=read();
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
			dis[i][j]=read();
	for (int i=1;i<=n;++i) del[i]=read();
	for (int T=n;T;T--){
		int x=del[T];
		flag[x]=1;
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n;++j)
				if (i^j){
					dis[i][j]=min(dis[i][j],dis[i][x]+dis[x][j]);
					if (flag[i] && flag[j]) ans[T]+=dis[i][j];
				}
	}
	for (int i=1;i<=n-1;++i) printf("%lld ",ans[i]);
	printf("%lld\n",ans[n]);
	return 0;
}