#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
#define b(x) (1<<((x)-1))

int i,j,k,n,m,t,a[300005],p[999],d;
int inv[1005000];
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
int su(int a,int b){a+=b;return (a>=M)?a-M:a;}
int f[100005],f2[17][100005];
ll sb[17][300005],sb2[17][300005],tot,res;

#define get(l,r,x) (sb[x][r]*sb2[x][l-1]%M)

void dfs(int cur,int msk,int lst,ll res){
	if(cur>m){
		if(!lst)return;
		res=res*get(p[lst],d,lst)%M;
		f[msk]=res;
		if(__builtin_popcount(msk)&1)f[msk]=M-f[msk];
		return;
	}
	dfs(cur+1,msk,lst,res);
	if(!lst)res=get(1,p[cur],cur);
	else{
		int md=(p[lst]+p[cur])/2;
		res=res*get(p[lst],md,lst)%M*get(md+1,p[cur],cur)%M;
	}
	msk|=b(cur);f[msk]=res;dfs(cur+1,msk,cur,res);
}

int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	inv[0]=1;
	for(i=1;i<=300000;i++)inv[i]=ksm(i,M-2);
	cin>>d>>n>>m;
	tot=ksm(d+1,n+1);
	for(i=1;i<=n;i++){cin>>k;a[k]=1;}
	for(i=1;i<=m;i++)cin>>p[i];
	sort(p+1,p+m+1);
	for(t=1;t<=m;t++){
		sb[t][0]=sb2[t][0]=1;
		for(i=1;i<=d;i++){
			sb[t][i]=sb[t][i-1];
			sb2[t][i]=sb2[t][i-1];
			if(a[i]){
				sb[t][i]=sb[t][i]*abs(i-p[t])%M;
				sb2[t][i]=sb2[t][i]*inv[abs(i-p[t])]%M;
			}
		}
	}
	dfs(1,0,0,1);
	for(t=1;t<=m;t++){
		for(i=1;i<b(m+1);i++)if(i&b(t))f2[t][i]=f[i];
		for(i=1;i<=m;i++)for(j=1;j<b(m+1);j++)if(j&b(i))f2[t][j]=su(f2[t][j],f2[t][j^b(i)]);
	}
	cin>>t;
	while(t--){
		cin>>k;
		vector<pair<ll,ll> >v;
		for(i=1;i<=m;i++)v.push_back({abs(p[i]-k),i});
		sort(v.begin(),v.end());
		res=tot;
		j=b(m+1)-1;
		for(auto [dis,id]:v){
			res=su(res,dis*f2[id][j]%M)%M;j^=b(id);
		}
		cout<<res<<'\n';
	}
}