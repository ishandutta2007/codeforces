#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
#define b(x) (1<<((x)-1))

int i,j,k,n,m,t,l[300500],r[300500],x[666],y[666],num[300500],f[300500][42],a[300500],cur,lst;
bool vis[300500];
ll jc[305000],inv[305000],g[66];
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll c(int n,int m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;}
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}

vector<int> v[22];

ll get(int z){
	memset(f,0,sizeof(f));
	memset(a,0,sizeof(a));
	ll res=0;
	int i,j,k=0,l1,r1;
	for(auto i:v[z]){
		k=0;
		l1=1,r1=n;
		for(j=1;j<=m;j++){
			if(b(j)&i){
				if(!vis[x[j]]){
					l1=max(l1,l[x[j]]);
					r1=min(r1,r[x[j]]);
					k++;
				}
				if(!vis[y[j]]){
					l1=max(l1,l[y[j]]);
					r1=min(r1,r[y[j]]);
					k++;
				}
				vis[x[j]]=vis[y[j]]=1;
			}
		}
		for(j=1;j<=m;j++)vis[x[j]]=vis[y[j]]=0;
		if(l1>r1)continue;
		f[l1][k]++;f[r1+1][k]--;
	}
	for(i=1;i<=n;i++){
		for(j=0;j<=40;j++){
			f[i][j]+=f[i-1][j];
			res=su(res,c(num[i]-j,i-j)*f[i][j]%M);
		}
	}
	return res;
}


int main() {
	jc[0]=inv[0]=1;
	for(i=1;i<=300000;i++){jc[i]=jc[i-1]*i%M;}
	inv[300000]=ksm(jc[300000],M-2);
	for(i=299999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	cin.tie(0);
	cin>>n>>m;
	for(i=0;i<b(m+1);i++){
		v[__builtin_popcount(i)].push_back(i);
	}
	for(i=1;i<=n;i++){
		cin>>l[i]>>r[i];
		num[l[i]]++;num[r[i]+1]--;
	}
	for(i=1;i<=m;i++)cin>>x[i]>>y[i];
	for(i=1;i<=n;i++)num[i]+=num[i-1];
	for(i=m;i>=0;i--){
		g[i]=su(g[i],get(i));
		for(j=i-1;j>=0;j--){
			g[j]=su(g[j],M-c(i,j)*g[i]%M);
		}
	}
	cout<<g[0];
}