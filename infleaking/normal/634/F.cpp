#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3010;
int px[N],py[N];
vector<int> d[N],h[N];
int r,c,n,k;
int prv[N],nxt[N],f[N],la;
void push(int x){
	prv[x]=la;
	nxt[la]=x;
	la=x;
}
void delt(int x){
	prv[nxt[x]]=prv[x];
	nxt[prv[x]]=nxt[x];
}
ll ans;
ll calc(int x){
	return 1<=x&&x<=n?(py[x]-py[prv[x]])*(c-(py[f[x]])+1):0;
}
void del(int x,ll &sum){
	sum-=calc(x)+calc(nxt[x]);
	delt(x);
	int y=prv[x];
	for (int i=1;i<=k;i++,y=prv[y]){
		sum-=calc(y);
		f[y]=nxt[f[y]];
		sum+=calc(y);
	}
	sum+=calc(nxt[x]);
}
int main(){
	cin>>r>>c>>n>>k;k--;
	for (int i=1;i<=n;i++)
		scanf("%d%d",&px[i],&py[i]),d[py[i]].push_back(i),h[px[i]].push_back(i);
	for (int i=1;i<=r;i++){
		memset(prv,0,sizeof prv);
		memset(nxt,0,sizeof nxt);
		memset(f,0,sizeof f);
		la=0;
		for (int j=1;j<=c;j++)
			for (auto x:d[j])
				if (px[x]>=i)push(x);
		push(n+1);
		nxt[n+1]=n+1;
		py[n+1]=c+1;
		ll sum=0;
		for (int x=nxt[0];x<=n;x=nxt[x]){
			f[x]=x;
			for (int y=x,z=1;z<=k;z++,f[x]=y=nxt[y]);
			sum+=calc(x);
		}
		for (int j=r;j>=i;j--){
			ans+=sum;
			for (auto x:h[j])
				del(x,sum);
		}
	}
	cout<<ans<<endl;
}