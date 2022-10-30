#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,in[100500],a[100500],mx,sb,fa[100500],mn,cur;
int res[100500],f[100500][33];
vector<int> v1[100500];

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++){cin>>f[i][0];in[f[i][0]]++;}
	for(i=1;i<=n;i++){
		if(!in[i])sb++;
		cin>>a[i];mx=max(mx,a[i]);
	}
	t=(mx-n)/sb;
	for(i=1;i<=31;i++)for(j=1;j<=n;j++)f[j][i]=f[f[j][i-1]][i-1];
	for(i=1;i<=n;i++){
		for(j=30,cur=i,k=t;j>=0;j--){
			if((1<<j)<=k)k-=(1<<j),cur=f[cur][j];
		}
		v1[cur].push_back(i);
	}
	for(i=1;i<=n;i++){
		mn=11451419;
		for(auto j:v1[i])mn=min(mn,j);
		for(auto j:v1[i])fa[j]=mn;
		if(mn<1e7)res[mn]=a[i];
	}
	set<int> s={n+1};
	for(i=1;i<=n;i++)s.insert(i);
	for(i=1;i<=n;i++)if(res[i])s.erase(res[i]);
	for(i=1;i<=n;i++){
		if(!res[i]){
			auto k=*s.upper_bound(res[fa[i]]);
			res[i]=k;s.erase(k);
		}
		cout<<res[i]<<' ';
	}
}