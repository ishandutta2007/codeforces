#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int hed[N],val[N<<1],nxt[N<<1],to[N<<1],cnt;
inline void adde(int u,int v,int w){
	++cnt;to[cnt]=v,nxt[cnt]=hed[u],val[cnt]=w;hed[u]=cnt;
}
int a[N],n;
typedef long long ll;
ll fir[N],sec[N];
ll ans = 0;
inline void dfs(int x,int pre){
	fir[x]=sec[x]=0;
	for(int i=hed[x];i;i=nxt[i]){
		int v=to[i];if(v==pre)continue;
		dfs(v,x);
		ll Val = fir[v] + a[v] - val[i];
		if(fir[x] < Val) sec[x] = fir[x], fir[x] = Val;
		else if(Val > sec[x])sec[x] = Val;
	}
	ans = max(ans, fir[x] + sec[x] +a[x]);
	//cout << x <<" "<< ans << endl;
}

int main()
{
	cin >> n; 
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		adde(u,v,w),adde(v,u,w);
	}
	dfs(1,0);
	cout << ans << endl;
}