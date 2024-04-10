// Hydro submission #62beeb9e12be0219046999cb@1656679327341
#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,cnt,fa[N];
double prb[N][63],ans[N];
inline int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9')
		x=(x<<3)+(x<<1)+(c^48), c=getchar();
	return x;
}
inline void Insert(int f){
	int u=++cnt; fa[u]=f;
	for(register int i=0;i<60;++i)
		prb[u][i]=1;
	double l=prb[f][0],ll;
	prb[f][0]*=0.5, ans[f]+=prb[f][0];
	for(register int i=1,x=f,y=fa[x];i<60&&y;++i){
		ll=prb[y][i], ans[y]+=ll;
		prb[y][i]*=(prb[x][i-1]+1)/(l+1);
		ans[y]-=prb[y][i], x=y, y=fa[y], l=ll;
	}
}
int main(){
	n=read(), Insert(0);
	for(register int i=1,op,x;i<=n;++i){
		op=read(), x=read();
		if(op==1) Insert(x);
		else printf("%.9lf\n",ans[x]);
	}
	return 0;
}